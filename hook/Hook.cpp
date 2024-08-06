# include <DxLib.h>

# ifdef EMSCRIPTEN
#  include <emscripten.h>
# endif

# undef ProcessMessage
# undef WaitKey

namespace DxLib {
    int ProcessMessage();

    void CaptureAndSaveScreen();

    int HookedWaitKey() {
        CaptureAndSaveScreen();
        return 0;
    }

    int HookedProcessMessage() {
        static int calledNum = 0;

        calledNum++;

        if (calledNum == 1) {
            return ProcessMessage();
        } else {
            CaptureAndSaveScreen();
            return -1;
        }
    }

    # if !defined(SAVED_SCREENSHOT_PATH)
    #   define SAVED_SCREENSHOT_PATH "./screen.bmp"
    # endif

    void CaptureAndSaveScreen() {
        int screen = GetDrawScreen();
        int screenWidth, screenHeight;
    
        GetGraphSize(screen, &screenWidth, &screenHeight);
# ifdef EMSCRIPTEN
        MAIN_THREAD_EM_ASM({
            FS.mkdir("screen");
        });
# endif
        SaveDrawScreen(0, 0, screenWidth, screenHeight, SAVED_SCREENSHOT_PATH);

# ifdef EMSCRIPTEN
        MAIN_THREAD_EM_ASM({
            emrun_file_dump(UTF8ToString($0), FS.readFile(UTF8ToString($0)));
        }, SAVED_SCREENSHOT_PATH);
# endif
    }
}

# ifdef _WIN32

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    int main();
    return main();
}

# endif

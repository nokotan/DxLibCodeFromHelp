# include <DxLib.h>

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
        SaveDrawScreen(0, 0, screenWidth, screenHeight, SAVED_SCREENSHOT_PATH);
    }
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    int main();
    return main();
}

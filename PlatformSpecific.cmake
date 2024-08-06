function(AddMSVCSpecificOptions TargetName)
    target_include_directories(${FileName} PRIVATE ${DxLibInstallDir})
    target_link_directories(${FileName} PRIVATE ${DxLibInstallDir})

    target_compile_options(${TargetName} PRIVATE "/FI${CMAKE_CURRENT_SOURCE_DIR}/hook/Hook.hpp")
    target_link_options(${TargetName} PRIVATE "/SUBSYSTEM:Windows")

    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(${TargetName} PUBLIC "/MTd")
    else()
        target_compile_options(${TargetName} PUBLIC "/MT")
    endif()
endfunction()

function(AddEmscriptenSpecificOptions TargetName)
    target_include_directories(${TargetName} PRIVATE ${DxLibHTML5InstallDir}/include)
    target_link_directories(${TargetName} PRIVATE ${DxLibHTML5InstallDir}/lib)

    target_compile_options(${TargetName} PRIVATE 
        -include${CMAKE_CURRENT_SOURCE_DIR}/hook/Hook.hpp
        -pthread
        -fwasm-exceptions
        -std=c++17
    )

    target_link_options(${TargetName} PRIVATE
        -pthread
        -fwasm-exceptions

        "-sUSE_BULLET=1"
        "-sUSE_FREETYPE=1"
        "-sUSE_OGG=1"
        "-sUSE_LIBPNG=1"
        "-sUSE_LIBJPEG=1" 
        "-sUSE_VORBIS=1"
        "-sUSE_ZLIB=1"

        "--emrun"
        "-sFULL_ES2=1"
        "-sALLOW_MEMORY_GROWTH=1"
        "-sPROXY_TO_PTHREAD=1"
        "-sOFFSCREEN_FRAMEBUFFER=1"
        "-sEXIT_RUNTIME=1"
        "-sSTACK_SIZE=1MB"
        "--preload-file=${CMAKE_CURRENT_SOURCE_DIR}/Assets@/"
    )

    set_target_properties(${TargetName} PROPERTIES
        SUFFIX ".html"
    )
endfunction()


function(AddPlatformSpecificOptions TargetName)
    if (MSVC)
        AddMSVCSpecificOptions(${TargetName})
    elseif(EMSCRIPTEN)
        AddEmscriptenSpecificOptions(${TargetName})
    endif()
endfunction()

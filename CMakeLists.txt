cmake_minimum_required(VERSION 3.22)

project(DxLibCodeFromHelp)

# Config
set(DxLibInstallDir "./DxLib" CACHE STRING "DXライブラリのインストールパス")
set(DxLibHTML5InstallDir "./DxLibForHTML5" CACHE STRING "DXライブラリ HTML5版のインストールパス")

include(./PlatformSpecific.cmake)

if(MSVC)
    file(GLOB SourceFiles ${CMAKE_CURRENT_SOURCE_DIR}/out/sjis/*.cpp)
else()
    file(GLOB SourceFiles ${CMAKE_CURRENT_SOURCE_DIR}/out/utf8/*.cpp)
endif()

# executable generation
foreach(Source IN LISTS SourceFiles)
    get_filename_component(FileName ${Source} NAME)

    add_executable(${FileName})

    target_sources(${FileName} PRIVATE ${Source} ${CMAKE_CURRENT_SOURCE_DIR}/hook/Hook.cpp)
    target_compile_definitions(${FileName} PRIVATE SAVED_SCREENSHOT_PATH=\"screen/${FileName}.bmp\")
    target_link_libraries(${FileName} PRIVATE DxLib DxDrawFunc DxUseCLib)

    AddPlatformSpecificOptions(${FileName})
endforeach()

enable_testing()

foreach(Source IN LISTS SourceFiles)
    get_filename_component(FileName ${Source} NAME)

    if(MSVC)
        add_test(NAME "run_test_${FileName}" COMMAND ${FileName} WORKING_DIRECTORY ${DxLibCodeFromHelp_BINARY_DIR})
    elseif(EMSCRIPTEN)
        add_test(NAME "run_test_${FileName}" 
            COMMAND emrun.bat --kill-exit ${FileName}.html
            WORKING_DIRECTORY ${DxLibCodeFromHelp_BINARY_DIR}
        )
    endif()
endforeach()

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

# Custom Shaders
list(FILTER SourceFiles EXCLUDE REGEX "3d_shader")
# TextInput
list(FILTER SourceFiles EXCLUDE REGEX "input")
list(FILTER SourceFiles EXCLUDE REGEX "live2D")
# PlayMovie
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_graph3\\.10")
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_graph3\\.11")
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_graph3\\.12")
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_graph3\\.13")
# WindowMode
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_other\\.7")
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_other\\.8")
# Socket
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_other\\.9")
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_other\\.10")
# SoftImage
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_other\\.15")
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_other\\.16")
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_other\\.17")
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_other\\.18")
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_other\\.19")
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_other\\.20")
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_other\\.21")
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_other\\.22")
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_other\\.23")
list(FILTER SourceFiles EXCLUDE REGEX "dxfunc_other\\.24")

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
            COMMAND emrun.bat --browser chrome --kill-exit ${FileName}.html
            WORKING_DIRECTORY ${DxLibCodeFromHelp_BINARY_DIR}
        )
    endif()
endforeach()

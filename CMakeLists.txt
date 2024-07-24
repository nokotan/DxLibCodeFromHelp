cmake_minimum_required(VERSION 3.22)

project(DxLibCodeFromHelp)

set(DxLibInstallDir "./DxLib" CACHE STRING "DXライブラリのインストールパス")

file(GLOB SourceFiles ${CMAKE_CURRENT_SOURCE_DIR}/out/*.cpp)

foreach(Source IN LISTS SourceFiles)
    get_filename_component(FileName ${Source} NAME)

    add_executable(${FileName})

    target_sources(${FileName} PRIVATE ${Source} ${CMAKE_CURRENT_SOURCE_DIR}/hook/Hook.cpp)
    target_compile_definitions(${FileName} PRIVATE SAVED_SCREENSHOT_PATH=\"screen/${FileName}.bmp\")
    target_include_directories(${FileName} PRIVATE ${DxLibInstallDir})
    target_link_directories(${FileName} PRIVATE ${DxLibInstallDir})
    target_link_libraries(${FileName} PRIVATE DxLib DxDrawFunc DxUseCLib)

    target_compile_options(${FileName} PRIVATE "/FI${CMAKE_CURRENT_SOURCE_DIR}/hook/Hook.hpp")
    target_link_options(${FileName} PRIVATE "/SUBSYSTEM:Windows")

    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(${FileName} PUBLIC "/MTd")
    else()
        target_compile_options(${FileName} PUBLIC "/MT")
    endif()

endforeach()

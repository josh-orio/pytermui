cmake_minimum_required(VERSION 3.28.0)
project(pytermui LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
    termui
    GIT_REPOSITORY https://github.com/josh-orio/termui.git
    GIT_TAG        main 
)
FetchContent_MakeAvailable(termui)

add_subdirectory(bindings)

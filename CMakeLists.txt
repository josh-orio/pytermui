cmake_minimum_required(VERSION 3.28.0)
project(pytermui LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(FetchContent)
FetchContent_Declare(
    termui
    GIT_REPOSITORY https://github.com/josh-orio/termui.git
    GIT_TAG        main 
)
FetchContent_MakeAvailable(termui)

include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG        master 
)
FetchContent_MakeAvailable(pybind11)

file(GLOB SOURCES "bindings/*.cpp")

pybind11_add_module(pytermui ${SOURCES})
target_link_libraries(pytermui PRIVATE termui)
set_target_properties(pytermui PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/pytermui
)

install(TARGETS pytermui
    LIBRARY DESTINATION pytermui
)
install(DIRECTORY pytermui/ DESTINATION pytermui)

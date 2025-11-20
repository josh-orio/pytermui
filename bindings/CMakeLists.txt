include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG        master 
)
FetchContent_MakeAvailable(pybind11)

file(GLOB SOURCES "*.cpp")

add_library(pytermui MODULE ${SOURCES})

target_link_libraries(pytermui
    PRIVATE
        pybind11::module
        termui      
)

pybind11_extension(pytermui)

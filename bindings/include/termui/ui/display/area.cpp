#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/display/area.hpp>

namespace py = pybind11;

void bind_area(py::module_ &m) {
  m.doc() = "Python bindings for termui::Area";

  py::class_<termui::Area>(m, "Area")
      // Constructors
      .def(py::init<uint, uint, const termui::Style &, std::string>(), py::arg("width"), py::arg("height"), py::arg("style"), py::arg("symbol") = "╳")

      // Methods
      .def("render", &termui::Area::render, "Render the area and return the ANSI escape sequence string");
  // .def("width", &termui::Area::width, "Get the area width")
  // .def("height", &termui::Area::height, "Get the area height");
}

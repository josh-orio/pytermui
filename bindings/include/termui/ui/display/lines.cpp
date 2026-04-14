#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/display/lines.hpp>

namespace py = pybind11;

void bind_lines(py::module_ &m) {
  m.doc() = "Python bindings for termui::HorizontalLine and termui::VerticalLine";

  py::class_<termui::HorizontalLine>(m, "HorizontalLine")
      // Constructors
      .def(py::init<uint, const termui::Border &>(), py::arg("width"), py::arg("border"))

      // Methods
      .def("render", &termui::HorizontalLine::render, "Render the horizontal line and return the ANSI escape sequence string")
      .def("width", &termui::HorizontalLine::width, "Get the horizontal line width");

  py::class_<termui::VerticalLine>(m, "VerticalLine")
      // Constructors
      .def(py::init<uint, const termui::Border &>(), py::arg("height"), py::arg("border"))

      // Methods
      .def("render", &termui::VerticalLine::render, "Render the vertical line and return the ANSI escape sequence string")
      .def("height", &termui::VerticalLine::height, "Get the vertical line height");
}

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/display/box.hpp>

namespace py = pybind11;

void bind_box(py::module_ &m) {
  m.doc() = "Python bindings for termui::Box";

  py::class_<termui::Box>(m, "Box")
      // Constructors
      .def(py::init<uint, uint, const termui::Border &, const termui::Style &>(), py::arg("width"), py::arg("height"), py::arg("border"),
           py::arg("style") = termui::Styles::none)

      // Methods
      .def("render", &termui::Box::render, "Render the box and return the ANSI escape sequence string")
      .def("resize", &termui::Box::resize, py::arg("w"), py::arg("h"), "Resize the box")
      .def("width", &termui::Box::width, "Get the box width")
      .def("height", &termui::Box::height, "Get the box height");
}

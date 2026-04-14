#include <pybind11/pybind11.h>

#include <termui/core/rendering.hpp>

namespace py = pybind11;

void bind_rendering(py::module_ &m) {
  m.doc() = "termui Python bindings";

  py::class_<termui::Renderer>(m, "Renderer")
      .def(py::init<termui::ColorMode>(), py::arg("color_capability"))
      .def("render", &termui::Renderer::render, py::arg("str"), py::arg("style"));
}

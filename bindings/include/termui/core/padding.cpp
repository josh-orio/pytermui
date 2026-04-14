#include <pybind11/pybind11.h>

#include <termui/core/padding.hpp>

namespace py = pybind11;

void bind_padding(py::module_ &m) {
  m.doc() = "termui Python bindings";

  // --- Padding struct
  py::class_<termui::Padding>(m, "Padding")
      .def(py::init<>())
      .def(py::init<unsigned int, unsigned int, unsigned int, unsigned int>(), py::arg("left"), py::arg("right"), py::arg("top"), py::arg("bottom"))
      .def_readwrite("left", &termui::Padding::left)
      .def_readwrite("right", &termui::Padding::right)
      .def_readwrite("top", &termui::Padding::top)
      .def_readwrite("bottom", &termui::Padding::bottom);

  py::module_ padding_style = m.def_submodule("PaddingStyle", "Predefined padding styles");

  padding_style.attr("none")  = termui::PaddingStyle::none;
  padding_style.attr("label") = termui::PaddingStyle::label;
  padding_style.attr("one")   = termui::PaddingStyle::one;
}

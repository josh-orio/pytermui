#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/base/padded-text.hpp>

namespace py = pybind11;

void bind_padded_text(py::module_ &m) {
  m.doc() = "Python bindings for termui::PaddedText";

  py::class_<termui::PaddedText>(m, "PaddedText")
      // Constructors
      .def(py::init<const termui::string &, const termui::Style &, const termui::Padding &>(), py::arg("str"), py::arg("style") = termui::Style{},
           py::arg("pad_style") = termui::Padding{})

      // Methods inherited from Text
      .def("style", &termui::PaddedText::style, py::arg("s"), py::return_value_policy::reference, "Set the padded text style")
      .def("align", &termui::PaddedText::align, py::arg("a"), py::return_value_policy::reference, "Set the padded text alignment")
      .def("width", &termui::PaddedText::width, py::arg("w"), py::return_value_policy::reference, "Set the padded text width")
      .def("height", &termui::PaddedText::height, py::arg("h"), py::return_value_policy::reference, "Set the padded text height")
      .def("size", &termui::PaddedText::size, py::arg("w"), py::arg("h"), py::return_value_policy::reference, "Set width and height in one call")
      .def("render", &termui::PaddedText::render, "Render the padded text and return the ANSI escape sequence string")

      // PaddedText-specific methods
      .def("h_padding", &termui::PaddedText::hPadding, "Get the horizontal padding")
      .def("v_padding", &termui::PaddedText::vPadding, "Get the vertical padding");
}

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/base/text.hpp>

namespace py = pybind11;

void bind_text(py::module_ &m) {
  m.doc() = "Python bindings for termui::Text";

  py::class_<termui::Text>(m, "Text")
      // Constructors
      .def(py::init<const termui::string &, const termui::Style &, uint, uint>(), py::arg("str"), py::arg("style") = termui::Style{}, py::arg("width") = 0,
           py::arg("height") = 0)

      // Methods
      .def("style", &termui::Text::style, py::arg("s"), py::return_value_policy::reference, "Set the text style")
      .def("align", &termui::Text::align, py::arg("a"), py::return_value_policy::reference, "Set the text alignment")
      .def("width", &termui::Text::width, py::arg("w"), py::return_value_policy::reference, "Set the text width")
      .def("height", &termui::Text::height, py::arg("h"), py::return_value_policy::reference, "Set the text height")
      .def("size", &termui::Text::size, py::arg("w"), py::arg("h"), py::return_value_policy::reference, "Set width and height in one call")
      .def("render", &termui::Text::render, "Render the text and return the ANSI escape sequence string");
}

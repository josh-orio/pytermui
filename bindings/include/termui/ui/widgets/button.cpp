#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/widgets/button.hpp>

namespace py = pybind11;

void bind_button(py::module_ &m) {
  m.doc() = "Python bindings for termui::Button";

  py::class_<termui::Button>(m, "Button")
      // Constructors
      .def(py::init<const termui::string &, termui::Style, termui::Style>(), py::arg("text"), py::arg("focus_style") = termui::Style{},
           py::arg("blur_style") = termui::Style{})

      // Methods
      .def("focus_style", &termui::Button::focus_style, py::return_value_policy::reference, "Set the focus style")
      .def("blur_style", &termui::Button::blur_style, py::return_value_policy::reference, "Set the blur style")
      .def("width", &termui::Button::width, py::return_value_policy::reference, "Set the button width")
      .def("focus", &termui::Button::focus, "Focus the button")
      .def("blur", &termui::Button::blur, "Blur the button")
      .def("render", &termui::Button::render, py::return_value_policy::copy, "Render the button as a string");
}

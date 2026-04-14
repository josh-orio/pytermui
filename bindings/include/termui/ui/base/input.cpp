#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/base/input.hpp>

namespace py = pybind11;

void bind_input(py::module_ &m) {
  m.doc() = "Python bindings for termui::Input";

  py::class_<termui::Input>(m, "Input")
      // Constructors
      .def(py::init<>(), "Default constructor")

      .def(py::init<const termui::string &, const termui::string &, const termui::Style &, const termui::Style &>(), py::arg("value") = termui::string(""),
           py::arg("placeholder") = termui::string(""), py::arg("val_style") = termui::Style{}, py::arg("plh_style") = termui::Styles::faint,
           "Construct an Input with optional value, placeholder, and styles")

      // Setters — each returns *this so we replicate the fluent interface by returning a reference to the same Input object
      .def("value", &termui::Input::value, py::arg("v"), py::return_value_policy::reference_internal, "Set the input value")
      .def("placeholder", &termui::Input::placeholder, py::arg("p"), py::return_value_policy::reference_internal, "Set the placeholder text")
      .def("value_style", &termui::Input::valueStyle, py::arg("s"), py::return_value_policy::reference_internal, "Set the style applied to the value")
      .def("placeholder_style", &termui::Input::placeholderStyle, py::arg("s"), py::return_value_policy::reference_internal,
           "Set the style applied to the placeholder")
      .def("width", &termui::Input::width, py::arg("w"), py::return_value_policy::reference_internal, "Set the widget width")
      .def("height", &termui::Input::height, py::arg("h"), py::return_value_policy::reference_internal, "Set the widget height")
      .def("size", &termui::Input::size, py::arg("w"), py::arg("h"), py::return_value_policy::reference_internal, "Set both width and height at once")
      .def("get_value", &termui::Input::get_value, "Get the current input value")

      // Render
      .def("render", &termui::Input::render, "Render the widget and return the ANSI string");
}
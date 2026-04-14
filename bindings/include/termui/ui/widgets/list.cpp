#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/widgets/list.hpp>

namespace py = pybind11;

void bind_list(py::module_ &m) {
  m.doc() = "Python bindings for termui::List";

  // Bind the List class
  py::class_<termui::List>(m, "List")
      // Constructors
      .def(py::init<const termui::strings &, termui::Style, termui::Style>(), py::arg("elements"), py::arg("focus_style") = termui::Style{},
           py::arg("blur_style") = termui::Style{})

      // Methods
      .def("focus_style", &termui::List::focus_style, py::return_value_policy::reference, "Set the focus style")
      .def("blur_style", &termui::List::blur_style, py::return_value_policy::reference, "Set the blur style")
      .def("width", &termui::List::width, py::return_value_policy::reference, "Set the width")
      .def("height", &termui::List::height, py::return_value_policy::reference, "Set the height")
      .def("line_seperation", &termui::List::line_seperation, py::return_value_policy::reference, "Set the line separation")
      .def("cursor_up", &termui::List::cursor_up, py::arg("count") = 1, py::return_value_policy::reference, "Move cursor up")
      .def("cursor_down", &termui::List::cursor_down, py::arg("count") = 1, py::return_value_policy::reference, "Move cursor down")
      .def("get_cursor", &termui::List::get_cursor, py::return_value_policy::copy, "Get the cursor position")
      .def("render", &termui::List::render, py::return_value_policy::copy, "Render the list as a string");
}

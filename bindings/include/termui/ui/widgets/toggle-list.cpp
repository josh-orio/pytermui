#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/widgets/toggle-list.hpp>

namespace py = pybind11;

void bind_toggle_list(py::module_ &m) {
  m.doc() = "Python bindings for termui::ToggleList";

  // Bind the ToggleList class
  py::class_<termui::ToggleList>(m, "ToggleList")
      // Constructors
      .def(py::init<const termui::strings &, termui::Style, termui::Style>(), py::arg("elements"), py::arg("focus_style") = termui::Style{},
           py::arg("blur_style") = termui::Style{})

      // Methods
      .def("focus_style", &termui::ToggleList::focus_style, py::return_value_policy::reference, "Set the focus style")
      .def("blur_style", &termui::ToggleList::blur_style, py::return_value_policy::reference, "Set the blur style")
      .def("width", &termui::ToggleList::width, py::return_value_policy::reference, "Set the width")
      .def("height", &termui::ToggleList::height, py::return_value_policy::reference, "Set the height")
      .def("line_seperation", &termui::ToggleList::line_seperation, py::return_value_policy::reference, "Set the line separation")
      .def("cursor_up", &termui::ToggleList::cursor_up, py::arg("count") = 1, py::return_value_policy::reference, "Move cursor up")
      .def("cursor_down", &termui::ToggleList::cursor_down, py::arg("count") = 1, py::return_value_policy::reference, "Move cursor down")
      .def("get_cursor", &termui::ToggleList::get_cursor, py::return_value_policy::copy, "Get the cursor position")
      .def("toggle", &termui::ToggleList::toggle, py::return_value_policy::copy, "Toggle selection on current element")
      .def("getSelection", &termui::ToggleList::getSelection, py::arg("i"), py::return_value_policy::copy, "Get selection status for element at index");
}

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/widgets/fancy-list.hpp>

namespace py = pybind11;

void bind_fancy_list(py::module_ &m) {
  m.doc() = "Python bindings for termui::FancyList";

  // Bind the Element struct
  py::class_<termui::FancyList::Element>(m, "Element")
      .def(py::init<const termui::string &, const termui::string &>(), py::arg("title"), py::arg("description"))
      .def_readwrite("title", &termui::FancyList::Element::title)
      .def_readwrite("description", &termui::FancyList::Element::description);

  // Bind the FancyList class
  py::class_<termui::FancyList>(m, "FancyList")
      // Constructors
      .def(py::init<const std::vector<termui::FancyList::Element> &, termui::Style, termui::Style>(), py::arg("rows"), py::arg("focus_style") = termui::Style{},
           py::arg("blur_style") = termui::Style{})

      // Methods
      .def("focus_style", &termui::FancyList::focus_style, py::return_value_policy::reference, "Set the focus style")
      .def("blur_style", &termui::FancyList::blur_style, py::return_value_policy::reference, "Set the blur style")
      .def("width", &termui::FancyList::width, py::return_value_policy::reference, "Set the width")
      .def("height", &termui::FancyList::height, py::return_value_policy::reference, "Set the height")
      .def("line_seperation", &termui::FancyList::line_seperation, py::return_value_policy::reference, "Set the line separation")
      .def("cursor_up", &termui::FancyList::cursor_up, py::arg("count") = 1, py::return_value_policy::reference, "Move cursor up")
      .def("cursor_down", &termui::FancyList::cursor_down, py::arg("count") = 1, py::return_value_policy::reference, "Move cursor down")
      .def("get_cursor", &termui::FancyList::get_cursor, py::return_value_policy::copy, "Get the cursor position")
      .def("render", &termui::FancyList::render, py::return_value_policy::copy, "Render the list as a string");
}

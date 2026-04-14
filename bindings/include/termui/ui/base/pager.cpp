#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/base/pager.hpp>

namespace py = pybind11;

void bind_pager(py::module_ &m) {
  m.doc() = "Python bindings for termui::Pager";

  py::class_<termui::Pager>(m, "Pager")
      // Constructors
      .def(py::init<const termui::string &, const termui::Style &, uint, uint>(), py::arg("str"), py::arg("style") = termui::Style{}, py::arg("width") = 0,
           py::arg("height") = 0)

      // Methods inherited from Text
      .def("style", &termui::Pager::style, py::arg("s"), py::return_value_policy::reference, "Set the pager style")
      .def("align", &termui::Pager::align, py::arg("a"), py::return_value_policy::reference, "Set the pager alignment")
      .def("width", &termui::Pager::width, py::arg("w"), py::return_value_policy::reference, "Set the pager width")
      .def("height", &termui::Pager::height, py::arg("h"), py::return_value_policy::reference, "Set the pager height")
      .def("size", &termui::Pager::size, py::arg("w"), py::arg("h"), py::return_value_policy::reference, "Set width and height in one call")
      .def("render", &termui::Pager::render, "Render the pager and return the ANSI escape sequence string")

      // Pager-specific methods
      .def("cursor_up", &termui::Pager::cursor_up, py::arg("count") = 1, py::return_value_policy::reference, "Move cursor up by the specified count")
      .def("cursor_down", &termui::Pager::cursor_down, py::arg("count") = 1, py::return_value_policy::reference, "Move cursor down by the specified count")
      .def("get_cursor", &termui::Pager::get_cursor, "Get the current cursor position");
}

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/interfaces/menu.hpp>

namespace py = pybind11;

void bind_menu(py::module_ &m) {
  m.doc() = "Python bindings for termui::Menu";

  py::class_<termui::Menu>(m, "Menu")
      // Constructors
      .def(py::init<const termui::string &, const termui::strings &, uint>(), py::arg("title"), py::arg("elements"), py::arg("line_seperation") = 1)

      // Methods
      .def("show", &termui::Menu::show, "Show the menu and return the selected element index (-1 for exit)")
      .def("cursor", &termui::Menu::cursor, "Get the current cursor position");
  //   .def("status", &termui::Menu::status, py::return_value_policy::copy, "Get the interface status (EXIT or SELECT)");
}

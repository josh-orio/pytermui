#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/interfaces/toggle-menu.hpp>

namespace py = pybind11;

void bind_toggle_menu(py::module_ &m) {
  m.doc() = "Python bindings for termui::ToggleMenu";

  py::class_<termui::ToggleMenu>(m, "ToggleMenu")
      // Constructors
      .def(py::init<const termui::string &, const termui::strings &, uint>(), py::arg("title"), py::arg("elements"), py::arg("line_seperation") = 1)

      // Methods
      .def("show", &termui::ToggleMenu::show, "Show the toggle menu")
      .def("cursor", &termui::ToggleMenu::cursor, "Get the current cursor position")
      .def("is_selected", &termui::ToggleMenu::isSelected, py::arg("index"), "Check if an element is selected");
  // .def("get_selection_map", &termui::ToggleMenu::selmap, "Get the map of selected element indices");
}

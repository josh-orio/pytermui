#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/interfaces/fancy-menu.hpp>

namespace py = pybind11;

void bind_fancy_menu(py::module_ &m) {
  m.doc() = "Python bindings for termui::FancyMenu";

  py::class_<termui::FancyMenu>(m, "FancyMenu")
      // Constructors
      .def(py::init<const termui::string &, const std::vector<termui::FancyList::Element> &, uint>(), py::arg("title"), py::arg("rows"),
           py::arg("line_seperation") = 1)

      // Methods
      .def("show", &termui::FancyMenu::show, "Show the fancy menu")
      .def("cursor", &termui::FancyMenu::cursor, "Get the current cursor position");
}

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/interfaces/binary-menu.hpp>

namespace py = pybind11;

void bind_binary_menu(py::module_ &m) {
  m.doc() = "Python bindings for termui::BinaryMenu";

  py::class_<termui::BinaryMenu>(m, "BinaryMenu")
      // Constructors
      .def(py::init<const termui::string &, const termui::string &, const termui::string &, const termui::string &>(), py::arg("title"), py::arg("text"),
           py::arg("affirmative"), py::arg("negative"))

      // Methods
      .def("show", &termui::BinaryMenu::show, py::return_value_policy::reference,
           "Show the binary menu and return the selection (true for affirmative, false for negative)");
}

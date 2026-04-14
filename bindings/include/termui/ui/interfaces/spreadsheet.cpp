#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/interfaces/spreadsheet.hpp>

namespace py = pybind11;

void bind_spreadsheet(py::module_ &m) {
  m.doc() = "Python bindings for termui::Spreadsheet";

  py::class_<termui::Spreadsheet>(m, "Spreadsheet")
      // Constructors
      .def(py::init<const termui::string &, const termui::strings &, const std::vector<termui::strings> &>(), py::arg("title"), py::arg("cols"),
           py::arg("data"))

      // Methods
      .def("show", &termui::Spreadsheet::show, "Show the spreadsheet");
}

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/interfaces/info-page.hpp>

namespace py = pybind11;

void bind_info_page(py::module_ &m) {
  m.doc() = "Python bindings for termui::InfoPage";

  py::class_<termui::InfoPage>(m, "InfoPage")
      .def(py::init<const termui::string &, const termui::string &>(), py::arg("title"), py::arg("content"))
      .def("show", &termui::InfoPage::show, "Show the info page");
}

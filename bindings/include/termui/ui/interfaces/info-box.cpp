#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/interfaces/info-box.hpp>

namespace py = pybind11;

void bind_info_box(py::module_ &m) {
  m.doc() = "Python bindings for termui::InfoBox";

  py::class_<termui::InfoBox>(m, "InfoBox")
      // Constructors
      .def(py::init<const termui::string &, const termui::string &>(), py::arg("title"), py::arg("content"))

      // Methods
      .def("show", &termui::InfoBox::show, "Show the info box");
}

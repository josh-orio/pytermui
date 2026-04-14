#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/interfaces/input-page.hpp>

namespace py = pybind11;

void bind_input_page(py::module_ &m) {
  m.doc() = "Python bindings for termui::InputPage";

  py::class_<termui::InputPage>(m, "InputPage")
      // Constructors
      .def(py::init<const termui::string &, const termui::strings &, const termui::strings &, uint>(), py::arg("title"), py::arg("fields"),
           py::arg("responses"), py::arg("line_seperation") = 0)

      // Methods
      .def("show", &termui::InputPage::show, "Show the input page");
}

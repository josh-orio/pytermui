#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/interfaces/input-box.hpp>

namespace py = pybind11;

void bind_input_box(py::module_ &m) {
  m.doc() = "Python bindings for termui::InputBox";

  py::class_<termui::InputBox>(m, "InputBox")
      // Constructors
      .def(py::init<const termui::string &, const termui::string &, const termui::string &>(), py::arg("field"), py::arg("response"), py::arg("placeholder"))

      // Methods
      .def("show", &termui::InputBox::show, "Show the input box");
}

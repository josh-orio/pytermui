#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/interfaces/text-editor.hpp>

namespace py = pybind11;

void bind_text_editor(py::module_ &m) {
  m.doc() = "Python bindings for termui::TextEditor";

  py::class_<termui::TextEditor>(m, "TextEditor")
      // Constructors
      .def(py::init<const termui::string &, const termui::string &>(), py::arg("title"), py::arg("content"))

      // Methods
      .def("show", &termui::TextEditor::show, "Show the text editor");
}

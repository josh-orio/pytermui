#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/display/progress-bar.hpp>

namespace py = pybind11;

void bind_progress_bar(py::module_ &m) {
  m.doc() = "Python bindings for termui::ProgressBar";

  py::class_<termui::ProgressBar>(m, "ProgressBar")
      // Constructors
      .def(py::init<uint, float, const termui::Color &, const termui::Color &>(), py::arg("width"), py::arg("decimal"), py::arg("foreground"),
           py::arg("background"))

      // Methods
      .def("render", &termui::ProgressBar::render, "Render the progress bar and return the ANSI escape sequence string");
  // .def("width", &termui::ProgressBar::width, "Get the progress bar width");
}

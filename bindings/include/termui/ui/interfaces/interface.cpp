#include <pybind11/pybind11.h>

#include <termui/ui/interfaces/interface.hpp>

namespace py = pybind11;

void bind_interface(py::module_ &m) {
  py::class_<termui::Interface>(m, "Interface")
      // no constructors exposed (protected)
      ;

  py::enum_<termui::Interface::State>(m, "InterfaceState")
      .value("EXIT", termui::Interface::State::EXIT)
      .value("CONTINUE", termui::Interface::State::CONTINUE)
      .value("SELECT", termui::Interface::State::SELECT)
      .export_values();
}
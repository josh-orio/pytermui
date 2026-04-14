#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/globals.hpp>

namespace py = pybind11;
using namespace termui;

void bind_globals(py::module_ &m) {

  py::module_ g = m.def_submodule("globals", "Module-level terminal and renderer references (mirrors termui::terminal / termui::renderer).");

  g.attr("terminal") = py::cast(const_cast<Terminal *>(&termui::terminal), py::return_value_policy::reference);
  g.attr("renderer") = py::cast(const_cast<Renderer *>(&termui::renderer), py::return_value_policy::reference);
}

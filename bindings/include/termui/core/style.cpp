#include <pybind11/operators.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/core/style.hpp>

namespace py = pybind11;

void bind_style(py::module_ &m) {
  py::enum_<termui::SGR>(m, "SGR")
      .value("None", termui::SGR::None)
      .value("Bold", termui::SGR::Bold)
      .value("Faint", termui::SGR::Faint)
      .value("Italic", termui::SGR::Italic)
      .value("Underlined", termui::SGR::Underlined)
      .value("Blink", termui::SGR::Blink)
      .value("FastBlink", termui::SGR::FastBlink)
      .value("ReverseVideo", termui::SGR::ReverseVideo)
      .value("Conceal", termui::SGR::Conceal)
      .value("CrossedOut", termui::SGR::CrossedOut)
      .export_values();

  py::class_<termui::Style>(m, "Style")
      .def(py::init<>())
      .def(py::init<std::optional<termui::Color>, std::optional<termui::Color>>(), py::arg("fg"), py::arg("bg"))
      .def(py::init<std::optional<termui::Color>, std::optional<termui::Color>, std::vector<termui::SGR>>(), py::arg("fg"), py::arg("bg"), py::arg("sgr"))
      .def("Foreground", &termui::Style::Foreground, py::return_value_policy::reference_internal)
      .def("Background", &termui::Style::Background, py::return_value_policy::reference_internal)
      .def("Attributes", &termui::Style::Attributes, py::return_value_policy::reference_internal)
      .def(py::self == py::self)
      .def(py::self != py::self);

  py::class_<termui::StyleMap>(m, "StyleMap")
      .def(py::init<std::map<std::string, termui::Style>>(), py::arg("styles"))
      .def("at", &termui::StyleMap::at, py::arg("style"), py::return_value_policy::reference_internal);

  py::module_ styles   = m.def_submodule("Styles", "Predefined styles");
  styles.attr("none")  = termui::Styles::none;
  styles.attr("bold")  = termui::Styles::bold;
  styles.attr("faint") = termui::Styles::faint;
}

#include <pybind11/operators.h>
#include <pybind11/pybind11.h>

#include <termui/core/color.hpp>

namespace py = pybind11;

void bind_color(py::module_ &m) {
  m.doc() = "Python bindings for termui Color types";

  // --- ColorMode enum
  py::enum_<termui::ColorMode>(m, "ColorMode")
      .value("ASCII", termui::ColorMode::ASCII)
      .value("ANSI256", termui::ColorMode::ANSI256)
      .value("TRUECOLOR", termui::ColorMode::TRUECOLOR)
      .export_values();

  // --- Color class
  py::class_<termui::Color>(m, "Color")
      // Color(value)  — ANSI256
      .def(py::init<uint8_t>(), py::arg("value"), "Construct an ANSI-256 colour from a palette index (0-255).")
      // Color(r, g, b) — TRUECOLOR
      .def(py::init<uint8_t, uint8_t, uint8_t>(), py::arg("r"), py::arg("g"), py::arg("b"),
           "Construct a 24-bit truecolor from R, G, B components (0-255 each).")

      // mode is safe to expose directly (not part of the union)
      .def_readwrite("mode", &termui::Color::mode)

      // Union access — expose via properties with guards
      .def_property(
          "value",
          // getter: meaningful only for ANSI256 / ASCII
          [](const termui::Color &c) -> uint8_t { return c.value; },
          // setter
          [](termui::Color &c, uint8_t v) { c.value = v; }, "Palette index (ANSI256 / ASCII modes).")

      .def_property(
          "r", [](const termui::Color &c) -> uint8_t { return c.rgb.r; }, [](termui::Color &c, uint8_t v) { c.rgb.r = v; }, "Red channel (TRUECOLOR mode).")
      .def_property(
          "g", [](const termui::Color &c) -> uint8_t { return c.rgb.g; }, [](termui::Color &c, uint8_t v) { c.rgb.g = v; }, "Green channel (TRUECOLOR mode).")
      .def_property(
          "b", [](const termui::Color &c) -> uint8_t { return c.rgb.b; }, [](termui::Color &c, uint8_t v) { c.rgb.b = v; }, "Blue channel (TRUECOLOR mode).")

      // rgb tuple convenience property
      .def_property(
          "rgb", [](const termui::Color &c) -> py::tuple { return py::make_tuple(c.rgb.r, c.rgb.g, c.rgb.b); },
          [](termui::Color &c, py::tuple t) {
            if (t.size() != 3)
              throw py::value_error("rgb must be a 3-tuple (r, g, b)");
            c.rgb.r = t[0].cast<uint8_t>();
            c.rgb.g = t[1].cast<uint8_t>();
            c.rgb.b = t[2].cast<uint8_t>();
          },
          "RGB as a (r, g, b) tuple (TRUECOLOR mode).")

      .def(py::self == py::self);

  // --- Colors submodule
  py::module_ colors = m.def_submodule("colors", "Predefined named colours");

  colors.attr("Red")      = termui::Colors::Red;
  colors.attr("Green")    = termui::Colors::Green;
  colors.attr("Yellow")   = termui::Colors::Yellow;
  colors.attr("Blue")     = termui::Colors::Blue;
  colors.attr("Magenta")  = termui::Colors::Magenta;
  colors.attr("Cyan")     = termui::Colors::Cyan;
  colors.attr("White")    = termui::Colors::White;
  colors.attr("Black")    = termui::Colors::Black;
  colors.attr("Lavender") = termui::Colors::Lavender;
  colors.attr("Orange")   = termui::Colors::Orange;
  colors.attr("Rose")     = termui::Colors::Rose;
}

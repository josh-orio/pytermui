#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/util.hpp>

namespace py = pybind11;
using namespace termui;

void bind_util(py::module_ &m) {
  m.doc() = "Python bindings for termui utility functions and string constant namespaces.";

  // ---------------------------------------------------------------- Functions
  m.def("curs_up", &curs_up, py::arg("n"), "Return an ANSI escape string that moves the cursor up n rows.");
  m.def("curs_down", &curs_down, py::arg("n"), "Return an ANSI escape string that moves the cursor down n rows.");
  m.def("curs_right", &curs_right, py::arg("n"), "Return an ANSI escape string that moves the cursor right n columns.");
  m.def("curs_left", &curs_left, py::arg("n"), "Return an ANSI escape string that moves the cursor left n columns.");

  m.def("repeat", &repeat, py::arg("s"), py::arg("n"), "Return s concatenated n times.");

  m.def("visible_length", &visible_length, py::arg("s"),
        "Return the number of visible (printed) characters in s, ignoring ANSI escape sequences and counting UTF-8 codepoints.");

  m.def("max_visible_length", &max_visible_length, py::arg("s"), py::arg("n"), "Return the byte count that covers the first n visible characters of s.");

  m.def("reverse_max_visible_length", &reverse_max_visible_length, py::arg("s"), py::arg("n"),
        "Return the byte offset from the end of s that covers the last n visible characters.");

  m.def("color_swatch", &color_swatch, py::arg("swatches_per_line"),
        "Return a string that renders tiles of all 256 8-bit terminal colours, with swatches_per_line tiles per row.");

  m.def("test_sgr_features", &test_sgr_features,
        "Return a string that renders sample tiles for common SGR text attributes, useful for probing terminal capabilities.");

  m.def("inpmap", &inpmap, py::arg("s"), "Return a hex-byte representation of s — useful for inspecting raw input buffer contents.");

  // ---------------------------------------------------------------- key
  py::module_ k = m.def_submodule("key", "Raw escape-sequence strings for common keys, intended for comparison against input-buffer reads.");

  k.attr("ENTER")         = key::ENTER;
  k.attr("ESC")           = key::ESC;
  k.attr("DEL")           = key::DEL;
  k.attr("U_ARROW")       = key::U_ARROW;
  k.attr("D_ARROW")       = key::D_ARROW;
  k.attr("R_ARROW")       = key::R_ARROW;
  k.attr("L_ARROW")       = key::L_ARROW;
  k.attr("SHIFT_U_ARROW") = key::SHIFT_U_ARROW;
  k.attr("SHIFT_D_ARROW") = key::SHIFT_D_ARROW;
  k.attr("SHIFT_R_ARROW") = key::SHIFT_R_ARROW;
  k.attr("SHIFT_L_ARROW") = key::SHIFT_L_ARROW;

  // ---------------------------------------------------------------- unicode
  py::module_ u = m.def_submodule("unicode", "UTF-8 string constants for common UI glyphs and symbols.");

  u.attr("TICK")          = unicode::TICK;
  u.attr("DOT")           = unicode::DOT;
  u.attr("VERTICAL")      = unicode::VERTICAL;
  u.attr("VERTICAL_WIDE") = unicode::VERTICAL_WIDE;
  u.attr("ELLIPSIS")      = unicode::ELLIPSIS;
  u.attr("L_ARROW")       = unicode::L_ARROW;
  u.attr("R_ARROW")       = unicode::R_ARROW;
  u.attr("U_ARROW")       = unicode::U_ARROW;
  u.attr("D_ARROW")       = unicode::D_ARROW;
  u.attr("ENTER")         = unicode::ENTER;
  u.attr("TAB")           = unicode::TAB;
  u.attr("ESC")           = unicode::ESC;
  u.attr("FULL_SHADE")    = unicode::FULL_SHADE;
  u.attr("DARK_SHADE")    = unicode::DARK_SHADE;
  u.attr("MEDIUM_SHADE")  = unicode::MEDIUM_SHADE;
  u.attr("LIGHT_SHADE")   = unicode::LIGHT_SHADE;

  // ---------------------------------------------------------------- term
  py::module_ t = m.def_submodule("term", "Raw ANSI/VT escape-sequence strings for terminal control operations.");

  t.attr("CLEAR_CONSOLE")           = term::CLEAR_CONSOLE;
  t.attr("CLEAR_SCROLLBACK")        = term::CLEAR_SCROLLBACK;
  t.attr("CURSOR_HOME")             = term::CURSOR_HOME;
  t.attr("HIDE_CURSOR")             = term::HIDE_CURSOR;
  t.attr("SHOW_CURSOR")             = term::SHOW_CURSOR;
  t.attr("ALT_BUFFER")              = term::ALT_BUFFER;
  t.attr("PRIMARY_BUFFER")          = term::PRIMARY_BUFFER;
  t.attr("SAVE_CURSOR")             = term::SAVE_CURSOR;
  t.attr("RESTORE_CURSOR")          = term::RESTORE_CURSOR;
  t.attr("ENABLE_MOUSE_REPORTING")  = term::ENABLE_MOUSE_REPORTING;
  t.attr("DISABLE_MOUSE_REPORTING") = term::DISABLE_MOUSE_REPORTING;
}

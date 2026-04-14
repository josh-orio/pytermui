#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/system/terminal.hpp>

namespace py = pybind11;

void bind_terminal(py::module_ &m) {
  m.doc() = "Python bindings for the termui Terminal and TermSetup classes.";

  // --- Terminal
  //
  // Terminal is a singleton; we expose it as a module-level factory function
  // `terminal()` that returns a reference to the single instance.  The class
  // itself carries no public constructor in the API.
  py::class_<termui::Terminal>(m, "Terminal",
                               R"doc(
Singleton that owns the terminal connection.

Obtain the instance via:

    t = termui_terminal.terminal()

The singleton is not copy- or move-constructible; always use the factory.
)doc")
      // --- Renderer (opaque handle, returned as capsule-like object) 
      .def("get_renderer", &termui::Terminal::GetRenderer, py::return_value_policy::reference_internal, "Return a const reference to the internal Renderer.")

      // --- I/O 
      .def("write", py::overload_cast<const std::string &>(&termui::Terminal::write, py::const_), py::arg("s"),
           "Buffer a string for output (call flush() to send it).")
      .def("write", py::overload_cast<uint, uint, const std::string &>(&termui::Terminal::write, py::const_), py::arg("row"), py::arg("column"), py::arg("s"),
           "Move the cursor then buffer a string.")
      .def("flush", &termui::Terminal::flush, "Flush the output buffer to stdout.")
      .def("read", &termui::Terminal::read, "Read one line from stdin and return it as a string.")

      // --- Dimensions 
      .def("width", &termui::Terminal::width, "Current terminal width in columns.")
      .def("height", &termui::Terminal::height, "Current terminal height in rows.")

      // --- Colour capability 
     //  .def("foreground_color", &termui::Terminal::ForegroundColor, "Query the terminal's current foreground colour.")
     //  .def("background_color", &termui::Terminal::BackgroundColor, "Query the terminal's current background colour.")
     //  .def("has_dark_background", &termui::Terminal::HasDarkBackground, "Return True when the terminal background is dark.")
     //  .def("color_capability", &termui::Terminal::ColorCapability, "Return the colour depth supported by this terminal.")

      // --- Cursor positioning 
      .def("move_cursor", &termui::Terminal::MoveCursor, py::arg("row"), py::arg("column"), "Move the cursor to (row, column) — 1-based.")
     //  .def("save_cursor_position", &termui::Terminal::SaveCursorPosition, "Save the current cursor position (ANSI sequence).")
     //  .def("restore_cursor_position", &termui::Terminal::RestoreCursorPosition, "Restore a previously saved cursor position.")
      .def("cursor_up", &termui::Terminal::CursorUp, py::arg("n"), "Move cursor up n rows.")
      .def("cursor_down", &termui::Terminal::CursorDown, py::arg("n"), "Move cursor down n rows.")
      .def("cursor_forward", &termui::Terminal::CursorForward, py::arg("n"), "Move cursor forward n columns.")
      .def("cursor_back", &termui::Terminal::CursorBack, py::arg("n"), "Move cursor back n columns.")
     //  .def("cursor_next_line", &termui::Terminal::CursorNextLine, py::arg("n"), "Move cursor to the beginning of the next n-th line.")
     //  .def("cursor_prev_line", &termui::Terminal::CursorPrevLine, py::arg("n"), "Move cursor to the beginning of the previous n-th line.")

      // --- Screen management 
     //  .def("reset", &termui::Terminal::Reset, "Full terminal reset.")
     //  .def("save_screen", &termui::Terminal::SaveScreen, "Save the screen contents.")
     //  .def("restore_screen", &termui::Terminal::RestoreScreen, "Restore saved screen contents.")
     //  .def("alt_screen", &termui::Terminal::AltScreen, "Switch to the alternate screen buffer.")
     //  .def("exit_alt_screen", &termui::Terminal::ExitAltScreen, "Return from the alternate screen buffer.")
      .def("clear_screen", &termui::Terminal::ClearScreen, "Clear the visible screen area.")
      .def("clear_scrollback", &termui::Terminal::ClearScrollback, "Clear the scrollback buffer.")
     //  .def("clear_line", &termui::Terminal::ClearLine, "Clear the current line.")
     //  .def("clear_lines", &termui::Terminal::ClearLines, "Clear all lines (implementation-defined).")
     //  .def("insert_lines", &termui::Terminal::InsertLines, py::arg("n"), "Insert n blank lines at cursor.")
     //  .def("delete_lines", &termui::Terminal::DeleteLines, py::arg("n"), "Delete n lines at cursor.")

      // --- Input mode 
     //  .def("disable_input_buffering", &termui::Terminal::DisableInputBuffering, "Disable canonical (line-buffered) input mode.")
     //  .def("enable_input_buffering", &termui::Terminal::EnableInputBuffering, "Re-enable canonical input mode.")
     //  .def("disable_input_echo", &termui::Terminal::DisableInputEcho, "Stop the terminal from echoing typed characters.")
     //  .def("enable_input_echo", &termui::Terminal::EnableInputEcho, "Re-enable echo of typed characters.")

      // --- Session / appearance 
     //  .def("set_window_title", &termui::Terminal::SetWindowTitle, py::arg("title"), "Set the terminal window title via OSC escape.")
     //  .def("set_foreground_color", &termui::Terminal::SetForegroundColor, py::arg("color"), "Change the terminal foreground colour.")
     //  .def("set_background_color", &termui::Terminal::SetBackgroundColor, py::arg("color"), "Change the terminal background colour.")
     //  .def("set_cursor_color", &termui::Terminal::SetCursorColor, py::arg("color"), "Change the cursor colour.")
      .def("show_cursor", &termui::Terminal::ShowCursor, "Make the cursor visible.")
      .def("hide_cursor", &termui::Terminal::HideCursor, "Hide the cursor.")

      // --- Mouse 
     //  .def("enable_mouse_press", &termui::Terminal::EnableMousePress, "Enable X10 button-press reporting.")
     //  .def("disable_mouse_press", &termui::Terminal::DisableMousePress, "Disable X10 button-press reporting.")
     //  .def("enable_mouse_tracking", &termui::Terminal::EnableMouseTracking, "Enable full mouse-motion tracking.")
     //  .def("disable_mouse_tracking", &termui::Terminal::DisableMouseTracking, "Disable mouse-motion tracking.")
     ;

  // Singleton factory exposed as a free function so Python callers write
  // `t = termui_terminal.terminal()` — idiomatic and avoids confusion with
  // the constructor.
//   m.def("terminal", &termui::Terminal::instance, py::return_value_policy::reference, "Return the global Terminal singleton.");

  // --- TermSetup
  py::class_<termui::TermSetup>(m, "TermSetup",
                                R"doc(
Helper that configures and tears down the terminal in a controlled way.

Parameters (all bool)
---------------------
input_buffering          – whether to keep canonical input buffering
input_echoing            – whether to echo typed characters
show_cursor              – whether the cursor is visible
alternate_output_buffer  – whether to use the alternate screen buffer
enable_mouse_reporting   – whether to enable mouse event reporting

Call configure() to apply the settings and reset() to restore sane defaults.
)doc")
      .def(py::init<>(), "Default constructor — leaves terminal in its current state.")
      .def(py::init<bool, bool, bool, bool, bool>(), py::arg("input_buffering"), py::arg("input_echoing"), py::arg("show_cursor"),
           py::arg("alternate_output_buffer"), py::arg("enable_mouse_reporting"))
      .def("configure", &termui::TermSetup::configure, "Apply this configuration to the terminal.")
      .def("reset", &termui::TermSetup::reset, "Restore terminal defaults (not the inverse of configure).");

  // ------------------------------------------------------------ TermSetups
  py::module_ ts                    = m.def_submodule("TermSetups", "Predefined TermSetup configurations mirroring termui::TermSetups.");
  ts.attr("fullscreen")             = termui::TermSetups::fullscreen;
  ts.attr("fullscreen_no_mouse")    = termui::TermSetups::fullscreen_no_mouse;
  ts.attr("fullscreen_with_cursor") = termui::TermSetups::fullscreen_with_cursor;
  ts.attr("windowed")               = termui::TermSetups::windowed;
}
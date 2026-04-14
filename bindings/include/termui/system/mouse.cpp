#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/system/mouse.hpp>

namespace py = pybind11;

void bind_mouse(py::module_ &m) {
  m.doc() = "Python bindings for the termui mouse event library.";

  // --- enums
  py::enum_<termui::EventType>(m, "EventType", "The kind of mouse event that occurred.")
      .value("Move", termui::EventType::Move)
      .value("ScrollUp", termui::EventType::ScrollUp)
      .value("ScrollDown", termui::EventType::ScrollDown)
      .value("ButtonPress", termui::EventType::ButtonPress)
      .value("ButtonRelease", termui::EventType::ButtonRelease)
      .export_values();

  py::enum_<termui::MouseButton>(m, "MouseButton", "Which mouse button was involved in the event.")
      .value("None", termui::MouseButton::None)
      .value("Left", termui::MouseButton::Left)
      .value("Middle", termui::MouseButton::Middle)
      .value("Right", termui::MouseButton::Right)
      .export_values();

  // --- ModifierKey
  py::class_<termui::ModifierKey>(m, "ModifierKey", "Keyboard modifier keys held during a mouse event.")
      .def(py::init<>())
      .def(py::init([](bool shift, bool control, bool option) {
             termui::ModifierKey mk;
             mk.shift   = shift;
             mk.control = control;
             mk.option  = option;
             return mk;
           }),
           py::arg("shift") = false, py::arg("control") = false, py::arg("option") = false)
      .def_readwrite("shift", &termui::ModifierKey::shift)
      .def_readwrite("control", &termui::ModifierKey::control)
      .def_readwrite("option", &termui::ModifierKey::option)
      .def("__eq__", &termui::ModifierKey::operator==)
      .def("__repr__", [](const termui::ModifierKey &mk) {
        return "<ModifierKey shift=" + std::to_string(mk.shift) + " control=" + std::to_string(mk.control) + " option=" + std::to_string(mk.option) + ">";
      });

  // --- predefined Modifiers
  py::class_<py::object>(m, "_Modifiers"); // forward-declare namespace object
  py::module_ mods     = m.def_submodule("Modifiers", "Predefined modifier-key constants mirroring termui::Modifiers.");
  mods.attr("None_")   = termui::Modifiers::None; // 'None' is a Python keyword
  mods.attr("Shift")   = termui::Modifiers::Shift;
  mods.attr("Control") = termui::Modifiers::Control;
  mods.attr("Option")  = termui::Modifiers::Option;

  // --- MouseInteraction
  py::class_<termui::MouseInteraction>(m, "MouseInteraction",
                                       R"doc(
Decoded SGR mouse escape sequence.

Construct with the raw escape string received from the terminal:

    mi = MouseInteraction("\x1b[<0;10;5M")   # left-button press at col 10, row 5

Attributes
----------
valid     : bool        – False when the input string could not be parsed.
col       : int         – Column (1-based).
row       : int         – Row (1-based).
event     : EventType
button    : MouseButton
modifiers : ModifierKey
)doc")
      .def(py::init<std::string>(), py::arg("sgr_string"), "Decode an SGR mouse escape sequence string.")
      .def_readonly("valid", &termui::MouseInteraction::valid)
      .def_readonly("col", &termui::MouseInteraction::col)
      .def_readonly("row", &termui::MouseInteraction::row)
      .def_readonly("event", &termui::MouseInteraction::event)
      .def_readonly("button", &termui::MouseInteraction::button)
      .def_readonly("modifiers", &termui::MouseInteraction::modifiers)

      // match() – event-only overload
      .def("match", py::overload_cast<termui::EventType, termui::MouseButton, termui::ModifierKey>(&termui::MouseInteraction::match), py::arg("event"),
           py::arg("button") = termui::MouseButton::None, py::arg("modifiers") = termui::Modifiers::None,
           R"doc(
Return True when this interaction matches the given event, button, and
modifiers.  Pass MouseButton.None or Modifiers.None_ to skip that check.
)doc")

      // match() – bounding-box overload
      .def("match",
           py::overload_cast<size_t, size_t, size_t, size_t, termui::EventType, termui::MouseButton, termui::ModifierKey>(&termui::MouseInteraction::match),
           py::arg("x1"), py::arg("x2"), py::arg("y1"), py::arg("y2"), py::arg("event"), py::arg("button") = termui::MouseButton::None,
           py::arg("modifiers") = termui::Modifiers::None,
           R"doc(
Return True when the interaction matches and the cursor lies within the
rectangle [x1, x2] x [y1, y2] (inclusive, 1-based col/row coordinates).
)doc")

      .def("__repr__", [](const termui::MouseInteraction &mi) {
        if (!mi.valid)
          return std::string("<MouseInteraction invalid>");
        return "<MouseInteraction col=" + std::to_string(mi.col) + " row=" + std::to_string(mi.row) + " valid=" + std::to_string(mi.valid) + ">";
      });
}

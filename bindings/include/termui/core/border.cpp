#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/core/border.hpp>

namespace py = pybind11;

void bind_border(py::module_ &m) {
  m.doc() = "Python bindings for termui border types";

  py::class_<termui::Border>(m, "Border")
      .def(py::init<>())
      .def(py::init<std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
                    std::string, std::string, std::string>(),
           py::arg("top"), py::arg("bottom"), py::arg("left"), py::arg("right"), py::arg("top_left"), py::arg("top_right"), py::arg("bottom_left"),
           py::arg("bottom_right"), py::arg("middle_left"), py::arg("middle_right"), py::arg("middle"), py::arg("middle_top"), py::arg("middle_bottom"))
      .def_readwrite("top", &termui::Border::Top)
      .def_readwrite("bottom", &termui::Border::Bottom)
      .def_readwrite("left", &termui::Border::Left)
      .def_readwrite("right", &termui::Border::Right)
      .def_readwrite("top_left", &termui::Border::TopLeft)
      .def_readwrite("top_right", &termui::Border::TopRight)
      .def_readwrite("bottom_left", &termui::Border::BottomLeft)
      .def_readwrite("bottom_right", &termui::Border::BottomRight)
      .def_readwrite("middle_left", &termui::Border::MiddleLeft)
      .def_readwrite("middle_right", &termui::Border::MiddleRight)
      .def_readwrite("middle", &termui::Border::Middle)
      .def_readwrite("middle_top", &termui::Border::MiddleTop)
      .def_readwrite("middle_bottom", &termui::Border::MiddleBottom);

  py::module_ borders = m.def_submodule("borders", "Predefined border styles");

  borders.attr("square")  = termui::Borders::square;
  borders.attr("rounded") = termui::Borders::rounded;
}

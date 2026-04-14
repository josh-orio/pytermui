#include <pybind11/cast.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/core/str.hpp>

namespace py = pybind11;

void bind_str(py::module_ &m) {
  m.doc() = "Pybind11 bindings for termui::string and termui::strings";

  // --- termui::string
  py::class_<termui::string, std::shared_ptr<termui::string>>(m, "string")
      // constructors
      .def(py::init<>())
      .def(py::init<const termui::string &>())
      .def(py::init<const std::string &>())
      .def(py::init<const char *>())

      // assignment operators
      .def(
          "__assign_str",
          [](termui::string &self, const std::string &s) -> termui::string & {
            self = s;
            return self;
          },
          py::return_value_policy::reference)

      .def(
          "__assign_cstr",
          [](termui::string &self, const char *s) -> termui::string & {
            self = s;
            return self;
          },
          py::return_value_policy::reference)

      .def(
          "__assign_obj",
          [](termui::string &self, const termui::string &other) -> termui::string & {
            self = other;
            return self;
          },
          py::return_value_policy::reference)

      // string access (mirrors implicit std::string& conversion)
      .def(
          "get", [](termui::string &self) -> std::string & { return static_cast<std::string &>(self); }, py::return_value_policy::reference_internal);

               .def(
          "text_const", [](const termui::string &s) -> const std::string & { return s.text(); },
          py::return_value_policy::reference_internal)
      .def(
          "text", [](termui::string &s) -> std::string & { return s.text(); },
          py::return_value_policy::reference_internal);

  // --- termui::strings
  py::class_<termui::strings, std::shared_ptr<termui::strings>>(m, "strings")
      .def(py::init<>())
      .def(py::init<const termui::strings &>())
      .def(py::init<const std::vector<std::string> &>())
      .def(py::init<std::initializer_list<std::string>>())
      .def(py::init<int, const std::string &>())
      .def("at", (termui::string & (termui::strings::*)(size_t)) & termui::strings::at, py::return_value_policy::reference_internal)
      // .def("at_const", (const termui::string &(termui::strings::*)(size_t) const) & termui::strings::at, py::return_value_policy::reference_internal)
      // .def("share", &termui::strings::share);
      .def("size", &termui::strings::size);

  py::implicitly_convertible<std::string, termui::string>(); // these allow python strings to implictly convert to termui::string
  py::implicitly_convertible<const char *, termui::string>();
}
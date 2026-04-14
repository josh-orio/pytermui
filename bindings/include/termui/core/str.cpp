#include <pybind11/operators.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/core/str.hpp>

namespace py = pybind11;

// why did calude add so many 'helpers'?

void bind_str(py::module_ &m) {
  m.doc() = "Python bindings for termui custom shared-ptr string types";

  // ── termui::string ──────────────────────────────────────────────────────
  py::class_<termui::string>(m, "string")
      // Constructors
      .def(py::init<>(), "Default constructor – allocates an empty shared string.")

      .def(py::init<const termui::string &>(), py::arg("t"), "Copy constructor – shares ownership of the same underlying string.")

      .def(py::init<const std::string &>(), py::arg("str"), "Construct from a Python str / std::string.")

      .def(py::init<const char *>(), py::arg("str"), "Construct from a C string literal.")

      // Assignment operators exposed as methods (Python has no operator=)
      .def("assign", py::overload_cast<const std::string &>(&termui::string::operator=), py::arg("str"), py::return_value_policy::reference_internal,
           "Assign a new value into the existing shared string object.")

      .def("assign", py::overload_cast<const char *>(&termui::string::operator=), py::arg("str"), py::return_value_policy::reference_internal,
           "Assign from a C string into the existing shared string object.")

      .def("assign", py::overload_cast<const termui::string &>(&termui::string::operator=), py::arg("t"), py::return_value_policy::reference_internal,
           "Rebind this String to share ownership with another termui::String.")

      // Implicit conversions → expose as explicit helpers in Python
      .def(
          "to_str", [](const termui::string &self) -> const std::string & { return static_cast<const std::string &>(self); },
          py::return_value_policy::reference_internal, "Return the underlying std::string by reference (read-only).")

      // __str__ / __repr__ for natural Python use
      .def("__str__", [](const termui::string &self) -> std::string { return static_cast<const std::string &>(self); })

      .def("__repr__", [](const termui::string &self) -> std::string { return "termui.String(" + static_cast<const std::string &>(self) + ")"; })

      // Rich comparison so strings can be sorted / compared in Python
      .def("__eq__",
           [](const termui::string &a, const termui::string &b) { return static_cast<const std::string &>(a) == static_cast<const std::string &>(b); })

      .def("__eq__", [](const termui::string &a, const std::string &b) { return static_cast<const std::string &>(a) == b; })

      .def("__lt__", [](const termui::string &a, const termui::string &b) { return static_cast<const std::string &>(a) < static_cast<const std::string &>(b); })

      // len() support
      .def("__len__", [](const termui::string &self) { return static_cast<const std::string &>(self).size(); });

  // ── termui::strings ─────────────────────────────────────────────────────
  py::class_<termui::strings>(m, "strings")
      // Constructors
      .def(py::init<>(), "Default constructor – allocates an empty shared vector.")

      .def(py::init<const termui::strings &>(), py::arg("strs"), "Copy constructor – shares ownership of the same underlying vector.")

      .def(py::init<const std::vector<std::string> &>(), py::arg("strs"), "Construct from a Python list of str.")

      .def(py::init([](const std::vector<std::string> &v) { return termui::strings(v); }), py::arg("strs"),
           "Construct from any iterable of str (list, tuple, …).")

      .def(py::init<int, const std::string &>(), py::arg("n"), py::arg("x"), "Construct n copies of string x.")

      // Element access
      .def("at", py::overload_cast<size_t>(&termui::strings::at), py::arg("idx"), py::return_value_policy::reference_internal,
           "Return a mutable reference to the element at idx.")

      .def("at", py::overload_cast<size_t>(&termui::strings::at, py::const_), py::arg("idx"), py::return_value_policy::reference_internal,
           "Return a const reference to the element at idx.")

      // share() – expose the underlying shared_ptr as a Python object
      // (useful for passing to C++ code that accepts shared_ptr<vector<string>>)
      // In pure Python code, iteration / len are more idiomatic.
      // .def("share", &termui::strings::share, "Return the underlying shared_ptr<vector<termui::string>>.")

      .def("size", &termui::strings::size, "Return the number of strings in the collection.")

      // Pythonic sequence protocol
      .def("__len__", &termui::strings::size)

      .def(
          "__getitem__",
          [](termui::strings &self, py::ssize_t idx) -> termui::string & {
            py::ssize_t sz = static_cast<py::ssize_t>(self.size());
            if (idx < 0)
              idx += sz;
            if (idx < 0 || idx >= sz)
              throw py::index_error("index out of range");
            return self.at(static_cast<size_t>(idx));
          },
          py::return_value_policy::reference_internal)

      .def("__setitem__",
           [](termui::strings &self, py::ssize_t idx, const std::string &val) {
             py::ssize_t sz = static_cast<py::ssize_t>(self.size());
             if (idx < 0)
               idx += sz;
             if (idx < 0 || idx >= sz)
               throw py::index_error("index out of range");
             self.at(static_cast<size_t>(idx)) = val;
           })

      .def(
          "__iter__", [](termui::strings &self) { return py::make_iterator(self.share()->begin(), self.share()->end()); }, py::keep_alive<0, 1>())

      .def("__repr__", [](const termui::strings &self) {
        // Cast away const via share() which is const
        auto        vec = self.share();
        std::string out = "termui.Strings([";
        for (size_t i = 0; i < vec->size(); ++i) {
          if (i)
            out += ", ";
          out += '"';
          out += static_cast<const std::string &>((*vec)[i]);
          out += '"';
        }
        out += "])";
        return out;
      });
}

// #include <pybind11/cast.h>
// #include <pybind11/pybind11.h>
// #include <pybind11/stl.h>

// #include <termui/core/str.hpp>

// namespace py = pybind11;

// void bind_str(py::module_ &m) {
//   m.doc() = "Pybind11 bindings for termui::string and termui::strings";

//   // --- termui::string
//   py::class_<termui::string, std::shared_ptr<termui::string>>(m, "string")
//       // constructors
//       .def(py::init<>())
//       .def(py::init<const termui::string &>())
//       .def(py::init<const std::string &>())
//       .def(py::init<const char *>())

//       // assignment operators
//       .def(
//           "__assign_str",
//           [](termui::string &self, const std::string &s) -> termui::string & {
//             self = s;
//             return self;
//           },
//           py::return_value_policy::reference)

//       .def(
//           "__assign_cstr",
//           [](termui::string &self, const char *s) -> termui::string & {
//             self = s;
//             return self;
//           },
//           py::return_value_policy::reference)

//       .def(
//           "__assign_obj",
//           [](termui::string &self, const termui::string &other) -> termui::string & {
//             self = other;
//             return self;
//           },
//           py::return_value_policy::reference)

//       // string access (mirrors implicit std::string& conversion)
//       .def(
//           "get", [](termui::string &self) -> std::string & { return static_cast<std::string &>(self); }, py::return_value_policy::reference_internal);

//   // --- termui::strings
//   py::class_<termui::strings, std::shared_ptr<termui::strings>>(m, "strings")
//       .def(py::init<>())
//       .def(py::init<const termui::strings &>())
//       .def(py::init<const std::vector<std::string> &>())
//       .def(py::init<std::initializer_list<std::string>>())
//       .def(py::init<int, const std::string &>())
//       .def("at", (termui::string & (termui::strings::*)(size_t)) & termui::strings::at, py::return_value_policy::reference_internal)
//       // .def("at_const", (const termui::string &(termui::strings::*)(size_t) const) & termui::strings::at, py::return_value_policy::reference_internal)
//       // .def("share", &termui::strings::share);
//       .def("size", &termui::strings::size);

//   py::implicitly_convertible<std::string, termui::string>(); // these allow python strings to implictly convert to termui::string
//   py::implicitly_convertible<const char *, termui::string>();
// }

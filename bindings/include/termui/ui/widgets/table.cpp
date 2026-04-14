#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <termui/ui/widgets/table.hpp>

namespace py = pybind11;

void bind_table(py::module_ &m) {
  m.doc() = "Python bindings for termui::Table";

  // Bind the Column struct
  py::class_<termui::Table::Column>(m, "Column")
      .def(py::init<const termui::string &, uint>(), py::arg("title"), py::arg("width") = 1)
      .def_readwrite("title", &termui::Table::Column::title)
      .def_readwrite("width", &termui::Table::Column::width);

  // Bind the Row struct
  py::class_<termui::Table::Row>(m, "Row").def(py::init<const termui::strings &>(), py::arg("cells")).def_readwrite("cells", &termui::Table::Row::cells);

  // Bind the TableStyle struct
  py::class_<termui::Table::TableStyle>(m, "TableStyle")
      .def(py::init<uint, uint, uint, termui::Style, termui::Border>(), py::arg("table_height") = 0, py::arg("cell_height") = 1, py::arg("line_seperation") = 0,
           py::arg("cursor_style") = termui::Style(std::nullopt, 57), py::arg("border") = termui::Borders::rounded)
      .def_readwrite("table_height", &termui::Table::TableStyle::table_height)
      .def_readwrite("cell_height", &termui::Table::TableStyle::cell_height)
      .def_readwrite("line_seperation", &termui::Table::TableStyle::line_seperation)
      .def_readwrite("cursor_style", &termui::Table::TableStyle::cursor_style)
      .def_readwrite("border", &termui::Table::TableStyle::border);

  // Bind the Table class
  py::class_<termui::Table>(m, "Table")
      // Constructors
      .def(py::init<const std::vector<termui::Table::Column> &, const std::vector<termui::Table::Row> &, const termui::Table::TableStyle &>(),
           py::arg("columns"), py::arg("rows"), py::arg("style") = termui::Table::TableStyle{})
      .def(py::init<const termui::strings &, const std::vector<termui::strings> &, const termui::Table::TableStyle &>(), py::arg("columns"), py::arg("rows"),
           py::arg("style") = termui::Table::TableStyle{})

      // Methods
      .def("column_width", &termui::Table::column_width, py::arg("col"), py::arg("w"), py::return_value_policy::reference, "Set column width")
      .def("table_height", &termui::Table::table_height, py::arg("h"), py::return_value_policy::reference, "Set table height")
      .def("cell_height", &termui::Table::cell_height, py::arg("h"), py::return_value_policy::reference, "Set cell height")
      .def("line_seperation", &termui::Table::line_seperation, py::arg("ls"), py::return_value_policy::reference, "Set line separation")
      .def("cursor_up", &termui::Table::cursor_up, py::arg("count") = 1, py::return_value_policy::reference, "Move cursor up")
      .def("cursor_down", &termui::Table::cursor_down, py::arg("count") = 1, py::return_value_policy::reference, "Move cursor down")
      .def("get_cursor", &termui::Table::get_cursor, py::return_value_policy::copy, "Get the cursor position")
      .def("colCount", &termui::Table::colCount, py::return_value_policy::copy, "Get the number of columns")
      .def("render", &termui::Table::render, py::return_value_policy::copy, "Render the table as a string");
}

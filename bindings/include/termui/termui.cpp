#include <pybind11/pybind11.h>

#include <termui/termui.hpp>

namespace py = pybind11;

void bind_mouse(py::module_ &m);
void bind_terminal(py::module_ &m);

void bind_globals(py::module_ &m);
void bind_util(py::module_ &m);

void bind_border(py::module_ &m);
void bind_color(py::module_ &m);
void bind_padding(py::module_ &m);
void bind_rendering(py::module_ &m);
void bind_str(py::module_ &m);
void bind_style(py::module_ &m);

void bind_input(py::module_ &m);
void bind_padded_text(py::module_ &m);
void bind_pager(py::module_ &m);
void bind_text(py::module_ &m);

void bind_area(py::module_ &m);
void bind_box(py::module_ &m);
void bind_lines(py::module_ &m);
void bind_progress_bar(py::module_ &m);

void bind_binary_menu(py::module_ &m);
void bind_fancy_menu(py::module_ &m);
void bind_info_box(py::module_ &m);
void bind_info_page(py::module_ &m);
void bind_input_box(py::module_ &m);
void bind_input_page(py::module_ &m);
void bind_interface(py::module_ &m);
void bind_menu(py::module_ &m);
void bind_spreadsheet(py::module_ &m);
void bind_text_editor(py::module_ &m);
void bind_toggle_menu(py::module_ &m);

void bind_button(py::module_ &m);
void bind_fancy_list(py::module_ &m);
void bind_list(py::module_ &m);
void bind_table(py::module_ &m);
void bind_toggle_list(py::module_ &m);

PYBIND11_MODULE(pytermui, m) {

  bind_mouse(m);
  bind_terminal(m);

  bind_border(m);
  bind_color(m);
  bind_padding(m);
  bind_rendering(m);
  bind_str(m);
  bind_style(m);

  bind_globals(m);
  bind_util(m);

  bind_input(m);
  bind_padded_text(m);
  bind_pager(m);
  bind_text(m);

  bind_area(m);
  bind_box(m);
  bind_lines(m);
  bind_progress_bar(m);

  bind_binary_menu(m);
  bind_fancy_menu(m);
  bind_info_box(m);
  bind_info_page(m);
  bind_input_box(m);
  bind_input_page(m);
  bind_interface(m);
  bind_menu(m);
  bind_spreadsheet(m);
  bind_text_editor(m);
  bind_toggle_menu(m);

  bind_button(m);
  bind_fancy_list(m);
  bind_list(m);
  bind_table(m);
  bind_toggle_list(m);

  //  bind_terminal(m);
  //  bind_rendering(m);
  //    bind_globals(m);
  //  bind_util(m);
  //  bind_border(m);
  //  bind_color(m);
  //  bind_padding(m);
  //  bind_str(m);
  //  bind_style(m);
  //  bind_mouse(m);
  // //  bind_input(m);
  // //  bind_padded_text(m);
  // //  bind_pager(m);
  // //  bind_text(m);
  // //  bind_area(m);
  // //  bind_box(m);
  // //  bind_lines(m);
  // //  bind_progress_bar(m);
  // //  bind_binary_menu(m);
  // //  bind_fancy_menu(m);
  // //  bind_menu(m);

  //  bind_input(m);
  //  bind_padded_text(m);
  //  bind_pager(m);
  //  bind_text(m);

  //  bind_area(m);
  //  bind_box(m);
  //  bind_lines(m);
  //  bind_progress_bar(m);

  //  bind_binary_menu(m);
  //  bind_fancy_menu(m);
  //  bind_info_box(m);
  //  bind_info_page(m);
  //  bind_input_box(m);
  //  bind_input_page(m);
  //  bind_interface(m);
  //  bind_menu(m);
  //  bind_spreadsheet(m);
  //  bind_text_editor(m);
  //  bind_toggle_menu(m);

  //  bind_button(m);
  //  bind_fancy_list(m);
  //  bind_list(m);
  //  bind_table(m);
  //  bind_toggle_list(m);
}

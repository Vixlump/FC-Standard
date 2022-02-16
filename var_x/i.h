#pragma once

void input_output_var();
void input_output_group();
void input_output();

void input_stream() {
  do {
    fc_getline();
    switch (active_script[line]) {
      case COREFC("+output"):
        input_output();
        break;
      //standard:
      case COREFC("i*")://sexit
      case COREFC("~~~*")://uexit
        return;
      case COREFC("%")://abstract register
        abstract_register();
        break;
      case COREFC("@*")://assignment wrap
        assignment_wrap();
        break;
      case COREFC("**")://debug point
        debug_point();
        break;
      case COREFC("")://whitespace
        break;
      case COREFC("*~~~")://channelswap stream
        channelswap_stream();
        break;
      default://error trigger
        error_stream();
        break;
    }
  } loop;

}

void input_output() {
  do {
    fc_getline();
    switch (active_script[line]) {
      case COREFC("_line"):
        fc_getline();
        cout<<codex_get_string(active_script[line])<<endl;
        break;
      case COREFC("_var"):
        input_output_var();
        break;
      case COREFC("_group"):
        input_output_group();
        break;
      case COREFC("_break"):
        cout<<endl;
        break;
      case COREFC("_text"):
        fc_getline();
        cout<<codex_get_string(active_script[line]);
        break;
      case COREFC("_ret"):
        return;
      default:
        error_stream();
        break;
    }
  } loop;
}

void input_output_var() {
  fc_getline();
  switch (active_script[line]) {
    case COREFC("_int"):
    case COREFC("_int64"):
      fc_getline();
      cout<<codex_return_int64(active_script[line]);
      break;
    case COREFC("_int32"):
      fc_getline();
      cout<<codex_return_int32(active_script[line]);
      break;
    case COREFC("_int16"):
      fc_getline();
      cout<<codex_return_int16(active_script[line]);
      break;
    case COREFC("_int8"):
      fc_getline();
      cout<<codex_return_int8(active_script[line]);
      break;
    case COREFC("_float"):
      fc_getline();
      cout<<codex_return_float(active_script[line]);
      break;
    case COREFC("_double"):
      fc_getline();
      cout<<codex_return_double(active_script[line]);
      break;
    case COREFC("_triple"):
      fc_getline();
      cout<<codex_return_triple(active_script[line]);
      break;
    case COREFC("_bool"):
      fc_getline();
      cout<<codex_return_bool(active_script[line]);
      break;
    case COREFC("_string"):
      fc_getline();
      cout<<codex_return_string(active_script[line]);
      break;
    case COREFC("_array"):
      break;
    default:
      error_stream();
      break;
  }
}
void input_output_group() {
  do {
    fc_getline();
    switch(active_script[line]) {
      case COREFC("_break"):
        cout<<endl;
        break;
      case COREFC("_var"):
        input_output_var();
        break;
      case COREFC("_ret"):
        return;
      default:
        cout<<codex_get_string(active_script[line]);
        break;
    }
  } loop;
}
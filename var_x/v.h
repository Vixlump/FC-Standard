#pragma once
void var_create_string(uint32_t input_name, int64_t input_size);
void var_store_string(uint32_t input_name, int64_t pos, uint32_t value);
string var_request_string(uint32_t input_name, int64_t pos);
void var_store();

void var_stream() {
  do {
    fc_getline();
    switch(active_script[line]) {
      case COREFC("+store"):
        var_store();
        break;
      case COREFC("+convert"):
        break;
      case COREFC("+swap"):
        break;
      case COREFC("+allocate"):
        break;
      case COREFC("+delete"):
        break;
      case COREFC("+locate"):
        break;
        //standard:
        case COREFC("v*")://sexit
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
      default:
        error_stream();
        break;
    }
  } loop;
}

void var_store() {
  do {
    fc_getline();
    switch(active_script[line]) {
      case COREFC("_int"):
      case COREFC("_int64"):
        break;
      case COREFC("_int32"):
        break;
      case COREFC("_int16"):
        break;
      case COREFC("_int8"):
        break;
      case COREFC("_double"):
        break;
      case COREFC("_float"):
        break;
      case COREFC("_triple"):
        break;
      case COREFC("_bool"):
        break;
      case COREFC("string"):
        break;
      case COREFC("_var"):
        break;
      case COREFC("_array"):
        break;
      case COREFC("_ret"):
        return;
      default:
        error_stream();
        break;
    }
  } loop;

}

void var_create_string(uint32_t input_name, int64_t input_size) {
  fc_type_string input_type;
  input_type.name = input_name;
  if (input_size == 0) {

  } else {
    for (int64_t i = 0; i < input_size; i++) {
      input_type.value.push_back("");
    }
  }
  string_var.push_back(input_type);
}
void var_store_string(uint32_t input_name, int64_t pos, uint32_t value) {
  for (int64_t i = 0; i < string_var.size(); i++) {
    if (string_var[i].name == input_name) {
      if (pos < string_var[i].value.size()) {
        string_var[i].value[pos] = codex_get_string(value);
        return;
      } else {
        var_create_string(input_name, pos+1);
        string_var[i].value[pos] = codex_get_string(value);
        return;
      }
    }
  }
  error_stream();
}
string var_request_string(uint32_t input_name, int64_t pos) {
  for (uint64_t i = 0; i < string_var.size(); i++) {
    if (string_var[i].name == input_name) {
      if (pos < string_var[i].value.size()) {
        return string_var[i].value[pos];
      } else {
        error_stream();
        return "";
      }
    }
  }
  error_stream();
  return "";
}
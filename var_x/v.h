#pragma once
void var_convert();
void var_store_array();
void var_store();

void var_stream() {
  do {
    fc_getline();
    switch(active_script[line]) {
      case COREFC("+store"):
        var_store();
        break;
      case COREFC("+convert"):
        var_convert();
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


template <typename T>
void var_convert_numbers(T input) {
  fc_getline();
  switch(active_script[line]) {
    case COREFC("_int"):
    case COREFC("_int64"):
      fc_getline();
      if constexpr (std::is_same_v<T, string>) {
        codex_store_int64(active_script[line], stoll(input.c_str()));
      } else {
        codex_store_int64(active_script[line], static_cast<int64_t>(input));
      }
      break;
    case COREFC("_int32"):
      fc_getline();
      if constexpr (std::is_same_v<T, string>) {
        codex_store_int32(active_script[line], stol(input.c_str()));
      } else {
        codex_store_int32(active_script[line], static_cast<int32_t>(input));
      }
      break;
    case COREFC("_int16"):
      fc_getline();
      if constexpr (std::is_same_v<T, string>) {
        codex_store_int16(active_script[line], atoi(input.c_str()));
      } else {
        codex_store_int16(active_script[line], static_cast<int16_t>(input));
      }
      break;
    case COREFC("_int8"):
      fc_getline();
      if constexpr (std::is_same_v<T, string>) {
        codex_store_int8(active_script[line], atoi(input.c_str()));
      } else {
        codex_store_int8(active_script[line], static_cast<int8_t>(input));
      }
      break;
    case COREFC("_bool"):
      fc_getline();
      if constexpr (std::is_same_v<T, string>) {
        if (input=="1"||input=="true"||input=="True"||input=="TRUE") {codex_store_bool(active_script[line], true);} else {codex_store_bool(active_script[line], false);}
      } else {
        codex_store_bool(active_script[line], static_cast<bool>(input));
      }
      break;
    case COREFC("_triple"):
      fc_getline();
      if constexpr (std::is_same_v<T, string>) {
        codex_store_triple(active_script[line], stold(input.c_str()));
      } else {
        codex_store_triple(active_script[line], static_cast<triple>(input));
      }
      break;
    case COREFC("_double"):
      fc_getline();
      if constexpr (std::is_same_v<T, string>) {
        codex_store_double(active_script[line], stod(input.c_str()));
      } else {
        codex_store_double(active_script[line], static_cast<double>(input));
      }
      break;
    case COREFC("_float"):
      fc_getline();
      if constexpr (std::is_same_v<T, string>) {
        codex_store_float(active_script[line], atof(input.c_str()));
      } else {
        codex_store_float(active_script[line], static_cast<float>(input));
      }
      break;
    case COREFC("_string"):
      fc_getline();
      if constexpr (std::is_same_v<T, string>) {
        codex_store_string(active_script[line], input);
      } else {
        codex_store_string(active_script[line], to_string(input));
      }
      break;
    default:
      error_stream();
      break;
  }
}

void var_convert() {
  do {
    fc_getline();
    switch(active_script[line]) {
      case COREFC("_int"):
      case COREFC("_int64"):
        fc_getline();
        var_convert_numbers<int64_t>(codex_return_int64(active_script[line]));
        break;
      case COREFC("_int32"):
        fc_getline();
        var_convert_numbers<int32_t>(codex_return_int32(active_script[line]));
        break;
      case COREFC("_int16"):
        fc_getline();
        var_convert_numbers<int16_t>(codex_return_int16(active_script[line]));
        break;
      case COREFC("_int8"):
        fc_getline();
        var_convert_numbers<int8_t>(codex_return_int8(active_script[line]));
        break;
      case COREFC("_bool"):
        fc_getline();
        var_convert_numbers<bool>(codex_return_bool(active_script[line]));
        break;
      case COREFC("_triple"):
        fc_getline();
        var_convert_numbers<triple>(codex_return_triple(active_script[line]));
        break;
      case COREFC("_double"):
        fc_getline();
        var_convert_numbers<double>(codex_return_double(active_script[line]));
        break;
      case COREFC("_float"):
        fc_getline();
        var_convert_numbers<float>(codex_return_float(active_script[line]));
        break;
      case COREFC("_string"):
        fc_getline();
        var_convert_numbers<string>(codex_return_string(active_script[line]));
        break;
      case COREFC("_ret"):
        return;
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
        fc_getline();
        codex_store_int64(active_script[line], codex_get_int64(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_int32"):
        fc_getline();
        codex_store_int32(active_script[line], codex_get_int32(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_int16"):
        fc_getline();
        codex_store_int16(active_script[line], codex_get_int16(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_int8"):
        fc_getline();
        codex_store_int8(active_script[line], codex_get_int8(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_double"):
        fc_getline();
        codex_store_double(active_script[line], codex_get_double(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_float"):
        fc_getline();
        codex_store_float(active_script[line], codex_get_float(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_triple"):
        fc_getline();
        codex_store_triple(active_script[line], codex_get_triple(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_bool"):
        fc_getline();
        codex_store_bool(active_script[line], codex_get_bool(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_string"):
        fc_getline();
        codex_store_string(active_script[line], codex_get_string(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_var"):
        break;
      case COREFC("_array"):
        var_store_array();
        break;
      case COREFC("_ret"):
        return;
      default:
        error_stream();
        break;
    }
  } loop;

}
void var_store_array() {
  fc_getline();
  switch (active_script[line]) {
      case COREFC("_int"):
      case COREFC("_int64"):
        fc_getline();
        codex_store_int64(active_script[line], codex_get_int64(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_int32"):
        fc_getline();
        codex_store_int32(active_script[line], codex_get_int32(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_int16"):
        fc_getline();
        codex_store_int16(active_script[line], codex_get_int16(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_int8"):
        fc_getline();
        codex_store_int8(active_script[line], codex_get_int8(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_double"):
        fc_getline();
        codex_store_double(active_script[line], codex_get_double(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_float"):
        fc_getline();
        codex_store_float(active_script[line], codex_get_float(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_triple"):
        fc_getline();
        codex_store_triple(active_script[line], codex_get_triple(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("_bool"):
        fc_getline();
        codex_store_bool(active_script[line], codex_get_bool(active_script[line+1]));
        fc_getline();
        break;
      case COREFC("string"):
        fc_getline();
        codex_store_string(active_script[line], codex_get_string(active_script[line+1]));
        fc_getline();
        break;
      default:
        error_stream();
        break;
  }
}
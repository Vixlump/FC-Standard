#pragma once
#define FCS_V
void var_allocate();
void var_convert();
void var_store_array();
void var_store();
void var_array();
void var_delete();
void var_swap();

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
        var_swap();
        break;
      case COREFC("+array"):
        var_array();
        break;
      case COREFC("+allocate"):
        var_allocate();
        break;
      case COREFC("+delete"):
        var_delete();
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
      case COREFC("**")://debug point
        debug_point();
        break;
      case COREFC("")://whitespace
      case COREFC("*null")://do nothing
          fc_nothing();
        break;
      case COREFC("*~~~")://channelswap stream
        channelswap_stream();
        break;
      default:
        error_stream("*v->*error");
        break;
    }
  } loop;
}

void var_allocate() {
  do {
    fc_getline();
    fc_getline();
    switch (active_script[line-1]) {
      case COREFC("_int"):
      case COREFC("_int64"):
        break;
      case COREFC("_int32"):
        break;
      case COREFC("_int16"):
        break;
      case COREFC("_int8"):
        break;
      case COREFC("_bool"):
        break;
      case COREFC("_triple"):
        break;
      case COREFC("_double"):
        break;
      case COREFC("_float"):
        break;
      case COREFC("_string"):
        break;
      case COREFC("_hash"):
        break;
      case COREFC("_ret"):
        return;
      case COREFC("_chart"):
        break;
      case COREFC("_quantum"):
        break;
      case COREFC("_array"):
        break;
      default:
        error_stream("+allocate->*error");
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
    case COREFC("_hash"):
      fc_getline();
      if constexpr (std::is_same_v<T, string>) {
        codex_store_hash(active_script[line], stoull(input.c_str()));
      } else {
        codex_store_hash(active_script[line], static_cast<uint64_t>(input));
      }
      break;
    default:
      error_stream("+convert->_var->*error");
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
        var_convert_numbers<int64_t>(codex_get_int64(active_script[line]));
        break;
      case COREFC("_int32"):
        fc_getline();
        var_convert_numbers<int32_t>(codex_get_int32(active_script[line]));
        break;
      case COREFC("_int16"):
        fc_getline();
        var_convert_numbers<int16_t>(codex_get_int16(active_script[line]));
        break;
      case COREFC("_int8"):
        fc_getline();
        var_convert_numbers<int8_t>(codex_get_int8(active_script[line]));
        break;
      case COREFC("_bool"):
        fc_getline();
        var_convert_numbers<bool>(codex_get_bool(active_script[line]));
        break;
      case COREFC("_triple"):
        fc_getline();
        var_convert_numbers<triple>(codex_get_triple(active_script[line]));
        break;
      case COREFC("_double"):
        fc_getline();
        var_convert_numbers<double>(codex_get_double(active_script[line]));
        break;
      case COREFC("_float"):
        fc_getline();
        var_convert_numbers<float>(codex_get_float(active_script[line]));
        break;
      case COREFC("_string"):
        fc_getline();
        var_convert_numbers<string>(codex_get_string(active_script[line]));
        break;
      case COREFC("_hash"):
        fc_getline();
        var_convert_numbers<uint64_t>(codex_get_hash(active_script[line]));
        break;
      case COREFC("_ret"):
        return;
      default:
        error_stream("+convert->*error");
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
        fc_getline();
        codex_store_int64(active_script[line-1], codex_get_int64(active_script[line]));
        break;
      case COREFC("_int32"):
        fc_getline();
        fc_getline();
        codex_store_int32(active_script[line-1], codex_get_int32(active_script[line]));
        break;
      case COREFC("_int16"):
        fc_getline();
        fc_getline();
        codex_store_int16(active_script[line-1], codex_get_int16(active_script[line]));
        break;
      case COREFC("_int8"):
        fc_getline();
        fc_getline();
        codex_store_int8(active_script[line-1], codex_get_int8(active_script[line]));
        break;
      case COREFC("_double"):
        fc_getline();
        fc_getline();
        codex_store_double(active_script[line-1], codex_get_double(active_script[line]));
        break;
      case COREFC("_float"):
        fc_getline();
        fc_getline();
        codex_store_float(active_script[line-1], codex_get_float(active_script[line]));
        break;
      case COREFC("_triple"):
        fc_getline();
        fc_getline();
        codex_store_triple(active_script[line-1], codex_get_triple(active_script[line]));
        break;
      case COREFC("_bool"):
        fc_getline();
        fc_getline();
        codex_store_bool(active_script[line-1], codex_get_bool(active_script[line]));
        break;
      case COREFC("_string"):
        fc_getline();
        fc_getline();
        codex_store_string(active_script[line-1], codex_get_string(active_script[line]));
        break;
      case COREFC("_hash"):
        fc_getline();
        fc_getline();
        codex_store_hash(active_script[line-1], codex_get_hash(active_script[line]));
        break;
      case COREFC("_all"):
        fc_getline();
        fc_getline();
        codex_store_all(active_script[line-1], codex_get_string(active_script[line]));
        break;
      case COREFC("_array"):
        var_store_array();
        break;
      case COREFC("_ret"):
        return;
      default:
        error_stream("+store->*error");
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
        codex_store_int64_array(active_script[line],codex_get_int64(active_script[line+1]), codex_get_int64(active_script[line+2]));
        fc_getline();fc_getline();
        break;
      case COREFC("_int32"):
        fc_getline();
        codex_store_int32_array(active_script[line],codex_get_int64(active_script[line+1]), codex_get_int32(active_script[line+2]));
        fc_getline();fc_getline();
        break;
      case COREFC("_int16"):
        fc_getline();
        codex_store_int16_array(active_script[line],codex_get_int64(active_script[line+1]), codex_get_int16(active_script[line+2]));
        fc_getline();fc_getline();
        break;
      case COREFC("_int8"):
        fc_getline();
        codex_store_int8_array(active_script[line],codex_get_int64(active_script[line+1]), codex_get_int8(active_script[line+2]));
        fc_getline();fc_getline();
        break;
      case COREFC("_double"):
        fc_getline();
        codex_store_double_array(active_script[line],codex_get_int64(active_script[line+1]), codex_get_double(active_script[line+2]));
        fc_getline();fc_getline();
        break;
      case COREFC("_float"):
        fc_getline();
        codex_store_float_array(active_script[line],codex_get_int64(active_script[line+1]), codex_get_float(active_script[line+2]));
        fc_getline();fc_getline();
        break;
      case COREFC("_triple"):
        fc_getline();
        codex_store_triple_array(active_script[line],codex_get_int64(active_script[line+1]), codex_get_triple(active_script[line+2]));
        fc_getline();fc_getline();
        break;
      case COREFC("_bool"):
        fc_getline();
        codex_store_bool_array(active_script[line],codex_get_int64(active_script[line+1]), codex_get_bool(active_script[line+2]));
        fc_getline();fc_getline();
        break;
      case COREFC("_string"):
        fc_getline();
        codex_store_string_array(active_script[line],codex_get_int64(active_script[line+1]), codex_get_string(active_script[line+2]));
        fc_getline();fc_getline();
        break;
      case COREFC("_hash"):
        fc_getline();
        codex_store_hash_array(active_script[line],codex_get_int64(active_script[line+1]), codex_get_hash(active_script[line+2]));
        fc_getline();fc_getline();
        break;
      default:
        error_stream("+store->_array->*error");
        break;
  }
}

void var_array() {
  do {
    fc_getline();
      switch(active_script[line]) {
        case COREFC("_push")://accept _front or _back operator
          break;
        case COREFC("_pop")://accept _front or _back operator
          break;
        case COREFC("_get"):
          break;
        case COREFC("_size"):
          break;
        case COREFC("_erase"):
          break;
        case COREFC("_clear"):
          break;
        default:
          error_stream("+array->*error");
          break;
      }
  } loop;
}

void var_delete_array() {
  fc_getline();
  switch (active_script[line]) {
    case COREFC("_int"):
    case COREFC("_int64"):
      fc_getline();
      int64_var_array[active_script[line]].clear();
      int64_var_array.erase(active_script[line]);
      break;
    case COREFC("_int32"):
      fc_getline();
      int32_var_array[active_script[line]].clear();
      int32_var_array.erase(active_script[line]);
      break;
    case COREFC("_int16"):
      fc_getline();
      int16_var_array[active_script[line]].clear();
      int16_var_array.erase(active_script[line]);
      break;
    case COREFC("_int8"):
      fc_getline();
      int8_var_array[active_script[line]].clear();
      int8_var_array.erase(active_script[line]);
      break;
    case COREFC("_bool"):
      fc_getline();
      bool_var_array[active_script[line]].clear();
      bool_var_array.erase(active_script[line]);
      break;
    case COREFC("_triple"):
      fc_getline();
      triple_var_array[active_script[line]].clear();
      triple_var_array.erase(active_script[line]);
      break;
    case COREFC("_double"):
      fc_getline();
      double_var_array[active_script[line]].clear();
      double_var_array.erase(active_script[line]);
      break;
    case COREFC("_float"):
      fc_getline();
      float_var_array[active_script[line]].clear();
      float_var_array.erase(active_script[line]);
      break;
    case COREFC("_string"):
      fc_getline();
      string_var_array[active_script[line]].clear();
      string_var_array.erase(active_script[line]);
      break;
    case COREFC("_hash"):
      fc_getline();
      hash_var_array[active_script[line]].clear();
      hash_var_array.erase(active_script[line]);
      break;
    default:
      error_stream("+delete->_array->*error");
      break;
  }
}

void var_delete() {
  do {
    fc_getline();
    switch (active_script[line]) {
      case COREFC("_int"):
      case COREFC("_int64"):
        fc_getline();
        int64_var.erase(active_script[line]);
        break;
      case COREFC("_int32"):
        fc_getline();
        int32_var.erase(active_script[line]);
        break;
      case COREFC("_int16"):
        fc_getline();
        int16_var.erase(active_script[line]);     
        break;
      case COREFC("_int8"):
        fc_getline();
        int8_var.erase(active_script[line]);
        break;
      case COREFC("_bool"):
        fc_getline();
        bool_var.erase(active_script[line]);
        break;
      case COREFC("_triple"):
        fc_getline();
        triple_var.erase(active_script[line]);
        break;
      case COREFC("_double"):
        fc_getline();
        double_var.erase(active_script[line]);
        break;
      case COREFC("_float"):
        fc_getline();
        float_var.erase(active_script[line]);
        break;
      case COREFC("_string"):
        fc_getline();
        string_var.erase(active_script[line]);
        break;
      case COREFC("_hash"):
        fc_getline();
        hash_var.erase(active_script[line]);
        break;
      case COREFC("_array"):
        var_delete_array();
        break;
      case COREFC("_ret"):
        return;
      default:
        error_stream("+delete->*error");
        break;
    }
  } loop;
}

void var_swap() {
  do {
    fc_getline();
    switch(active_script[line]) {
      case COREFC("_int"):
      case COREFC("_int64"):
        {
          fc_getline();
          int64_t i = codex_return_int64(active_script[line]);
          uint64_t name = active_script[line];
          fc_getline();
          codex_store_int64(name, codex_return_int64(active_script[line]));
          codex_store_int64(active_script[line], i);
          break;
        }
      case COREFC("_int32"):
        {
          fc_getline();
          int32_t i = codex_return_int32(active_script[line]);
          uint64_t name = active_script[line];
          fc_getline();
          codex_store_int32(name, codex_return_int32(active_script[line]));
          codex_store_int32(active_script[line], i);
          break;
        }
      case COREFC("_int16"):
        {
          fc_getline();
          int16_t i = codex_return_int16(active_script[line]);
          uint64_t name = active_script[line];
          fc_getline();
          codex_store_int16(name, codex_return_int16(active_script[line]));
          codex_store_int16(active_script[line], i);
          break;
        }
      case COREFC("_int8"):
        {
          fc_getline();
          int8_t i = codex_return_int8(active_script[line]);
          uint64_t name = active_script[line];
          fc_getline();
          codex_store_int8(name, codex_return_int8(active_script[line]));
          codex_store_int8(active_script[line], i);
          break;
        }
      case COREFC("_bool"):
        {
          fc_getline();
          bool i = codex_return_bool(active_script[line]);
          uint64_t name = active_script[line];
          fc_getline();
          codex_store_bool(name, codex_return_bool(active_script[line]));
          codex_store_bool(active_script[line], i);
          break;
        }
      case COREFC("_triple"):
        {
          fc_getline();
          triple i = codex_return_triple(active_script[line]);
          uint64_t name = active_script[line];
          fc_getline();
          codex_store_triple(name, codex_return_triple(active_script[line]));
          codex_store_triple(active_script[line], i);
          break;
        }
      case COREFC("_double"):
        {
          fc_getline();
          double i = codex_return_double(active_script[line]);
          uint64_t name = active_script[line];
          fc_getline();
          codex_store_double(name, codex_return_double(active_script[line]));
          codex_store_double(active_script[line], i);
          break;
        }
      case COREFC("_float"):
        {
          fc_getline();
          float i = codex_return_float(active_script[line]);
          uint64_t name = active_script[line];
          fc_getline();
          codex_store_float(name, codex_return_float(active_script[line]));
          codex_store_float(active_script[line], i);
          break;
        }
      case COREFC("_string"):
        {
          fc_getline();
          string i = codex_return_string(active_script[line]);
          uint64_t name = active_script[line];
          fc_getline();
          codex_store_string(name, codex_return_string(active_script[line]));
          codex_store_string(active_script[line], i);
          break;
        }
      case COREFC("_hash"):
        {
          fc_getline();
          uint64_t i = codex_return_hash(active_script[line]);
          uint64_t name = active_script[line];
          fc_getline();
          codex_store_hash(name, codex_return_hash(active_script[line]));
          codex_store_hash(active_script[line], i);
          break;
        }
      case COREFC("_ret"):
        return;
      default:
        error_stream("+swap->*error");
        break;
    }
  } loop;
}
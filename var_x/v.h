#pragma once
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
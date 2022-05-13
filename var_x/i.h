#pragma once
#define FCS_I

void input_output_var();
void input_output_group();
void input_output();
void input_string();
void input_inspect();

void input_stream() {
  do {
    fc_getline();
    switch (active_script[line]) {
      case COREFC("+output"):
        input_output();
        break;
      case COREFC("+string"):
        input_string();
        break;
      case COREFC("+inspect"):
        input_inspect();
        break;
      case COREFC("+input"):
        {
          fc_getline();
          string input;
          cin>>input;
          codex_store_string(active_script[line], input);
        }
        break;
      //standard:
      case COREFC("i*")://sexit
      case COREFC("~~~*")://uexit
        return;
      case COREFC("%")://abstract register
        abstract_register();
        break;
      case COREFC("**")://debug point
        debug_point();
        break;
      case COREFC("")://whitespace
        break;
      case COREFC("*~~~")://channelswap stream
        channelswap_stream();
        break;
      case COREFC("@*")://assignment wrap
        assignment_wrap();
        break;
      default://error trigger
        error_stream("*i->*error");
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
        cout<<codex_get_string(active_script[line])<<"\n";
        break;
      case COREFC("_var"):
        input_output_var();
        break;
      case COREFC("_group"):
        input_output_group();
        break;
      case COREFC("_end"):
        cout<<endl;
        break;
      case COREFC("_break"):
        cout<<"\n";
        break;
      case COREFC("_text"):
        fc_getline();
        cout<<codex_get_string(active_script[line]);
        break;
      case COREFC("_ret"):
        return;
      default:
        error_stream("+output->*error");
        break;
    }
  } loop;
}

void input_inspect_parce() {
  fc_getline();
  string inspector_string = codex_get_string(active_script[line]);
  fc_getline();
  string delimiter = codex_get_string(active_script[line]);
  size_t pos = 0;
  string token;
  fc_getline();
  uint64_t i = 0;
  while ((pos = inspector_string.find(delimiter)) != string::npos) {
      token = inspector_string.substr(0, pos);
      codex_add_string_array(active_script[line],token);
      inspector_string.erase(0, pos + delimiter.length());
      i++;
  }
  codex_add_string_array(active_script[line],inspector_string);
}

void input_inspect() {
  do {
    fc_getline();
    switch(active_script[line]) {
      case COREFC("_parce"):
        input_inspect_parce();
        break;
      case COREFC("_ret"):
        return;
      default:
        error_stream("+inspect->*error");
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
    case COREFC("_hash"):
      fc_getline();
      cout<<codex_return_hash(active_script[line]);
      break;
    case COREFC("_chart"):
      break;
    default:
      error_stream("+output->_var->*error");
      break;
  }
}
void input_output_group() {
  do {
    fc_getline();
    switch(active_script[line]) {
      case COREFC("_end"):
        cout<<endl;
        break;
      case COREFC("_break"):
        cout<<"\n";
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

void input_string() {
  do {
    fc_getline();
    switch(active_script[line]) {
      case COREFC("_get"):
        break;
      case COREFC("_length"):
        break;
      case COREFC("_trunk"):
        break;
      case COREFC("_add"):
        break;
      case COREFC("_"):
        break;
      case COREFC("_ret"):
        return;
      default:
        error_stream("+string->*error");
        break;
    }
  } loop;
}
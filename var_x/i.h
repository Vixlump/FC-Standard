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
      case COREFC("*nothing")://do nothing
        fc_nothing();
        break;
      case COREFC("*~~~")://channelswap stream
        channelswap_stream();
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

void input_string_get() {
  fc_getline();
  uint64_t name = active_script[line];
  fc_getline();
  uint64_t pos = codex_get_int64(active_script[line]);
  fc_getline();
  switch (active_script[line]) {
    case COREFC("_string"):
      fc_getline();
      string_var[active_script[line]] = string_var[name][pos];
      break;
    case COREFC("_char"):
    case COREFC("_int8"):
      fc_getline();
      int8_var[active_script[line]] = string_var[name][pos];
      break;
    default:
      error_stream("+string->_get->*error");
      break;
  }

}
void input_string_length() {
  fc_getline();
  uint64_t name = active_script[line];
  fc_getline();
  codex_store_int64(active_script[line], codex_get_string(name).length());

}
void input_string_trunk() {
    fc_getline();
    uint64_t name = active_script[line];
    string i = codex_get_string(name);
    fc_getline();
    string i_erase = codex_get_string(active_script[line]);
    cout<<"hit1 ";
    size_t pos = i.find(i_erase);
    cout<<"hit2 ";
    if (pos != std::string::npos)
    {
        cout<<"hit3 ";
        i.erase(pos, i_erase.length());
    }
    cout<<"hit4 ";
    codex_store_string(name, i);
    cout<<"hit5 ";
}
void input_string_add() {
  fc_getline();
  switch (active_script[line]) {
    case COREFC("_front"):
      {
        fc_getline();
        uint64_t name = active_script[line];
        fc_getline();
        uint64_t name2 = active_script[line];
        string i = codex_get_string(name);
        i.insert(0, 1, codex_get_int8(name2));
        codex_store_string(name, i);
        break;
      }
    case COREFC("_back"):
      {
        fc_getline();
        uint64_t name = active_script[line];
        fc_getline();
        uint64_t name2 = active_script[line];
        string i = codex_get_string(name);
        i.push_back(codex_get_int8(name2));
        codex_store_string(name, i);
        break;
      }
    default:
      error_stream("+string->_add->*error");
      break;
  }
}
void input_string_char() {
  fc_getline();
  uint64_t name = active_script[line];
  fc_getline();
  string i = codex_get_string(active_script[line]);
  int8_var[name] = i[0];
}
void input_string_find() {

}

void input_string() {//need to add maker lower and make upercase and if lower or uppercase
  do {
    fc_getline();
    switch(active_script[line]) {
      case COREFC("_get"):
        input_string_get();
        break;
      case COREFC("_length"):
        input_string_length();
        break;
      case COREFC("_trunc"):
        input_string_trunk();//might still be broken
        break;
      case COREFC("_add"):
        input_string_add();
        break;
      case COREFC("_char"):
      case COREFC("_int8"):
        input_string_char();
        break;
      case COREFC("_find")://get number of chars within string, get possition of sub string within value
        break;
      case COREFC("_ret"):
        return;
      default:
        error_stream("+string->*error");
        break;
    }
  } loop;
}
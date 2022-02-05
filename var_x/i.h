#pragma once

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
      case COREFC("_ret"):
        return;
      default:
        error_stream();
        break;
    }
  } loop;
}

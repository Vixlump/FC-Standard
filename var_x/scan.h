#pragma once
//Template: case UIRN("",strlen("")):

void scan_stream() {
  do {
    fc_getline();
    switch (active_script[line]) {
      //crutials
      case COREFC("*v")://variable stream
        var_stream();
        goto escape_stream;
      case COREFC("*m")://math stream
        math_stream();
        goto escape_stream;
      case COREFC("*c")://control stream
        control_stream();
        goto escape_stream;
      case COREFC("*f")://functional stream
        goto escape_stream;
      case COREFC("*t")://threading
        goto escape_stream;
      case COREFC("*x")://external stream
        goto escape_stream;
      case COREFC("f")://define function
        fc_function_create();
        goto escape_stream;
      case COREFC("//A")://action overloader
        action_overloading_stream();
        goto escape_stream;
      //standard:
      case COREFC("?*")://sexit
        return;
      case COREFC("%")://abstract register
        abstract_register();
        goto escape_stream;
      case COREFC("~~~*")://uexit
        goto escape_stream;
      default:
        break;
    }
    //function checkerhere:
    if (fc_function_check()==true) {goto escape_stream;}
    switch (active_script[line]) {
      case COREFC("**")://debug point
        debug_point();
        break;
      case COREFC("")://whitespace
        break;
      case COREFC("*~~~")://channel swap
        channelswap_stream();
        break;
      //uncrutials
      case COREFC("*a")://aspectu standard compute tools
        break;
      case COREFC("*e")://experimental stream
        break;
      case COREFC("*r")://reserved stream
        reserved_stream();
        break;
      case COREFC("*i")://input stream
        input_stream();
        break;
      case COREFC("@*")://assignment wrap
        assignment_wrap();
        break;
      default://error trigger
        error_stream();
        break;
    }
    escape_stream:
      assignment_wrap();
  } while ((line+1 < active_script.size()) || (line == phantom_line));
}

#pragma once
//Template: case UIRN("",strlen("")):

void scan_donothing() {
  return;
}

void scan_stream() {
  do {
    fc_getline();
    switch (active_script[line]) {
      //crutials
      #ifdef FCS_V
      case COREFC("*v")://variable stream
        var_stream();
        goto escape_stream;
      #endif
      #ifdef FCS_M
      case COREFC("*m")://math stream
        math_stream();
        goto escape_stream;
      #endif
      #ifdef FCS_C
      case COREFC("*c")://control stream
        control_stream();
        goto escape_stream;
      #endif
      #ifdef FCS_F
      case COREFC("*f")://functional stream
        functional_stream();
        goto escape_stream;
      #endif
      #ifdef FCS_T
      case COREFC("*t")://threading
        threading_stream();
        goto escape_stream;
      #endif
      #ifdef FCS_X
      case COREFC("*x")://external stream
        xternal_stream();
        goto escape_stream;
      #endif
      #ifdef FCS_FUNCTIONDRIVER
      case COREFC("f")://define function
        fc_function_create();
        goto escape_stream;
      #endif
      #ifdef FCS_OVERLOADER
      case COREFC("//A")://action overloader
        action_overloading_stream();
        goto escape_stream;
      #endif
      //standard:
      case COREFC("?*")://sexit
        return;
      #ifdef FCS_ABREG
      case COREFC("%")://abstract register
        abstract_register();
        goto escape_stream;
      #endif
      case COREFC("~~~*")://uexit
        goto escape_stream;
      #ifdef ASPECTUFXTOOLS
      case COREFC("*a")://aspectu standard compute tools
        aspectu_stream();
        goto escape_stream;
      #endif
      default:
        break;
    }
    //function checkerhere:
    #ifdef FCS_FUNCTIONDRIVER
    if (fc_function_check()==true) {goto escape_stream;}
    #endif
    switch (active_script[line]) {
      #ifdef FCS_DEBUG
      case COREFC("**")://debug point
        debug_point();
        break;
      #endif
      case COREFC("")://whitespace
        break;
      #ifdef FCS_CSWAP
      case COREFC("*~~~")://channel swap
        channelswap_stream();
        break;
      #endif
      //uncrutials
      case COREFC("*e")://experimental stream
        break;
      #ifdef FCS_R
      case COREFC("*r")://reserved stream
        reserved_stream();
        break;
      #endif
      #ifdef FCS_O
      case COREFC("*o")://optimization stream
        optimization_stream();
        break;
      #endif
      #ifdef FCS_I
      case COREFC("*i")://input stream
        input_stream();
        break;
      #endif
      default://error trigger
        #ifdef FCS_ERROR
        error_stream("*?->*error");
        #endif
        break;
    }
    escape_stream:
      scan_donothing();
  } while ((line+1 < active_script.size()) || (line == phantom_line));
}

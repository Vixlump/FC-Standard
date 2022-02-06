#pragma once
//Template: case UIRN("",strlen("")):

void scan_stream() {
  do {
    fc_getline();
    switch (active_script[line]) {
      //crutials
      case COREFC("*v")://variable stream
        break;
      case COREFC("*m")://math stream
        break;
      case COREFC("*c")://control stream
        break;
      case COREFC("*f")://functional stream
        break;
      case COREFC("f")://define function
        break;
      case COREFC("*t")://threading
        break;
      case COREFC("*x")://external stream
        break;
      //standard:
      case COREFC("?*")://sexit
        return;
      case COREFC("%")://abstract register
        abstract_register();
        break;
      case COREFC("@*")://assignment wrap
        assignment_wrap();
        break;
      case COREFC("~~~*")://uexit
        break;
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
      default://error trigger
        error_stream();
        break;
    }
  } while ((line+1 < active_script.size()) || (line == phantom_line));
}

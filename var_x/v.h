#pragma once

void var_stream() {
  do {
    fc_getline();
    switch(active_script[line]) {
      case COREFC("+store"):
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
        case COREFC("*@")://assignment point
          assignment_point();
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

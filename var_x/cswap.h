#pragma once

void channelswap_stream() {
  fc_getline();
  switch (active_script[line]) {
    case COREFC("*<"):
      break;
    case COREFC(">*"):
      break;
    case COREFC("+patch"):
      break;
    case COREFC("+scan"):
      break;
    case COREFC("_string"):
      break;
      fc_getline();
      load_codex(codex_get_string(active_script[line]));
    default:
      load_codex(codex_get_string(active_script[line]));
      break;
  }
}

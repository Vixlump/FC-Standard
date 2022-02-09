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
    default:
      load_codex(codex_get_string(active_script[line]));
      break;
  }
}

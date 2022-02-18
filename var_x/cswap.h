#pragma once

void channelswap_stream() {
  fc_getline();
  switch (active_script[line]) {
    case COREFC("*<"):
      {
        fc_getline();
        uint64_t i = line;
        string i2 = file_name;
        load_codex(codex_get_string(active_script[line]));
        scan_stream();
        load_codex(i2);
        line = i;
        break;
      }
    case COREFC("+patch"):
      {
        uint64_t i = line;
        load_codex(file_name);
        line = i;
        break;
      }
    case COREFC("+scan"):
      break;
    case COREFC("_string"):
      fc_getline();
      load_codex(codex_get_string(active_script[line]));
      break;
    default:
      load_codex(codex_get_string(active_script[line]));
      break;
  }
}

#pragma once

void reserved_tap_asm();
void reserved_tap();

void reserved_stream() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("+tap"):
				reserved_tap();
				break;
			case COREFC("+debug"):
				debug_info();
				break;
			case COREFC("+stop"):
			case COREFC("+exit"):
			case COREFC("+terminate"):
				exit(42);
				break;
			//standard:
       		case COREFC("r*")://sexit
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
      		default:
        		error_stream();
        		break;
		}
	} loop;

}

void reserved_tap() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("_debug"):
				fc_getline();
				error_debug_mode = codex_get_bool(active_script[line]);
				break;
			case COREFC("_errorcap"):
				fc_getline();
				error_cap = codex_get_int64(active_script[line]);
				break;
			case COREFC("_errormsg"):
				fc_getline();
				error_trace=(error_trace+"|"codex_get_string(active_script[line]);
				break;
			case COREFC("_deprication"):
				deprications++;
				break;
			case COREFC("_errorlevel"):
				error_level++;
				break;
			case COREFC("_asm"):
				break;
			case COREFC("_ret"):
				return;
			default:
				error_stream();
				break;
		}
	} loop;
}
void reserved_tap_asm() {
	fc_getline();
	//asm(codex_get_string(active_script[line]).c_str());
}
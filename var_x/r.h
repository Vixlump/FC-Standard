#pragma once
#define FCS_R
void reserved_tap_threading();
void reserved_tap_asm();
void reserved_tap();
void reserved_shell();

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
        		error_stream("*r->*error");
        		break;
		}
	} loop;

}

void reserved_tap() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("_threading"):
				reserved_tap_threading();
				break;
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
				error_trace=(error_trace+"|"+codex_get_string(active_script[line]));
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
				error_stream("+tap->*error");
				break;
		}
	} loop;
}
void reserved_tap_asm() {
	fc_getline();
	//asm(codex_get_string(active_script[line]).c_str());
}
void reserved_tap_threading() {
	fc_getline();
	bool i = codex_get_bool(active_script[line]);
	fc_getline();
	fc_getline();
	switch (active_script[line-1]) {
		case COREFC("_known_threads"):
			{
				if (i = true) {known_threads = codex_get_hash(active_script[line]);} else {codex_store_hash(active_script[line], known_threads);}
				break;
			}
		case COREFC("_adapted_threads"):
			{
				if (i = true) {adapted_threads = codex_get_hash(active_script[line]);} else {codex_store_hash(active_script[line], adapted_threads);}
				break;
		}
		case COREFC("_thread_label"):
			{
				if (i = true) {thread_label = codex_get_hash(active_script[line]);} else {codex_store_hash(active_script[line], thread_label);}
				break;
			}
		default:
			error_stream("+tap->_threading->*error");
			break;
	}
}
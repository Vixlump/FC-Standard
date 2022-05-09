#pragma once
#define FCS_X

void xternal_file();
void xternal_address();

void xternal_stream() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("+file"):
				xternal_file();
				break;
			case COREFC("+address"):
				xternal_address();
				break;
			case COREFC("+python"):
				break;
			case COREFC("+shell"):
				fc_getline();
				codex_store_int32(COREFC("_shell"), system(codex_get_string(active_script[line]).c_str()));
				break;
			//standard:
       		case COREFC("x*")://sexit
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

void xternal_file_open() {
	fc_getline();
	switch (active_script[line]) {
		case COREFC("_chart"):
			fc_getline();
			fc_getline();
			chart_var[active_script[line-1]].open(codex_get_string(active_script[line]));
			break;
		case COREFC("_quantum"):
			fc_getline();
			fc_getline();
			quantum_var[active_script[line-1]].open(codex_get_string(active_script[line]));
			break;
		case COREFC("_array"):
			{
				fc_getline();
				if (active_script[line]==COREFC("_chart")) {
					fc_getline();
					fc_getline();
					fc_getline();
					//chart_var_array[active_script[line-2]][codex_get_int64(active_script[line-1])].open(active_script[line]);
					break;
				} else if (active_script[line]==COREFC("_quantum")) {
					fc_getline();
					fc_getline();
					fc_getline();
					//quantum_var_array[active_script[line-2]][codex_get_int64(active_script[line-1])].open(active_script[line]);
					break;
				} else {
					error_stream();
				}
				break;
			}
		default:
			error_stream();
			break;
	}
}
void xternal_file_close() {
	fc_getline();
	switch (active_script[line]) {
		case COREFC("_chart"):
			fc_getline();
			chart_var[active_script[line]].close();
			break;
		case COREFC("_quantum"):
			fc_getline();
			quantum_var[active_script[line]].close();
			break;
		default:
			error_stream();
			break;
	}
}
void xternal_file_write() {
	fc_getline();
	uint64_t name = active_script[line];
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_text"):
				fc_getline();
				quantum_var[name]<<codex_get_string(active_script[line]);
				break;
			case COREFC("_end"):
				quantum_var[name]<<endl;
				break;
			case COREFC("_break"):
				quantum_var[name]<<"\n";
				break;
			case COREFC("_ret"):
				return;
			case COREFC("_line"):
			default:
				fc_getline();
				quantum_var[name]<<codex_get_string(active_script[line])<<"\n";
				break;
		}
	} loop;
}
void xternal_file_read() {
	fc_getline();
	uint64_t name = active_script[line];
	fc_getline();
	switch (active_script[line]) {
		case COREFC("_line"):
			{
				string i;
				getline(chart_var[name], i);
				fc_getline();
				codex_store_string(active_script[line], i);
			}
			break;
		case COREFC("_all"):

			break;
		default:
			break;
	}
}
void xternal_file() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_read"):
				xternal_file_read();
				break;
			case COREFC("_write"):
				xternal_file_write();
				break;
			case COREFC("_open"):
				xternal_file_open();
				break;
			case COREFC("_close"):
				xternal_file_close();
				break;
			case COREFC("_ret"):
				return;
			default:
				error_stream();
				break;
		}
	} loop;
}

void xternal_address() {

}
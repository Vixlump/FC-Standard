#pragma once
#define FCS_T
void threading_thread();
void threading_unite();
void threading_detach();
void threading_adapt();
void threading_multi();
vector <thread> var_thread;

void threading_stream() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("+thread"):
				break;
			case COREFC("+unite"):
				break;
			case COREFC("+detach"):
				break;
			case COREFC("+adapt"):
				break;
			case COREFC("+multi"):
				break;
			//standard:
       		case COREFC("t*")://sexit
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

void threading_thread_new(vector <uint64_t> input) {
	thread_label = known_threads-1;
	line = phantom_line;
	active_script = input;
	scan_stream();
	known_threads--;
}

void threading_thread() {
	vector <uint64_t> input;
	bool i = true;
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("//T"):
				i = false;
				break;
			default:
				input.push_back(active_script[line]);
				break;
		}
	} while(i==true);
	adapted_threads++;
	known_threads++;
	var_thread.push_back(threading_thread_new, input);
}
void threading_unite() {

}
void threading_detach() {
	fc_getline();
	uint64_t i = codex_get_hash(active_script[line]);
	var_thread[i].detach();
}
void threading_adapt() {
	fc_getline();
	uint64_t i = codex_get_hash(active_script[line]);
	var_thread[i].join();
	var_thread.erase(var_thread.begin()+i);
}
void threading_multi() {

}
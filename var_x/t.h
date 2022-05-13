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
				threading_thread();
				break;
			case COREFC("+unite"):
				threading_unite();
				break;
			case COREFC("+detach"):
				threading_detach();
				break;
			case COREFC("+adapt"):
				threading_adapt();
				break;
			case COREFC("+multi"):
				threading_multi();
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
				error_stream("*t->*error");
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
	var_thread.push_back(thread(threading_thread_new, input));
}
void threading_unite() {

}
void threading_detach() {
	fc_getline();
	uint64_t i = codex_get_hash(active_script[line]);
	if (i == 0ull) {cout<<"Main Thread Is Unmaintained, Program Will Terminate\n";exit(42);}
	var_thread[i-1ull].detach();
}
void threading_adapt() {
	fc_getline();
	uint64_t i = codex_get_hash(active_script[line]);
	if (i == 0ull) {cout<<"Main Thread Was Adapted Into The Ether, Program Will Terminate\n";exit(42);}
	var_thread[i-1ull].join();
	var_thread.erase(var_thread.begin()+(i-1ull));
}
void threading_multi() {

}
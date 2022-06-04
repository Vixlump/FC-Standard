#pragma once
#define FCS_O

void optimization_order();
void optimization_protect();
void optimization_blotch();
void optimization_swap();

void optimization_stream() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("+order"):
				optimization_order();
				break;
			case COREFC("+protect"):
				optimization_protect();
				break;
			case COREFC("+blotch"):
				optimization_blotch();
				break;
			case COREFC("+swap@"):
				optimization_swap();
				break;
			//standard:
      		case COREFC("o*")://sexit
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
			default:
				error_stream("*o->*error");
				break;
		}
	} loop;
}

void optimization_order() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_memory")://all or simply prioritize single value
				break;
			case COREFC("_assignments"):
				break;
			case COREFC("_functions"):
				break;
			case COREFC("_ret"):
				return;
			default:
				error_stream("+order->*error");
				break;
		}
	} loop;
}
void optimization_protect() {
	fc_getline();
	switch (active_script[line]) {//define value that cannot be effected by optimizations
		case COREFC("_init"):
			break;
		case COREFC("_enforce"):
			break;
		default:
			error_stream("+protect->*error");
			break;
	}
}

void optimization_blotch_token(uint64_t token) {
	uint64_t i_total = active_script.size();
	for (uint64_t i = 0; i < i_total; i++) {
		if (active_script[i]==token) {
			active_script.erase(active_script.begin()+i);
			if (i<line) {line--;}
			i_total--;
			continue;
		} else {
			continue;
		}
	}
}


void optimization_blotch_duplicates_memory() {//_all (remove all memory duplicates),_type(remove all duplicates of var type):_specific(remove duplicate of type by name),_specificall (remove duplicate specific name of all types)

}
void optimization_blotch_duplicates_assignments() {

}
void optimization_blotch_duplicates_assignmentsfunctional() {///

}
void optimization_blotch_duplicates_functions() {

}
void optimization_blotch_duplicates() {//_memory

}
void optimization_blotch() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_whitespace"):
				optimization_blotch_token(COREFC(""));
				break;
			case COREFC("_debugpoints"):
				optimization_blotch_token(COREFC("**"));
				break;
			case COREFC("_custom"):
				{
					fc_getline();
					if (active_script[line]==COREFC("_string")) {
							fc_getline();
							string i = codex_get_string(active_script[line]);
							optimization_blotch_token(COREFC(i.c_str()));
					} else if (active_script[line]==COREFC("_hash")) {
							fc_getline();
							optimization_blotch_token(codex_get_hash(active_script[line]));
					}
					break;
				}
			case COREFC("_duplicates")://removes duplicate functions and assignment points and memory adresses subcommands _memory, _assigments, _functions, _@assignments
				optimization_blotch_duplicates();
				break;
			case COREFC("_ret"):
				return;
			default:
				error_stream("+blotch->*error");
				break;
		}
	} loop;
}
void optimization_swap() {

}
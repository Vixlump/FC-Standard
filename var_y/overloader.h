#pragma once
#define ACTION_OVERLOAD_OWNER active_script_bak[active_script_bak.size()-1].script[line_bak[line_bak.size()-1]]
void action_overloading_argument() {

}
void action_overloading_case() {

}
void action_overloading_fcload() {
	line_bak[line_bak.size()-1]++;
}
void action_overloading_escape() {
	fc_getline();
	if (ACTION_OVERLOAD_OWNER==COREFC("~~~*")||ACTION_OVERLOAD_OWNER==active_script[line]) {
		fc_getline();
		line = codex_get_assignment(active_script[line]);
	} else {
		fc_getline();
	}
}
void action_overloading_whitespace() {
	fc_getline();
	if (ACTION_OVERLOAD_OWNER==COREFC("")) {
		line = codex_get_assignment(active_script[line]);
	}
}
enum actiontype {
	action_hash,
	action_int64,
	action_int32,
	action_int16,
	action_int8,
	action_float,
	action_double,
	action_triple,
	action_bool,
	action_string
};
thread_local uint16_t action_flag = actiontype::action_hash;
void action_overloading_flag() {
	fc_getline();
	switch (active_script[line]) {
		case COREFC("+hash"):
		case COREFC("+action"):
			action_flag = actiontype::action_hash;
			break;
		case COREFC("+int"):
		case COREFC("+int64"):
			action_flag = actiontype::action_int64;
			break;
		case COREFC("+int32"):
			action_flag = actiontype::action_int32;
			break;
		case COREFC("+int16"):
			action_flag = actiontype::action_int16;
			break;
		case COREFC("+int8"):
			action_flag = actiontype::action_int8;
			break;
		case COREFC("+float"):
			action_flag = actiontype::action_float;
			break;
		case COREFC("+double"):
			action_flag = actiontype::action_double;
			break;
		case COREFC("+triple"):
			action_flag = actiontype::action_triple;
			break;
		case COREFC("+string"):
			action_flag = actiontype::action_string;
			break;
		default:
			line--;
			action_flag = actiontype::action_hash;
			break;
	}
}
void action_overloading_stream() {
	bool action_loop = false;
	fc_getline();
	do {
		switch(active_script[line]) {
			case COREFC("*fcload"):
				action_overloading_fcload();
				break;
			case COREFC("*action"):
				action_overloading_argument();
				break;
			case COREFC("*case"):
				action_overloading_case();
				break;
			case COREFC("*escape"):
				action_overloading_escape();
				break;
			case COREFC("*whitespace"):
				action_overloading_whitespace();
				break;
			case COREFC("*flag"):
				action_overloading_flag();
				break;
			case COREFC("*loop"):
				action_loop = true;
				break;
			case COREFC("loop*"):
				action_loop = false;
				break;
			default:
				line--;
				break;
		}
	} while (action_loop==true);
}
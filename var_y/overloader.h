#pragma once
#define ACTION_OVERLOAD_OWNER active_script_bak[active_script_bak.size()-1].script[line_bak[line_bak.size()-1]]
thread_local uint16_t action_flag;

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

void action_overloading_case() {

}
void action_overloading_argument_var() {
	line_bak[line_bak.size()-1]++;
	uint64_t overloaded_line = ACTION_OVERLOAD_OWNER;
	fc_getline();
	switch (action_flag) {
		case actiontype::action_hash:
			codex_store_hash(active_script[line], overloaded_line);
			break;
		case actiontype::action_int64:
			codex_store_int64(active_script[line], codex_get_int64(overloaded_line));
			break;
		case actiontype::action_int32:
			codex_store_int32(active_script[line], codex_get_int32(overloaded_line));
			break;
		case actiontype::action_int16:
			codex_store_int16(active_script[line], codex_get_int16(overloaded_line));
			break;
		case actiontype::action_int8:
			codex_store_int8(active_script[line], codex_get_int8(overloaded_line));
			break;
		case actiontype::action_bool:
			codex_store_bool(active_script[line], codex_get_bool(overloaded_line));
			break;
		case actiontype::action_triple:
			codex_store_triple(active_script[line], codex_get_triple(overloaded_line));
			break;
		case actiontype::action_double:
			codex_store_double(active_script[line], codex_get_double(overloaded_line));
			break;
		case actiontype::action_float:
			codex_store_float(active_script[line], codex_get_float(overloaded_line));
			break;
		case actiontype::action_string:
			codex_store_string(active_script[line], codex_get_string(overloaded_line));
			break;
		default:
			cout<<"Warning, Ungarded Flag, Program Will Try To Terminate Safely"<<endl;
			exit(42);
	}
}
void action_overloading_argument_array() {
	line_bak[line_bak.size()-1]++;
	uint64_t overloaded_line = ACTION_OVERLOAD_OWNER;
	fc_getline();
	fc_getline();
	switch (action_flag) {
		case actiontype::action_hash:
			codex_store_hash_array(active_script[line-1], codex_get_int64(active_script[line]), overloaded_line);
			break;
		case actiontype::action_int64:
			codex_store_int64_array(active_script[line-1], codex_get_int64(active_script[line]), codex_get_int64(overloaded_line));
			break;
		case actiontype::action_int32:
			codex_store_int32_array(active_script[line-1], codex_get_int64(active_script[line]), codex_get_int32(overloaded_line));
			break;
		case actiontype::action_int16:
			codex_store_int16_array(active_script[line-1], codex_get_int64(active_script[line]), codex_get_int16(overloaded_line));
			break;
		case actiontype::action_int8:
			codex_store_int8_array(active_script[line-1], codex_get_int64(active_script[line]), codex_get_int8(overloaded_line));
			break;
		case actiontype::action_bool:
			codex_store_bool_array(active_script[line-1], codex_get_int64(active_script[line]), codex_get_bool(overloaded_line));
			break;
		case actiontype::action_triple:
			codex_store_triple_array(active_script[line-1], codex_get_int64(active_script[line]), codex_get_triple(overloaded_line));
			break;
		case actiontype::action_double:
			codex_store_double_array(active_script[line-1], codex_get_int64(active_script[line]), codex_get_double(overloaded_line));
			break;
		case actiontype::action_float:
			codex_store_float_array(active_script[line-1], codex_get_int64(active_script[line]), codex_get_float(overloaded_line));
			break;
		case actiontype::action_string:
			codex_store_string_array(active_script[line-1], codex_get_int64(active_script[line]), codex_get_string(overloaded_line));
			break;
		default:
			cout<<"Warning, Ungarded Flag, Program Will Try To Terminate Safely"<<endl;
			exit(42);
	}
}
void action_overloading_argument() {
	fc_getline();
	switch (active_script[line]) {
		case COREFC("+var"):
			action_overloading_argument_var();
			break;
		case COREFC("+array"):
			action_overloading_argument_array();
			break;
		default:
			break;
	}
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

void action_overloading_skip() {
	line_bak[line_bak.size()-1]++;
}

void action_overlaoding_purge() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("purge*"):
				return;
			default:
				for (uint64_t i = 0; i < function_assignments.size(); i++) {
					if (function_assignments[i].name==active_script[line]) {
						function_assignments.erase(function_assignments.begin()+i);
						break;
					}
				}
				break;

		}
	} loop;
}

void action_overloading_stream() {
	bool action_loop = false;
	do {
		fc_getline();
		switch(active_script[line]) {
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
			case COREFC("*skip"):
				action_overloading_skip();
				break;
			case COREFC("*flag")://define error
				action_overloading_flag();
				break;
			case COREFC("*purge"):
				action_overlaoding_purge();
				break;
			case COREFC("*loop"):
				action_loop = true;
				break;
			case COREFC("loop*"):
				action_loop = false;
				break;
			case COREFC(""): //whitespace
				break;
			default:
				line--;
				break;
		}
	} while (action_loop==true);
}
#pragma once

void control_case();
void control_if();
void control_lock();
void control_while();
void control_for();

inline void control_goto() {
	fc_getline();
	line = codex_get_assignment(active_script[line]);
}

void control_stream() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("+case"):
				control_case();
				break;
			case COREFC("+if"):
				control_if();
				break;
			case COREFC("+goto"):
				control_goto();
				break;
			case COREFC("+loop"):
				break;
			case COREFC("+while"):
				control_while();
				break;
			case COREFC("+for"):
				control_for();
				break;
			//standard:
       		case COREFC("c*")://sexit
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

template<typename T>
void control_case_check(uint64_t & name) {
	do {
		fc_getline();
		if (active_script[line]==COREFC("_ret")) {return;}
		fc_getline();
		if constexpr (is_same<T, uint64_t>::value) {
			if (codex_return_hash(name)==active_script[line-1]) {
				line = codex_get_assignment(active_script[line]);
				return;
			}
		} else if constexpr (is_same<T, int64_t>::value) {
			if (codex_return_int64(name)==codex_get_int64(active_script[line-1])) {
				line = codex_get_assignment(active_script[line]);
				return;
			}
		} else if constexpr (is_same<T, int32_t>::value) {
			if (codex_return_int32(name)==codex_get_int32(active_script[line-1])) {
				line = codex_get_assignment(active_script[line]);
				return;
			}
		} else if constexpr (is_same<T, int16_t>::value) {
			if (codex_return_int16(name)==codex_get_int16(active_script[line-1])) {
				line = codex_get_assignment(active_script[line]);
				return;
			}
		} else if constexpr (is_same<T, int8_t>::value) {
			if (codex_return_int8(name)==codex_get_int8(active_script[line-1])) {
				line = codex_get_assignment(active_script[line]);
				return;
			}
		} else if constexpr (is_same<T, bool>::value) {
			if (codex_return_bool(name)==codex_get_bool(active_script[line-1])) {
				line = codex_get_assignment(active_script[line]);
				return;
			}
		} else if constexpr (is_same<T, triple>::value) {
			if (codex_return_triple(name)==codex_get_triple(active_script[line-1])) {
				line = codex_get_assignment(active_script[line]);
				return;
			}
		} else if constexpr (is_same<T, double>::value) {
			if (codex_return_double(name)==codex_get_double(active_script[line-1])) {
				line = codex_get_assignment(active_script[line]);
				return;
			}
		} else if constexpr (is_same<T, float>::value) {
			if (codex_return_float(name)==codex_get_float(active_script[line-1])) {
				line = codex_get_assignment(active_script[line]);
				return;
			}
		} else if constexpr (is_same<T, string>::value) {
			if (codex_return_string(name)==codex_get_string(active_script[line-1])) {
				line = codex_get_assignment(active_script[line]);
				return;
			}
		}
	} loop;
}

void control_case() {
	fc_getline();
	fc_getline();
	switch(active_script[line-1]) {
		case COREFC("_hash"):
			control_case_check<uint64_t>(active_script[line]);
			break;
		case COREFC("_int"):
		case COREFC("_int64"):
			control_case_check<int64_t>(active_script[line]);
			break;
		case COREFC("_int32"):
			control_case_check<int32_t>(active_script[line]);
			break;
		case COREFC("_int16"):
			control_case_check<int16_t>(active_script[line]);
			break;
		case COREFC("_int8"):
			control_case_check<int8_t>(active_script[line]);
			break;
		case COREFC("_bool"):
			control_case_check<bool>(active_script[line]);
			break;
		case COREFC("_triple"):
			control_case_check<triple>(active_script[line]);
			break;
		case COREFC("_double"):
			control_case_check<double>(active_script[line]);
			break;
		case COREFC("_float"):
			control_case_check<float>(active_script[line]);
			break;
		case COREFC("_string"):
			control_case_check<string>(active_script[line]);
			break;
		case COREFC("_array"):
		default:
			error_stream();
			break;
	}
}
void control_if() {

}
void control_lock() {

}
void control_while() {

}
void control_for() {
	
}
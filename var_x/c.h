#pragma once
#define FCS_C

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
        	case COREFC("*null")://do nothing
          		fc_nothing();
          		break;
        	case COREFC("*~~~")://channelswap stream
          		channelswap_stream();
          		break;
      		default:
        		error_stream("*c->*error");
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
			error_stream("+case->*error");
			break;
	}
}

template<typename T>
bool control_if_equ(T input1, T input2) {//==
	if (input1 == input2) {return true;} else {return false;}
}
template<typename T>
bool control_if_not(T input1, T input2) {//!=
	if (input1 != input2) {return true;} else {return false;}
}
template<typename T>
bool control_if_greater(T input1, T input2) {//>
	if (input1 > input2) {return true;} else {return false;}
}
template<typename T>
bool control_if_less(T input1, T input2) {//<
	if (input1 < input2) {return true;} else {return false;}
}
template<typename T>
bool control_if_greaterequ(T input1, T input2) {//>=
	if (input1 >= input2) {return true;} else {return false;}
}
template<typename T>
bool control_if_lessequ(T input1, T input2) {//<=
	if (input1 <= input2) {return true;} else {return false;}	
}
template<typename T>
bool control_if_spaceship(T input1, T input2) {//<=>
	if (input1 == input2 || input1 < input2 || input1 > input2) {return true;} else {return false;}
}
template <typename T>
void control_if_selector(T input1, uint64_t input2, T input3, vector <bool> & control_if_result) {
		uint16_t control_if_decision = 0;
		switch (input2) {
			case COREFC("=="):
				control_if_result.push_back(control_if_equ<T>(input1, input3));
				break;
			case COREFC("<"):
				control_if_result.push_back(control_if_less<T>(input1, input3));
				break;
			case COREFC(">"):
				control_if_result.push_back(control_if_greater<T>(input1, input3));
				break;
			case COREFC("!="):
				control_if_result.push_back(control_if_not<T>(input1, input3));
				break;
			case COREFC(">="):
				control_if_result.push_back(control_if_greaterequ<T>(input1, input3));
				break;
			case COREFC("<="):
				control_if_result.push_back(control_if_lessequ<T>(input1, input3));
				break;
			case COREFC("<=>"):
				control_if_result.push_back(control_if_spaceship<T>(input1, input3));
				break;
			default:
				error_stream("+if->*error");
				break;
		}
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_do"):
				{
					bool control_if_willsucseed = false;
					for (uint64_t i = 0; i < control_if_result.size(); i++) {
						switch (control_if_decision) {
							case 0:
								break;
							case 1:
								break;
							case 2:
								break;
							case 3:
								break;
							case 4:
								break;
							case 5:
								break;
							default:
								error_stream("+if->*error");
								break;
						}
					}
					if (control_if_willsucseed == true) {
						control_goto();
					} else {
						fc_getline();
					}
					return;
				}
			case COREFC("_and"):
				control_if_decision = 0;
				break;
			case COREFC("_or"):
				control_if_decision = 1;
				break;
			case COREFC("_xor"):
				control_if_decision = 2;
				break;
			case COREFC("_nand"):
				control_if_decision = 3;
				break;
			case COREFC("_nor"):
				control_if_decision = 4;
				break;
			case COREFC("_xnor"):
				control_if_decision = 5;
				break;
			default:
				error_stream("+if->*error");
				break;
		}
}
void control_if() { //c#+if|_int|n#64|==|n#64|go here|else continue
	vector <bool> control_if_result;
	fc_getline();
 	uint64_t control_if_type = active_script[line];
 	do {
	 	fc_getline();
		fc_getline();
		fc_getline();
	 	switch(control_if_type) {
	 		case COREFC("_int"):
	 		case COREFC("_int64"):
	 			control_if_selector<int64_t>(codex_get_int64(active_script[line-2]), active_script[line-1], codex_get_int64(active_script[line]), control_if_result);
	 			break;
	 		case COREFC("_int32"):
	 			control_if_selector<int32_t>(codex_get_int32(active_script[line-2]), active_script[line-1], codex_get_int32(active_script[line]), control_if_result);
	 			break;
	 		case COREFC("_int16"):
	 			control_if_selector<int16_t>(codex_get_int16(active_script[line-2]), active_script[line-1], codex_get_int16(active_script[line]), control_if_result);
	 			break;
	 		case COREFC("_int8"):
	 			control_if_selector<int8_t>(codex_get_int8(active_script[line-2]), active_script[line-1], codex_get_int8(active_script[line]), control_if_result);
	 			break;
	 		case COREFC("_bool"):
	 			control_if_selector<bool>(codex_get_bool(active_script[line-2]), active_script[line-1], codex_get_bool(active_script[line]), control_if_result);
	 			break;
	 		case COREFC("_triple"):
	 			control_if_selector<triple>(codex_get_triple(active_script[line-2]), active_script[line-1], codex_get_triple(active_script[line]), control_if_result);
	 			break;
	 		case COREFC("_double"):
	 			control_if_selector<double>(codex_get_double(active_script[line-2]), active_script[line-1], codex_get_double(active_script[line]), control_if_result);
	 			break;
	 		case COREFC("_float"):
	 			control_if_selector<float>(codex_get_float(active_script[line-2]), active_script[line-1], codex_get_float(active_script[line]), control_if_result);
	 			break;
	 		case COREFC("_string"):
	 			control_if_selector<string>(codex_get_string(active_script[line-2]), active_script[line-1], codex_get_string(active_script[line]), control_if_result);
	 			break;
	 		case COREFC("_hash"):
	 			control_if_selector<uint64_t>(active_script[line-2], active_script[line-1], active_script[line], control_if_result);
	 			break;
	 		default:
	 			error_stream("+if->*error");
				break;
	 	}
 	} loop;
}
void control_lock() {

}
void control_while() {

}
void control_for() {
	
}
#pragma once
#define FCS_M

enum mathstream {
	madd,
	msub,
	mmul,
	mdiv,
	mmod,
	mpow,
	mlog,
	mroot
};

void math_function();
void math_graph();
void math_cal();
void math_random();
void math_set();

void math_stream() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("+fun"):
			case COREFC("+function")://solves for one values
				math_function();
				break;
			case COREFC("+graph")://solves for multiple values
				math_graph();
				break;
			case COREFC("+cal"):
			case COREFC("+calculate")://preforms one mathematical function
				math_cal();
				break;
			case COREFC("+random"):
				math_random();
				break;
			case COREFC("+set")://round, floor, ceil, trunc
				math_set();
				break;
			//standard:
       		case COREFC("m*")://sexit
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
        		error_stream("*m->*error");
        		break;
        }
	} loop;
}

template <typename T>
void math_function_define(vector<T> & i, uint16_t vartype) {
	exprtk::symbol_table<T> math_symbol_table;
	string mathdefstring = "";
	for (uint64_t i2 = 0; i2 < i.size(); i2++) {
		mathdefstring = "x" + to_string(i2);
		math_symbol_table.add_variable(mathdefstring, i[i2]);
	}
	math_symbol_table.add_constants();

	string math_parcer_string = "";
	fc_getline();
	math_parcer_string = codex_get_string(active_script[line]);
	exprtk::expression<T> math_expression;
	math_expression.register_symbol_table(math_symbol_table);
	exprtk::parser<T> math_parser;
	math_parser.compile(math_parcer_string, math_expression);
	fc_getline();
	switch(vartype) {
		case actiontype::action_triple:
			codex_store_triple(active_script[line], math_expression.value());
			break;
		case actiontype::action_double:
			codex_store_double(active_script[line], math_expression.value());
			break;
		case actiontype::action_float:
			codex_store_float(active_script[line], math_expression.value());
			break;
		case actiontype::action_int64:
			codex_store_int64(active_script[line], static_cast<int64_t>(math_expression.value()));
			break;
		case actiontype::action_int32:
			codex_store_int32(active_script[line], static_cast<int32_t>(math_expression.value()));
			break;
		case actiontype::action_int16:
			codex_store_int16(active_script[line], static_cast<int16_t>(math_expression.value()));
			break;
		case actiontype::action_int8:
			codex_store_int8(active_script[line], static_cast<int8_t>(math_expression.value()));
			break;
		case actiontype::action_hash:
			codex_store_hash(active_script[line], static_cast<uint64_t>(math_expression.value()));
			break;
		default:
			error_stream("+function->_var->*error");
			break;
	}
}

void math_function() {
	//select type
	fc_getline();
	uint16_t math_var_type;
	switch (active_script[line]) {
		case COREFC("_triple"):
			{
				vector <triple> i_triple;
				math_var_type = actiontype::action_triple;
				do {fc_getline();
					if (active_script[line]==COREFC("_begin")) {break;}
					i_triple.push_back(codex_get_triple(active_script[line]));
				} loop;
				math_function_define<triple>(i_triple, math_var_type);
				break;
			}
		case COREFC("_double"):
			{
				vector <double> i_double;
				math_var_type = actiontype::action_double;
				do {fc_getline();
					if (active_script[line]==COREFC("_begin")) {break;}
					i_double.push_back(codex_get_double(active_script[line]));
				} loop;
				math_function_define<double>(i_double, math_var_type);
				break;
			}
		case COREFC("_float"):
			{
				vector <float> i_float;
				math_var_type = actiontype::action_float;
				do {fc_getline();
					if (active_script[line]==COREFC("_begin")) {break;}
					i_float.push_back(codex_get_float(active_script[line]));
				} loop;
				math_function_define<float>(i_float, math_var_type);
				break;
			}
		case COREFC("_hash"):
			{
				vector <triple> i_hash;
				math_var_type = actiontype::action_hash;
				do {fc_getline();
					if (active_script[line]==COREFC("_begin")) {break;}
					i_hash.push_back(static_cast<triple>(codex_get_hash(active_script[line])));
				} loop;
				math_function_define<triple>(i_hash, math_var_type);
				break;
			}
		case COREFC("_int"):
		case COREFC("_int64"):
			{
				vector <triple> i_int64;
				math_var_type = actiontype::action_int64;
				do {fc_getline();
					if (active_script[line]==COREFC("_begin")) {break;}
					i_int64.push_back(static_cast<triple>(codex_get_int64(active_script[line])));
				} loop;
				math_function_define<triple>(i_int64, math_var_type);
				break;
			}
		case COREFC("_int32"):
			{
				vector <triple> i_int32;
				math_var_type = actiontype::action_int32;
				do {fc_getline();
					if (active_script[line]==COREFC("_begin")) {break;}
					i_int32.push_back(static_cast<triple>(codex_get_int32(active_script[line])));
				} loop;
				math_function_define<triple>(i_int32, math_var_type);
				break;
			}
		case COREFC("_int16"):
			{
				vector <triple> i_int16;
				math_var_type = actiontype::action_int16;
				do {fc_getline();
					if (active_script[line]==COREFC("_begin")) {break;}
					i_int16.push_back(static_cast<triple>(codex_get_int16(active_script[line])));
				} loop;
				math_function_define<triple>(i_int16, math_var_type);
				break;
			}
		case COREFC("_int8"):
			{
				vector <triple> i_int8;
				math_var_type = actiontype::action_int8;
				do {fc_getline();
					if (active_script[line]==COREFC("_begin")) {break;}
					i_int8.push_back(static_cast<triple>(codex_get_int8(active_script[line])));
				} loop;
				math_function_define<triple>(i_int8, math_var_type);
				break;
			}
		default:
			error_stream("+function->*error");
			break;
	}
}

void math_random_gen() {

}
void math_random_alt() {

}
void math_random_noise() {

}
void math_random_range() {

}


void math_random() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_gen"):
				break;
			case COREFC("_alt"):
				break;
			case COREFC("_noise"):
				break;
			case COREFC("_range"):
				break;
			case COREFC("_ret"):
				return;
			default:
				error_stream("+random->*error");
				break;
		}
	} loop;
}

void math_graph() {

}

template <typename T>
T math_cal_return(T input) {
	fc_getline();
	switch (active_script[line]) {
		case COREFC("+"):
			fc_getline();
			if constexpr (is_same<T, int64_t>::value) {
				return input + codex_get_int64(active_script[line]);
			} else if constexpr (is_same<T, int32_t>::value) {
				return input + codex_get_int32(active_script[line]);
			} else if constexpr (is_same<T, int16_t>::value) {
				return input + codex_get_int16(active_script[line]);
			} else if constexpr (is_same<T, int8_t>::value) {
				return input + codex_get_int8(active_script[line]);
			} else if constexpr (is_same<T, bool>::value) {
				return input + codex_get_bool(active_script[line]);
			} else if constexpr (is_same<T, triple>::value) {
				return input + codex_get_triple(active_script[line]);
			} else if constexpr (is_same<T, double>::value) {
				return input + codex_get_double(active_script[line]);
			} else if constexpr (is_same<T, float>::value) {
				return input + codex_get_float(active_script[line]);
			} else if constexpr (is_same<T, string>::value) {
				return input + codex_get_string(active_script[line]);
			} else if constexpr (is_same<T, uint64_t>::value) {
				return input + codex_get_hash(active_script[line]);
			}
			break;
		case COREFC("-"):
			fc_getline();
			if constexpr (is_same<T, int64_t>::value) {
				return input - codex_get_int64(active_script[line]);
			} else if constexpr (is_same<T, int32_t>::value) {
				return input - codex_get_int32(active_script[line]);
			} else if constexpr (is_same<T, int16_t>::value) {
				return input - codex_get_int16(active_script[line]);
			} else if constexpr (is_same<T, int8_t>::value) {
				return input - codex_get_int8(active_script[line]);
			} else if constexpr (is_same<T, bool>::value) {
				return input - codex_get_bool(active_script[line]);
			} else if constexpr (is_same<T, triple>::value) {
				return input - codex_get_triple(active_script[line]);
			} else if constexpr (is_same<T, double>::value) {
				return input - codex_get_double(active_script[line]);
			} else if constexpr (is_same<T, float>::value) {
				return input - codex_get_float(active_script[line]);
			} else if constexpr (is_same<T, uint64_t>::value) {
				return input - codex_get_hash(active_script[line]);
			}
			break;
		case COREFC("*"):
			fc_getline();
			if constexpr (is_same<T, int64_t>::value) {
				return input * codex_get_int64(active_script[line]);
			} else if constexpr (is_same<T, int32_t>::value) {
				return input * codex_get_int32(active_script[line]);
			} else if constexpr (is_same<T, int16_t>::value) {
				return input * codex_get_int16(active_script[line]);
			} else if constexpr (is_same<T, int8_t>::value) {
				return input * codex_get_int8(active_script[line]);
			} else if constexpr (is_same<T, bool>::value) {
				return input * codex_get_bool(active_script[line]);
			} else if constexpr (is_same<T, triple>::value) {
				return input * codex_get_triple(active_script[line]);
			} else if constexpr (is_same<T, double>::value) {
				return input * codex_get_double(active_script[line]);
			} else if constexpr (is_same<T, float>::value) {
				return input * codex_get_float(active_script[line]);
			} else if constexpr (is_same<T, uint64_t>::value) {
				return input * codex_get_hash(active_script[line]);
			}
			break;
		case COREFC("/"):
			fc_getline();
			if constexpr (is_same<T, int64_t>::value) {
				return input / codex_get_int64(active_script[line]);
			} else if constexpr (is_same<T, int32_t>::value) {
				return input / codex_get_int32(active_script[line]);
			} else if constexpr (is_same<T, int16_t>::value) {
				return input / codex_get_int16(active_script[line]);
			} else if constexpr (is_same<T, int8_t>::value) {
				return input / codex_get_int8(active_script[line]);
			} else if constexpr (is_same<T, bool>::value) {
				return input / codex_get_bool(active_script[line]);
			} else if constexpr (is_same<T, triple>::value) {
				return input / codex_get_triple(active_script[line]);
			} else if constexpr (is_same<T, double>::value) {
				return input / codex_get_double(active_script[line]);
			} else if constexpr (is_same<T, float>::value) {
				return input / codex_get_float(active_script[line]);
			} else if constexpr (is_same<T, uint64_t>::value) {
				return input / codex_get_hash(active_script[line]);
			}
			break;
		case COREFC("^"):
			fc_getline();
			if constexpr (is_same<T, int64_t>::value) {
				return pow(input, codex_get_int64(active_script[line]));
			} else if constexpr (is_same<T, int32_t>::value) {
				return pow(input, codex_get_int32(active_script[line]));
			} else if constexpr (is_same<T, int16_t>::value) {
				return pow(input, codex_get_int16(active_script[line]));
			} else if constexpr (is_same<T, int8_t>::value) {
				return pow(input, codex_get_int8(active_script[line]));
			} else if constexpr (is_same<T, bool>::value) {
				return pow(input, codex_get_bool(active_script[line]));
			} else if constexpr (is_same<T, triple>::value) {
				return pow(input, codex_get_triple(active_script[line]));
			} else if constexpr (is_same<T, double>::value) {
				return pow(input, codex_get_double(active_script[line]));
			} else if constexpr (is_same<T, float>::value) {
				return pow(input, codex_get_float(active_script[line]));
			} else if constexpr (is_same<T, uint64_t>::value) {
				return pow(input, codex_get_hash(active_script[line]));
			}
			break;
		case COREFC("%"):
			fc_getline();
			if constexpr (is_same<T, int64_t>::value) {
				return input % codex_get_int64(active_script[line]);
			} else if constexpr (is_same<T, int32_t>::value) {
				return input % codex_get_int32(active_script[line]);
			} else if constexpr (is_same<T, int16_t>::value) {
				return input % codex_get_int16(active_script[line]);
			} else if constexpr (is_same<T, int8_t>::value) {
				return input % codex_get_int8(active_script[line]);
			} else if constexpr (is_same<T, bool>::value) {
				return input % codex_get_bool(active_script[line]);
			} else if constexpr (is_same<T, uint64_t>::value) {
				return input % codex_get_hash(active_script[line]);
			}
			break;
		case COREFC("++"):
			if constexpr (is_same<T, int64_t>::value) {
				return input++;
			} else if constexpr (is_same<T, int32_t>::value) {
				return input++;
			} else if constexpr (is_same<T, int16_t>::value) {
				return input++;
			} else if constexpr (is_same<T, int8_t>::value) {
				return input++;
			} else if constexpr (is_same<T, bool>::value) {
				return !input;
			} else if constexpr (is_same<T, triple>::value) {
				return input + 1.0;
			} else if constexpr (is_same<T, double>::value) {
				return input + 1.0;
			} else if constexpr (is_same<T, float>::value) {
				return input + 1.0;
			} else if constexpr (is_same<T, uint64_t>::value) {
				return input++;
			}
			break;
		case COREFC("--"):
			if constexpr (is_same<T, int64_t>::value) {
				return input--;
			} else if constexpr (is_same<T, int32_t>::value) {
				return input--;
			} else if constexpr (is_same<T, int16_t>::value) {
				return input--;
			} else if constexpr (is_same<T, int8_t>::value) {
				return input--;
			} else if constexpr (is_same<T, bool>::value) {
				return !input;
			} else if constexpr (is_same<T, triple>::value) {
				return input - 1.0;
			} else if constexpr (is_same<T, double>::value) {
				return input - 1.0;
			} else if constexpr (is_same<T, float>::value) {
				return input - 1.0;
			} else if constexpr (is_same<T, uint64_t>::value) {
				return input--;
			}
			break;
		case COREFC("_log"):
			if constexpr (is_same<T, int64_t>::value) {
				return log(input);
			} else if constexpr (is_same<T, int32_t>::value) {
				return log(input);
			} else if constexpr (is_same<T, int16_t>::value) {
				return log(input);
			} else if constexpr (is_same<T, int8_t>::value) {
				return log(input);
			} else if constexpr (is_same<T, bool>::value) {
				return log(input);
			} else if constexpr (is_same<T, triple>::value) {
				return log(input);
			} else if constexpr (is_same<T, double>::value) {
				return log(input);
			} else if constexpr (is_same<T, float>::value) {
				return log(input);
			} else if constexpr (is_same<T, uint64_t>::value) {
				return log(input);
			}
			break;
		case COREFC("_sqrt"):
			if constexpr (is_same<T, int64_t>::value) {
				return sqrt(input);
			} else if constexpr (is_same<T, int32_t>::value) {
				return sqrt(input);
			} else if constexpr (is_same<T, int16_t>::value) {
				return sqrt(input);
			} else if constexpr (is_same<T, int8_t>::value) {
				return sqrt(input);
			} else if constexpr (is_same<T, bool>::value) {
				return sqrt(input);
			} else if constexpr (is_same<T, triple>::value) {
				return sqrt(input);
			} else if constexpr (is_same<T, double>::value) {
				return sqrt(input);
			} else if constexpr (is_same<T, float>::value) {
				return sqrt(input);
			} else if constexpr (is_same<T, uint64_t>::value) {
				return sqrt(input);
			}
			break;
		case COREFC("_cbrt"):
			if constexpr (is_same<T, int64_t>::value) {
				return cbrt(input);
			} else if constexpr (is_same<T, int32_t>::value) {
				return cbrt(input);
			} else if constexpr (is_same<T, int16_t>::value) {
				return cbrt(input);
			} else if constexpr (is_same<T, int8_t>::value) {
				return cbrt(input);
			} else if constexpr (is_same<T, bool>::value) {
				return cbrt(input);
			} else if constexpr (is_same<T, triple>::value) {
				return cbrt(input);
			} else if constexpr (is_same<T, double>::value) {
				return cbrt(input);
			} else if constexpr (is_same<T, float>::value) {
				return cbrt(input);
			} else if constexpr (is_same<T, uint64_t>::value) {
				return cbrt(input);
			}
			break;
		case COREFC("_cos"):
			if constexpr (is_same<T, int64_t>::value) {
				return cos(input);
			} else if constexpr (is_same<T, int32_t>::value) {
				return cos(input);
			} else if constexpr (is_same<T, int16_t>::value) {
				return cos(input);
			} else if constexpr (is_same<T, int8_t>::value) {
				return cos(input);
			} else if constexpr (is_same<T, bool>::value) {
				return cos(input);
			} else if constexpr (is_same<T, triple>::value) {
				return cos(input);
			} else if constexpr (is_same<T, double>::value) {
				return cos(input);
			} else if constexpr (is_same<T, float>::value) {
				return cos(input);
			} else if constexpr (is_same<T, uint64_t>::value) {
				return cos(input);
			}
			break;
		case COREFC("_sin"):
			if constexpr (is_same<T, int64_t>::value) {
				return sin(input);
			} else if constexpr (is_same<T, int32_t>::value) {
				return sin(input);
			} else if constexpr (is_same<T, int16_t>::value) {
				return sin(input);
			} else if constexpr (is_same<T, int8_t>::value) {
				return sin(input);
			} else if constexpr (is_same<T, bool>::value) {
				return sin(input);
			} else if constexpr (is_same<T, triple>::value) {
				return sin(input);
			} else if constexpr (is_same<T, double>::value) {
				return sin(input);
			} else if constexpr (is_same<T, float>::value) {
				return sin(input);
			} else if constexpr (is_same<T, uint64_t>::value) {
				return sin(input);
			}
			break;
		case COREFC("_tan"):
			if constexpr (is_same<T, int64_t>::value) {
				return tan(input);
			} else if constexpr (is_same<T, int32_t>::value) {
				return tan(input);
			} else if constexpr (is_same<T, int16_t>::value) {
				return tan(input);
			} else if constexpr (is_same<T, int8_t>::value) {
				return tan(input);
			} else if constexpr (is_same<T, bool>::value) {
				return tan(input);
			} else if constexpr (is_same<T, triple>::value) {
				return tan(input);
			} else if constexpr (is_same<T, double>::value) {
				return tan(input);
			} else if constexpr (is_same<T, float>::value) {
				return tan(input);
			} else if constexpr (is_same<T, uint64_t>::value) {
				return tan(input);
			}
			break;
		default:
			error_stream("+cal->_var->*error");
			break;
	}
	error_stream("+cal->_var->*error");
	return 0;
}

void math_cal() {
	uint64_t input;
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("_int"):
			case COREFC("_int64"):
				fc_getline();
				input = active_script[line];
				codex_store_int64(input, math_cal_return<int64_t>(codex_get_int64(input)));
				break;
			case COREFC("_hash"):
				fc_getline();
				input = active_script[line];
				codex_store_hash(input, math_cal_return<uint64_t>(codex_get_hash(input)));
				break;
			case COREFC("_int32"):
				fc_getline();
				input = active_script[line];
				codex_store_int32(input, math_cal_return<int32_t>(codex_get_int32(input)));
				break;
			case COREFC("_int16"):
				fc_getline();
				input = active_script[line];
				codex_store_int16(input, math_cal_return<int16_t>(codex_get_int16(input)));
				break;
			case COREFC("_int8"):
				fc_getline();
				input = active_script[line];
				codex_store_int8(input, math_cal_return<int8_t>(codex_get_int8(input)));
				break;
			case COREFC("_bool"):
				fc_getline();
				input = active_script[line];
				codex_store_bool(input, math_cal_return<bool>(codex_get_bool(input)));
				break;
			case COREFC("_triple"):
				fc_getline();
				input = active_script[line];
				codex_store_triple(input, math_cal_return<triple>(codex_get_triple(input)));
				break;
			case COREFC("_double"):
				fc_getline();
				input = active_script[line];
				codex_store_double(input, math_cal_return<double>(codex_get_double(input)));
				break;
			case COREFC("_float"):
				fc_getline();
				input = active_script[line];
				codex_store_float(input, math_cal_return<float>(codex_get_float(input)));
				break;
			case COREFC("_string"):
				fc_getline();
				input = active_script[line];
				codex_store_string(input, math_cal_return<string>(codex_get_string(input)));
				break;
			case COREFC("_ret"):
				return;
			case COREFC("_array"):
			default:
			error_stream("+cal->*error");
				break;
		}
	} loop;

}
void math_set() {

}

#pragma once

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
			case COREFC("+set"):
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
          	case COREFC("@*")://assignment wrap
          		assignment_wrap();
          		break;
      		default:
        		error_stream();
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
		default:
			error_stream();
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
		default:
			error_stream();
			break;
	}
}
void math_graph() {

}
void math_cal() {
	uint16_t math_var_type = actiontype::action_int64;
	uint64_t math_output_var;
	uint16_t math_operator;
	fc_getline();
	switch(active_script[line]) {
		case COREFC("_int64"):
			math_var_type = actiontype::action_int64;
			break;
		case COREFC("_int32"):
			math_var_type = actiontype::action_int32;
			break;
		case COREFC("_int16"):
			math_var_type = actiontype::action_int16;
			break;
		case COREFC("_int8"):
			math_var_type = actiontype::action_int8;
			break;
		case COREFC("_bool"):
			math_var_type = actiontype::action_bool;
			break;
		case COREFC("_triple"):
			math_var_type = actiontype::action_triple;
			break;
		case COREFC("_double"):
			math_var_type = actiontype::action_double;
			break;
		case COREFC("_float"):
			math_var_type = actiontype::action_float;
			break;
		case COREFC("_string"):
			math_var_type = actiontype::action_string;
			break;
		default:
		error_stream();
			break;
	}
	fc_getline();
	math_output_var = active_script[line];
	fc_getline();
	switch(active_script[line]) {
		case COREFC("+")://addition
		case COREFC("_add"):
			math_operator = mathstream::madd;
			break;
		case COREFC("-")://subtraction
		case COREFC("_sub"):
			math_operator = mathstream::msub;
			break;
		case COREFC("*")://multiplication
		case COREFC("_mul"):
			math_operator = mathstream::mmul;
			break;
		case COREFC("/")://division
		case COREFC("_div"):
			math_operator = mathstream::mdiv;
			break;
		case COREFC("%")://modulose
		case COREFC("_mod"):
			math_operator = mathstream::mmod;
			break;
		case COREFC("^")://power
		case COREFC("_pow"):
			math_operator = mathstream::mpow;
			break;
		case COREFC("log")://log
		case COREFC("_log"):
			math_operator = mathstream::mlog;
			break;
		case COREFC("root")://root
		case COREFC("_root"):
			math_operator = mathstream::mroot;
			break;
		default:
			error_stream();
			break;
	}
	fc_getline();

}
void math_set() {

}

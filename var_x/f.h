#pragma once
#define FCS_F

void functional_time() {

}
void functional_hash() {

}
void functional_size();

void functional_sleep() {

}

void functional_stream() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("+time"):
				functional_time();
				break;
			case COREFC("+hash")://64/32/16/8
				functional_hash();
				break;
			case COREFC("+size"):
				functional_size();
				break;
			case COREFC("+sleep"):
				functional_sleep();
				break;
			//standard:
       		case COREFC("f*")://sexit
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
				error_stream("*f->*error");
				break;
		}

	} loop;
}

void functional_size_var_array(uint64_t & i) {
	fc_getline();
	switch (active_script[line]) {
		case COREFC("_hash"):
			fc_getline();
			codex_store_int16(i, sizeof(hash_var_array[active_script[line]]));
			break;
		case COREFC("_int"):
		case COREFC("_int64"):
			fc_getline();
			codex_store_int16(i, sizeof(int64_var_array[active_script[line]]));
			break;
		case COREFC("_int32"):
			fc_getline();
			codex_store_int16(i, sizeof(int32_var_array[active_script[line]]));
			break;
		case COREFC("_int16"):
			fc_getline();
			codex_store_int16(i, sizeof(int16_var_array[active_script[line]]));
			break;
		case COREFC("_int8"):
			fc_getline();
			codex_store_int16(i, sizeof(int8_var_array[active_script[line]]));
			break;
		case COREFC("_bool"):
			fc_getline();
			codex_store_int16(i, sizeof(bool_var_array[active_script[line]]));
			break;
		case COREFC("_float"):
			fc_getline();
			codex_store_int16(i, sizeof(float_var_array[active_script[line]]));
			break;
		case COREFC("_double"):
			fc_getline();
			codex_store_int16(i, sizeof(double_var_array[active_script[line]]));
			break;
		case COREFC("_triple"):
			fc_getline();
			codex_store_int16(i, sizeof(triple_var_array[active_script[line]]));
			break;
		case COREFC("_string"):
			fc_getline();
			codex_store_int16(i, sizeof(string_var_array[active_script[line]]));
			break;
		default:
			error_stream("+size->_var->_array->*error");
			break;
	}
}

void functional_size_var() {
	fc_getline();
	uint64_t i = active_script[line];
	fc_getline();
	switch (active_script[line]) {
		case COREFC("_hash"):
			fc_getline();
			codex_store_int16(i, sizeof(hash_var[active_script[line]]));
			break;
		case COREFC("_int"):
		case COREFC("_int64"):
			fc_getline();
			codex_store_int16(i, sizeof(int64_var[active_script[line]]));
			break;
		case COREFC("_int32"):
			fc_getline();
			codex_store_int16(i, sizeof(int32_var[active_script[line]]));
			break;
		case COREFC("_int16"):
			fc_getline();
			codex_store_int16(i, sizeof(int16_var[active_script[line]]));
			break;
		case COREFC("_int8"):
			fc_getline();
			codex_store_int16(i, sizeof(int8_var[active_script[line]]));
			break;
		case COREFC("_bool"):
			fc_getline();
			codex_store_int16(i, sizeof(bool_var[active_script[line]]));
			break;
		case COREFC("_float"):
			fc_getline();
			codex_store_int16(i, sizeof(float_var[active_script[line]]));
			break;
		case COREFC("_double"):
			fc_getline();
			codex_store_int16(i, sizeof(double_var[active_script[line]]));
			break;
		case COREFC("_triple"):
			fc_getline();
			codex_store_int16(i, sizeof(triple_var[active_script[line]]));
			break;
		case COREFC("_string"):
			fc_getline();
			codex_store_int16(i, sizeof(string_var[active_script[line]]));
			break;
		case COREFC("_array"):
			functional_size_var_array(i);
			break;
		default:
			error_stream("+size->_var->*error");
			break;
	}
}
void functional_size_array() {
	fc_getline();
	switch (active_script[line]) {
		case COREFC("_hash"):
			fc_getline();
			codex_store_int64(active_script[line], hash_var_array[active_script[line]].size());
			break;
		case COREFC("_int"):
		case COREFC("_int64"):
			fc_getline();
			codex_store_int64(active_script[line], int64_var_array[active_script[line]].size());
			break;
		case COREFC("_int32"):
			fc_getline();
			codex_store_int64(active_script[line], int32_var_array[active_script[line]].size());
			break;
		case COREFC("_int16"):
			fc_getline();
			codex_store_int64(active_script[line], int16_var_array[active_script[line]].size());
			break;
		case COREFC("_int8"):
			fc_getline();
			codex_store_int64(active_script[line], int8_var_array[active_script[line]].size());
			break;
		case COREFC("_bool"):
			fc_getline();
			codex_store_int64(active_script[line], bool_var_array[active_script[line]].size());
			break;
		case COREFC("_float"):
			fc_getline();
			codex_store_int64(active_script[line], float_var_array[active_script[line]].size());
			break;
		case COREFC("_double"):
			fc_getline();
			codex_store_int64(active_script[line], double_var_array[active_script[line]].size());
			break;
		case COREFC("_triple"):
			fc_getline();
			codex_store_int64(active_script[line], triple_var_array[active_script[line]].size());
			break;
		case COREFC("_string"):
			fc_getline();
			codex_store_int64(active_script[line], string_var_array[active_script[line]].size());
			break;
		case COREFC("_quantum"):
			fc_getline();
			codex_store_int64(active_script[line], quantum_var_array[active_script[line]].size());
			break;
		case COREFC("_chart"):
			fc_getline();
			codex_store_int64(active_script[line], chart_var_array[active_script[line]].size());
			break;
		default:
			error_stream("+size->_array->*error");
			break;
	}
}
void functional_size_type_max() {
	fc_getline();
	fc_getline();
	switch (active_script[line-1]) {
		case COREFC("_hash"):
			codex_store_hash(active_script[line], numeric_limits<uint64_t>::max());
			break;
		case COREFC("_int"):
		case COREFC("_int64"):
			codex_store_int64(active_script[line], numeric_limits<int64_t>::max());
			break;
		case COREFC("_int32"):
			codex_store_int32(active_script[line], numeric_limits<int32_t>::max());
			break;
		case COREFC("_int16"):
			codex_store_int16(active_script[line], numeric_limits<int16_t>::max());
			break;
		case COREFC("_int8"):
			codex_store_int8(active_script[line], numeric_limits<int8_t>::max());
			break;
		case COREFC("_bool"):
			codex_store_bool(active_script[line], numeric_limits<bool>::max());
			break;
		case COREFC("_float"):
			codex_store_float(active_script[line], numeric_limits<float>::max());
			break;
		case COREFC("_double"):
			codex_store_double(active_script[line], numeric_limits<double>::max());
			break;
		case COREFC("_triple"):
			codex_store_triple(active_script[line], numeric_limits<triple>::max());
			break;
		default:
			error_stream("+size->_type->*error");
			break;
	}
}
void functional_size_type_min() {
	fc_getline();
	fc_getline();
	switch (active_script[line-1]) {
		case COREFC("_hash"):
			codex_store_hash(active_script[line], numeric_limits<uint64_t>::min());
			break;
		case COREFC("_int"):
		case COREFC("_int64"):
			codex_store_int64(active_script[line], numeric_limits<int64_t>::min());
			break;
		case COREFC("_int32"):
			codex_store_int32(active_script[line], numeric_limits<int32_t>::min());
			break;
		case COREFC("_int16"):
			codex_store_int16(active_script[line], numeric_limits<int16_t>::min());
			break;
		case COREFC("_int8"):
			codex_store_int8(active_script[line], numeric_limits<int8_t>::min());
			break;
		case COREFC("_bool"):
			codex_store_bool(active_script[line], numeric_limits<bool>::min());
			break;
		case COREFC("_float"):
			codex_store_float(active_script[line], numeric_limits<float>::min());
			break;
		case COREFC("_double"):
			codex_store_double(active_script[line], numeric_limits<double>::min());
			break;
		case COREFC("_triple"):
			codex_store_triple(active_script[line], numeric_limits<triple>::min());
			break;
		default:
			error_stream("+size->_type->*error");
			break;
	}
}
void functional_size_type() {
	fc_getline();
	switch (active_script[line]) {
		case COREFC("_max"):
			functional_size_type_max();
			break;
		case COREFC("_min"):
			functional_size_type_min();
			break;
		default:
			error_stream("+size->_type->*error");
			break;
	}
}

void functional_size() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_var"):
				functional_size_var();
				break;
			case COREFC("_array"):

				break;
			case COREFC("_type"):
				functional_size_type();
				break;
			case COREFC("_ret"):
				return;
			default:
				error_stream("+size->*error");
				break;
		}
	} loop;
}
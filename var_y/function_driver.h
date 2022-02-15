#pragma once

void scan_stream();//super dangerus function declaration, do not try at home. This was done by a spagetti code professional.

void fc_function_return() {
	line = line_bak[line_bak.size()-1];
	active_script = active_script_bak[active_script_bak.size()-1].script;
	line_bak.pop_back();
	active_script_bak.pop_back();
}

void fc_function_load() {
	//backup current function
	line_bak.push_back(line);//backup line
	codex_function_swap load_new_function;//create new script backup slot
	load_new_function.script = active_script;//backup current script
	active_script_bak.push_back(load_new_function);//store newly crated script backup in longterm storage
	//load new function
	active_script = fc_functions[active_script[line]];
	line = phantom_line;
	scan_stream();
	fc_function_return();
}

bool fc_function_check() {
	if (fc_functions.find(active_script[line]) == fc_functions.end()) {
		//not found function
		return false;
	} else {
		//found function
		fc_function_load();
		return true;
	}
}

void fc_function_create() {
	uint32_t fc_function_input_name;
	fc_getline();
	fc_function_input_name = active_script[line];
	while(line < active_script.size()) {
		fc_getline();
		if (active_script[line]==phantom_hash) {return;}
		fc_functions[fc_function_input_name].push_back(active_script[line]);
	}
}

void fc_function_delete() {
	
}
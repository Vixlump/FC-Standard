#pragma once

void convert_codex_to_hash_var(uint64_t & input, uint8_t hash_location) {
  string script_reinterpretor;
  for (int i = hash_location+1; i<script_reader[input].length(); i++) {
    script_reinterpretor += script_reader[input][i];
  }
  switch (script_reader[input][hash_location-1]) {
    case 'n':
    case '6':
      active_int64.push_back(stoll(script_reinterpretor.c_str()));
      active_script.push_back(active_int64.size()-1);
      break;
    case 'l':
    case '3':
      active_int32.push_back(stol(script_reinterpretor.c_str()));
      active_script.push_back(active_int32.size()-1);
      break;
    case 'i':
    case '1':
      active_int16.push_back(stoi(script_reinterpretor.c_str()));
      active_script.push_back(active_int16.size()-1);
      break;
    case '8':
      active_int8.push_back(stoi(script_reinterpretor.c_str()));
      active_script.push_back(active_int8.size()-1);
      break;
    case 'b':
      if ((script_reinterpretor=="true") || (script_reinterpretor=="1") || (script_reinterpretor=="True") || (script_reinterpretor=="TRUE")) {
        active_bool.push_back(true); } else {active_bool.push_back(false);}
        active_script.push_back(active_bool.size()-1);
      break;
    case 'd':
      active_double.push_back(stod(script_reinterpretor.c_str()));
      active_script.push_back(active_double.size()-1);
      break;
    case 'f':
      active_float.push_back(stof(script_reinterpretor.c_str()));
      active_script.push_back(active_float.size()-1);
      break;
    case 't':
      active_triple.push_back(stold(script_reinterpretor.c_str()));
      active_script.push_back(active_triple.size()-1);
      break;
    case 's':
      active_string.push_back(script_reinterpretor);
      active_script.push_back(active_string.size()-1);
      break;
    case '@':
      assignment new_assignment_point;
      new_assignment_point.name = UIRN(script_reinterpretor.c_str(), strlen(script_reinterpretor.c_str()));
      new_assignment_point.line = input;
      active_assignments.push_back(new_assignment_point);
      active_script.push_back(UIRN("", strlen("")));
      break;
    case '/':
      active_script.push_back(UIRN("", strlen("")));
      break;
    default:
      cout<<"Syntax Error Codex Could Not Be Compiled[N="<<file_name<<" L="<<input<<"]"<<endl;
      exit(42);
      break;
  }
}

void convert_codex_to_hash() {
  constexpr uint8_t hash_location = 1;
  for (uint64_t i = 0; i < script_reader.size(); i++) {
    switch (script_reader[i][hash_location]) {
      case '#':
        convert_codex_to_hash_var(i, hash_location);
        break;
      default:
        active_script.push_back(UIRN(script_reader[i].c_str(), strlen(script_reader[i].c_str())));
        break;
    }
  }
}

void load_codex(string input) {
  file_name = input + defined_file_extention;
  ifstream new_active_file(file_name);
  string loader_process_m;
  script_reader.clear();
  while (getline(new_active_file, loader_process_m)) {
    script_reader.push_back(loader_process_m);
  }
  new_active_file.close();
  active_script.clear();

  active_string.clear();
  active_int64.clear();
  active_int32.clear();
  active_int16.clear();
  active_int8.clear();
  active_bool.clear();
  active_float.clear();
  active_double.clear();
  active_triple.clear();
  active_assignments.clear();
  line = phantom_line;
  convert_codex_to_hash();

}

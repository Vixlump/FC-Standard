#pragma once

void convert_codex_to_hash_var(uint64_t & input, uint8_t hash_location, bool & in_patchwork_function, uint64_t & function_line_counter) {
  string script_reinterpretor;
  for (int i = hash_location+1; i<script_reader[input].length(); i++) {
    script_reinterpretor += script_reader[input][i];
  }
  switch (script_reader[input][hash_location-1]) {
    case 'n':
    case '6'://int64
      active_int64.push_back(stoll(script_reinterpretor.c_str()));
      active_script.push_back(active_int64.size()-1);
      break;
    case 'l':
    case '3'://int32
      active_int32.push_back(stol(script_reinterpretor.c_str()));
      active_script.push_back(active_int32.size()-1);
      break;
    case 'i':
    case '1'://int16
      active_int16.push_back(stoi(script_reinterpretor.c_str()));
      active_script.push_back(active_int16.size()-1);
      break;
    case '8'://int8
      active_int8.push_back(stoi(script_reinterpretor.c_str()));
      active_script.push_back(active_int8.size()-1);
      break;
    case 'b'://bool
      if ((script_reinterpretor=="true") || (script_reinterpretor=="1") || (script_reinterpretor=="True") || (script_reinterpretor=="TRUE")) {
        active_bool.push_back(true); } else {active_bool.push_back(false);}
        active_script.push_back(active_bool.size()-1);
      break;
    case 'd'://double
      active_double.push_back(stod(script_reinterpretor.c_str()));
      active_script.push_back(active_double.size()-1);
      break;
    case 'f'://float
      active_float.push_back(stof(script_reinterpretor.c_str()));
      active_script.push_back(active_float.size()-1);
      break;
    case 't'://triple
      active_triple.push_back(stold(script_reinterpretor.c_str()));
      active_script.push_back(active_triple.size()-1);
      break;
    case 's'://string
      active_string.push_back(script_reinterpretor);
      active_script.push_back(active_string.size()-1);
      break;
    case '@'://assignment
      assignment new_assignment_point;
      new_assignment_point.name = COREFC(script_reinterpretor.c_str());
      if (in_patchwork_function==true) {new_assignment_point.line = function_line_counter;} else {
        new_assignment_point.line = input;
      }
      if (script_reinterpretor[0]=='@') {
        function_assignments.push_back(new_assignment_point);
      } else {
        active_assignments.push_back(new_assignment_point);
      }
      active_script.push_back(COREFC(""));
      break;
    case '~'://escaped hash can be used to add functions to a program without changing the Codex ID
      active_script.push_back(COREFC(script_reinterpretor.c_str()));
      break;  
    case '#':
      active_script.push_back(atoi(script_reinterpretor.c_str()));
      break;
    case '*':
    case '0'://largest possible uint64_t to ensure namespace is never taken
      in_patchwork_function = false;
      active_script.push_back(phantom_hash);
      break;
    case 'v'://second largest possible uint64_t to ensure var is called is never taken
      active_script.push_back(phantom_var);
      break;
    case 'a':
      active_script.push_back(phantom_array);
      break;
    case '/'://notation
      active_script.push_back(COREFC(""));
      break;
    default:
      cout<<"Syntax Error Codex Could Not Be Compiled[N="<<file_name<<" L="<<input+1<<"]"<<endl;
      exit(42);
      break;
  }
}

void convert_codex_to_hash() {
  constexpr uint8_t hash_location = 1;
  bool in_patchwork_function = false;
  uint64_t function_line_counter = phantom_line;
  for (uint64_t i = 0; i < script_reader.size(); i++) {
    if (in_patchwork_function == true) {function_line_counter++;}
    //cout<<"HashBook["<<script_reader[i]<<"]"<<i<<endl;//this line is for codex debugging
    switch (script_reader[i][hash_location]) {
      case '#':
        convert_codex_to_hash_var(i, hash_location, in_patchwork_function, function_line_counter);
        break;
      default:
        codex_id+=COREFC(script_reader[i].c_str());
        active_script.push_back(COREFC(script_reader[i].c_str()));
        if (script_reader[i]=="f") {
          in_patchwork_function = true;
          function_line_counter = phantom_line;
          i++;
          script_reader[i] = "*"+script_reader[i];
          codex_id+=COREFC(script_reader[i].c_str());
          active_script.push_back(COREFC(script_reader[i].c_str()));
        }
        break;
    }
  }
  //codex_id /= script_reader.size();//I want to add it but I also don't... hmm
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

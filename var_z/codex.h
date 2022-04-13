#pragma once

//custom types
typedef long double triple;
struct codex_function_swap {
  vector<uint64_t> script;
};

string original_file_name = "active";
const string defined_file_extention = ".fc";

thread_local string file_name = "active";
thread_local vector <string> file_name_bak;

constexpr uint64_t phantom_line = numeric_limits<uint64_t>::max();
constexpr uint64_t phantom_hash = numeric_limits<uint64_t>::max();
constexpr uint64_t phantom_var = phantom_hash-1;
constexpr uint64_t phantom_array = phantom_var-1;

thread_local uint64_t line = 0;
thread_local vector <uint64_t> line_bak;

thread_local uint64_t thread_label = 0;
uint64_t adapted_threads = 1;
uint64_t known_threads = 1;

uint64_t codex_id = 0;

map <uint64_t, vector<uint64_t>> fc_functions;

//anything you add here needs to get added to the patchwork.h load_codex and be cleared
thread_local vector <string> script_reader;
thread_local vector <uint64_t> active_script;
thread_local vector <codex_function_swap> active_script_bak;
thread_local vector <string> active_string;
thread_local vector <int64_t> active_int64;
thread_local vector <int32_t> active_int32;
thread_local vector <int16_t> active_int16;
thread_local vector <int8_t> active_int8;
thread_local vector <bool> active_bool;
thread_local vector <float> active_float;
thread_local vector <double> active_double;
thread_local vector <triple> active_triple;
struct assignment { uint64_t name; uint64_t line; };
thread_local vector <assignment> active_assignments;
thread_local vector <assignment> function_assignments;

struct fc_type_string {uint64_t name;vector <string> value;};
struct fc_type_int64 {uint64_t name;vector <int64_t> value;};
struct fc_type_int32 {uint64_t name;vector <int32_t> value;};
struct fc_type_int16 {uint64_t name;vector <int16_t> value;};
struct fc_type_int8 {uint64_t name;vector <int8_t> value;};
struct fc_type_bool {uint64_t name;vector <bool> value;};
struct fc_type_float {uint64_t name;vector <float> value;};
struct fc_type_double {uint64_t name;vector <double> value;};
struct fc_type_triple {uint64_t name;vector <triple> value;};
struct fc_type_chart {uint64_t name;vector <ifstream> value;};
struct fc_type_quantum {uint64_t name;vector <ofstream> value;};
map <uint64_t, string> string_var;map <uint64_t, vector <string>> string_var_array;
map <uint64_t, int64_t> int64_var;map <uint64_t, vector <int64_t>> int64_var_array;
map <uint64_t, int32_t> int32_var;map <uint64_t, vector <int32_t>> int32_var_array;
map <uint64_t, int16_t> int16_var;map <uint64_t, vector <int16_t>> int16_var_array;
map <uint64_t, int8_t> int8_var;map <uint64_t, vector <int8_t>> int8_var_array;
map <uint64_t, bool> bool_var;map <uint64_t, vector <bool>> bool_var_array;
map <uint64_t, float> float_var;map <uint64_t, vector <float>> float_var_array;
map <uint64_t, double> double_var;map <uint64_t, vector <double>> double_var_array;
map <uint64_t, triple> triple_var;map <uint64_t, vector <triple>> triple_var_array;
map <uint64_t, uint64_t> hash_var;map <uint64_t, vector <uint64_t>> hash_var_array;
map <uint64_t, ifstream> chart_var;map <uint64_t, vector <ifstream>> chart_var_array;
map <uint64_t, ofstream> quantum_var;map <uint64_t, vector <ofstream>> quantum_var_array;
//allocators
inline void codex_allocate_int64(uint64_t name) {int64_t input; int64_var.insert(pair<uint64_t,int64_t>(name,input));}
inline void codex_allocate_int32(uint64_t name) {int32_t input; int32_var.insert(pair<uint64_t,int32_t>(name,input));}
inline void codex_allocate_int16(uint64_t name) {int16_t input; int16_var.insert(pair<uint64_t,int16_t>(name,input));}
inline void codex_allocate_int8(uint64_t name) {int8_t input; int8_var.insert(pair<uint64_t,int8_t>(name,input));}
inline void codex_allocate_bool(uint64_t name) {bool input; bool_var.insert(pair<uint64_t,bool>(name,input));}
inline void codex_allocate_triple(uint64_t name) {triple input; triple_var.insert(pair<uint64_t,triple>(name,input));}
inline void codex_allocate_double(uint64_t name) {double input; double_var.insert(pair<uint64_t,double>(name,input));}
inline void codex_allocate_float(uint64_t name) {float input; float_var.insert(pair<uint64_t,float>(name,input));}
inline void codex_allocate_string(uint64_t name) {string input; string_var.insert(pair<uint64_t,string>(name,input));}
inline void codex_allocate_hash(uint64_t name) {uint64_t input; hash_var.insert(pair<uint64_t,uint64_t>(name,input));}
//inline void codex_allocate_int64_array(uint64_t name) {vector<int64_t> input; int64_var.insert({name,input});}
//inline void codex_allocate_int32_array(uint64_t name) {vector<int32_t> input; int32_var.insert({name,input});}
//inline void codex_allocate_int16_array(uint64_t name) {vector<int16_t> input; int16_var.insert({name,input});}
//inline void codex_allocate_int8_array(uint64_t name) {vector<int8_t> input; int8_var.insert({name,input});}
//inline void codex_allocate_bool_array(uint64_t name) {vector<bool> input; bool_var.insert({name,input});}
//inline void codex_allocate_triple_array(uint64_t name) {vector<triple> input; triple_var.insert({name,input});}
//inline void codex_allocate_double_array(uint64_t name) {vector<double> input; double_var.insert({name,input});}
//inline void codex_allocate_float_array(uint64_t name) {vector<float> input; float_var.insert({name,input});}
//inline void codex_allocate_string_array(uint64_t name) {vector<string> input; string_var.insert({name,input});}
//inline void codex_allocate_hash_array(uint64_t name) {vector<uint64_t> input; hash_var.insert({name,input});}

//array pushbacks:
inline void codex_add_string_array(uint64_t name, string value) {
  string_var_array[name].push_back(value);
}
inline void codex_add_int64_array(uint64_t name, int64_t value) {
  int64_var_array[name].push_back(value);
}
inline void codex_add_int32_array(uint64_t name, int32_t value) {
  int32_var_array[name].push_back(value);
}
inline void codex_add_int16_array(uint64_t name, int16_t value) {
  int16_var_array[name].push_back(value);
}
inline void codex_add_int8_array(uint64_t name, int8_t value) {
  int8_var_array[name].push_back(value);
}
inline void codex_add_bool_array(uint64_t name, bool value) {
  bool_var_array[name].push_back(value);
}
inline void codex_add_float_array(uint64_t name, float value) {
  float_var_array[name].push_back(value);
}
inline void codex_add_double_array(uint64_t name, double value) {
  double_var_array[name].push_back(value);
}
inline void codex_add_triple_array(uint64_t name, triple value) {
  triple_var_array[name].push_back(value);
}
inline void codex_add_hash_array(uint64_t name, uint64_t value) {
  hash_var_array[name].push_back(value);
}

//return variable:
inline string codex_return_string(uint64_t name) {
  return string_var[name];
}
inline int64_t codex_return_int64(uint64_t name) {
  return int64_var[name];
}
inline int32_t codex_return_int32(uint64_t name) {
  return int32_var[name];
}
inline int16_t codex_return_int16(uint64_t name) {
  return int16_var[name];
}
inline int8_t codex_return_int8(uint64_t name) {
  return int8_var[name];
}
inline bool codex_return_bool(uint64_t name) {
  return bool_var[name];
}
inline float codex_return_float(uint64_t name) {
  return float_var[name];
}
inline double codex_return_double(uint64_t name) {
  return double_var[name];
}
inline triple codex_return_triple(uint64_t name) {
  return triple_var[name];
}
inline uint64_t codex_return_hash(uint64_t name) {
  return hash_var[name];
}
//array types:
inline string codex_return_string_array(uint64_t name, uint64_t pos) {
  return string_var_array[name][pos];
}
inline int64_t codex_return_int64_array(uint64_t name, uint64_t pos) {
  return int64_var_array[name][pos];
}
inline int32_t codex_return_int32_array(uint64_t name, uint64_t pos) {
  return int32_var_array[name][pos];
}
inline int16_t codex_return_int16_array(uint64_t name, uint64_t pos) {
  return int16_var_array[name][pos];
}
inline int8_t codex_return_int8_array(uint64_t name, uint64_t pos) {
  return int8_var_array[name][pos];
}
inline bool codex_return_bool_array(uint64_t name, uint64_t pos) {
  return bool_var_array[name][pos];
}
inline float codex_return_float_array(uint64_t name, uint64_t pos) {
  return float_var_array[name][pos];
}
inline double codex_return_double_array(uint64_t name, uint64_t pos) {
  return double_var_array[name][pos];
}
inline triple codex_return_triple_array(uint64_t name, uint64_t pos) {
  return triple_var_array[name][pos];
}
inline uint64_t codex_return_hash_array(uint64_t name, uint64_t pos) {
  return hash_var_array[name][pos];
}

//constants:
inline uint64_t codex_get_assignment(uint64_t name) {
  for (uint64_t i = 0; i < active_assignments.size(); i++) {
    if (active_assignments[i].name==name) {return active_assignments[i].line;}
  }
  for (uint64_t i2 = 0; i2 < function_assignments.size(); i2++) {
    if (function_assignments[i2].name==name) {return function_assignments[i2].line;}
  }
  cout<<"Contex Error["<<name<<"] is not an assignment point."<<endl;
  exit(42);
}

inline int64_t codex_get_allint(uint64_t input) {
  //possible addition
  return 0;
}

inline int64_t codex_get_int64(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_int64(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_int64_array(active_script[line-1], codex_get_int64(active_script[line]));
    default:
      return active_int64[input];
  }
}
inline string codex_get_string(uint64_t input) {
  switch (input) {
    case phantom_var:
      line++;
      return codex_return_string(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_string_array(active_script[line-1], codex_get_int64(active_script[line]));
    default:
      return active_string[input];
      
  }
}
inline int64_t codex_get_int32(uint64_t input) {
  switch (input) {
    case phantom_var:
      line++;
      return codex_return_int32(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_int32_array(active_script[line-1], codex_get_int64(active_script[line]));
    default:
      return active_int32[input];
  }
}
inline int16_t codex_get_int16(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_int16(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_int16_array(active_script[line-1], codex_get_int64(active_script[line]));
    default:
      return active_int16[input];
  }
}
inline int8_t codex_get_int8(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_int8(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_int8_array(active_script[line-1], codex_get_int64(active_script[line]));
    default:
      return active_int8[input];
  }
}
inline bool codex_get_bool(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_bool(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_bool_array(active_script[line-1], codex_get_int64(active_script[line]));
    default:
      return active_bool[input];
  }
}
inline float codex_get_float(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_float(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_float_array(active_script[line-1], codex_get_int64(active_script[line]));
    default:
      return active_float[input];
  }
}
inline double codex_get_double(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_double(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_double_array(active_script[line-1], codex_get_int64(active_script[line]));
    default:
      return active_double[input];
  }
}
inline triple codex_get_triple(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_triple(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_triple_array(active_script[line-1], codex_get_int64(active_script[line]));
    default:
      return active_triple[input];
  }
}

inline uint64_t codex_get_hash(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_hash(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_hash_array(active_script[line-1], codex_get_int64(active_script[line]));
    default:
      return input;
  }
}

//store variable:
inline void codex_store_all(uint64_t name, string value) {
  string_var[name] = value;
  hash_var[name] = stoull(value.c_str());
  int64_var[name] = stoll(value.c_str());
  int32_var[name] = stol(value.c_str());
  int16_var[name] = stoi(value.c_str());
  int8_var[name] = stoi(value.c_str());
  if (value=="true"||stoll(value.c_str())>=1||value=="True"||value=="TRUE") {bool_var[name] = true;} else {bool_var[name] = false;}
  float_var[name] = stof(value.c_str());
  double_var[name] = stod(value.c_str());
  triple_var[name] = stold(value.c_str());
}
//array types:
inline void codex_store_string_array(uint64_t name, uint64_t pos, string value) {
  string_var_array[name][pos] = value;
}
inline void codex_store_int64_array(uint64_t name, uint64_t pos, int64_t value) {
  int64_var_array[name][pos] = value;
}
inline void codex_store_int32_array(uint64_t name, uint64_t pos, int32_t value) {
  int32_var_array[name][pos] = value;
}
inline void codex_store_int16_array(uint64_t name, uint64_t pos, int16_t value) {
  int16_var_array[name][pos] = value;
}
inline void codex_store_int8_array(uint64_t name, uint64_t pos, int8_t value) {
  int8_var_array[name][pos] = value;
}
inline void codex_store_bool_array(uint64_t name, uint64_t pos, bool value) {
  bool_var_array[name][pos] = value;
}
inline void codex_store_float_array(uint64_t name, uint64_t pos, float value) {
  float_var_array[name][pos] = value;
}
inline void codex_store_double_array(uint64_t name, uint64_t pos, double value) {
  double_var_array[name][pos] = value;
}
inline void codex_store_triple_array(uint64_t name, uint64_t pos, triple value) {
  triple_var_array[name][pos] = value;
}
inline void codex_store_hash_array(uint64_t name, uint64_t pos, uint64_t value) {
  hash_var_array[name][pos] = value;
}
inline void codex_store_string(uint64_t name, string value) {
  string_var[name] = value;
}
inline void codex_store_int64(uint64_t name, int64_t value) {
  int64_var[name] = value;
}
inline void codex_store_int32(uint64_t name, int32_t value) {
  int32_var[name] = value;
}
inline void codex_store_int16(uint64_t name, int16_t value) {
  int16_var[name] = value;
}
inline void codex_store_int8(uint64_t name, int8_t value) {
  int8_var[name] = value;
}
inline void codex_store_bool(uint64_t name, bool value) {
  bool_var[name] = value;
}
inline void codex_store_float(uint64_t name, float value) {
  float_var[name] = value;
}
inline void codex_store_double(uint64_t name, double value) {
  double_var[name] = value;
}
inline void codex_store_triple(uint64_t name, triple value) {
  triple_var[name] = value;
}
inline void codex_store_hash(uint64_t name, uint64_t value) {
  hash_var[name] = value;
}
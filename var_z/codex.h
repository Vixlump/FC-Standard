#pragma once

//custom types
typedef long double triple;

string original_file_name = "active";
const string defined_file_extention = ".fc";

thread_local string file_name = "active.fc";
thread_local vector <string> file_name_bak;

constexpr uint64_t phantom_line = numeric_limits<uint64_t>::max();

thread_local uint64_t line = 0;
thread_local vector <uint32_t> line_bak;

thread_local uint32_t thread_label = 0;
uint32_t adapted_threads = 1;
uint32_t known_threads = 1;

uint64_t codex_id = 0;

//anything you add here needs to get added to the patchwork.h load_codex and be cleared
thread_local vector <string> script_reader;
thread_local vector <uint32_t> active_script;
thread_local vector <string> active_string;
thread_local vector <int64_t> active_int64;
thread_local vector <int32_t> active_int32;
thread_local vector <int16_t> active_int16;
thread_local vector <int8_t> active_int8;
thread_local vector <bool> active_bool;
thread_local vector <float> active_float;
thread_local vector <double> active_double;
thread_local vector <triple> active_triple;
struct assignment { uint32_t name; uint64_t line; };
thread_local vector <assignment> active_assignments;

inline uint64_t codex_get_assignment(uint32_t name) {
  for (uint32_t i = 0; i < active_assignments.size(); i++) {
    if (active_assignments[i].name==name) {return active_assignments[i].line;}
  }
  exit(42);
}

inline string codex_get_string(uint64_t input) {
  return active_string[input];
}
inline uint32_t codex_get_int32(uint64_t input) {
  return active_int32[input];
}
inline uint64_t codex_get_int64(uint64_t input) {
  return active_int64[input];
}
inline uint16_t codex_get_int16(uint64_t input) {
  return active_int16[input];
}
inline uint8_t codex_get_int8(uint64_t input) {
  return active_int8[input];
}
inline bool codex_get_bool(uint64_t input) {
  return active_bool[input];
}
inline float codex_get_float(uint64_t input) {
  return active_float[input];
}
inline double codex_get_double(uint64_t input) {
  return active_double[input];
}
inline triple codex_get_triple(uint64_t input) {
  return active_triple[input];
}

struct fc_type_string {uint32_t name;vector <string> value;};
struct fc_type_int64 {uint32_t name;vector <int64_t> value;};
struct fc_type_int32 {uint32_t name;vector <int32_t> value;};
struct fc_type_int16 {uint32_t name;vector <int16_t> value;};
struct fc_type_int8 {uint32_t name;vector <int8_t> value;};
struct fc_type_bool {uint32_t name;vector <bool> value;};
struct fc_type_float {uint32_t name;vector <float> value;};
struct fc_type_double {uint32_t name;vector <double> value;};
struct fc_type_triple {uint32_t name;vector <triple> value;};
struct fc_type_chart {uint32_t name;vector <ifstream> value;};
struct fc_type_quantum {uint32_t name;vector <ofstream> value;};
map <uint32_t, string> string_var;map <uint32_t, vector <string>> string_var_array;
map <uint32_t, int64_t> int64_var;map <uint32_t, vector <int64_t>> int64_var_array;
map <uint32_t, int32_t> int32_var;map <uint32_t, vector <int32_t>> int32_var_array;
map <uint32_t, int16_t> int16_var;map <uint32_t, vector <int16_t>> int16_var_array;
map <uint32_t, int8_t> int8_var;map <uint32_t, vector <int8_t>> int8_var_array;
map <uint32_t, bool> bool_var;map <uint32_t, vector <bool>> bool_var_array;
map <uint32_t, float> float_var;map <uint32_t, vector <float>> float_var_array;
map <uint32_t, double> double_var;map <uint32_t, vector <double>> double_var_array;
map <uint32_t, triple> triple_var;map <uint32_t, vector <triple>> triple_var_array;
map <uint32_t, uint32_t> hash_var;map <uint32_t, vector <uint32_t>> hash_var_array;
map <uint32_t, ifstream> chart_var;map <uint32_t, vector <ifstream>> chart_var_array;
map <uint32_t, ofstream> quantum_var;map <uint32_t, vector <ofstream>> quantum_var_array;
//store variable:
inline void codex_store_string(uint32_t name, string value) {
  string_var[name] = value;
}
inline void codex_store_int64(uint32_t name, int64_t value) {
  int64_var[name] = value;
}
inline void codex_store_int32(uint32_t name, int32_t value) {
  int32_var[name] = value;
}
inline void codex_store_int16(uint32_t name, int16_t value) {
  int16_var[name] = value;
}
inline void codex_store_int8(uint32_t name, int8_t value) {
  int8_var[name] = value;
}
inline void codex_store_bool(uint32_t name, bool value) {
  bool_var[name] = value;
}
inline void codex_store_float(uint32_t name, float value) {
  float_var[name] = value;
}
inline void codex_store_double(uint32_t name, double value) {
  double_var[name] = value;
}
inline void codex_store_triple(uint32_t name, triple value) {
  triple_var[name] = value;
}
inline void codex_store_hash(uint32_t name, uint32_t value) {
  hash_var[name] = value;
}
//array types:
inline void codex_store_string_array(uint32_t name, uint64_t pos, string value) {
  string_var_array[name][pos] = value;
}
inline void codex_store_int64_array(uint32_t name, uint64_t pos, int64_t value) {
  int64_var_array[name][pos] = value;
}
inline void codex_store_int32_array(uint32_t name, uint64_t pos, int32_t value) {
  int32_var_array[name][pos] = value;
}
inline void codex_store_int16_array(uint32_t name, uint64_t pos, int16_t value) {
  int16_var_array[name][pos] = value;
}
inline void codex_store_int8_array(uint32_t name, uint64_t pos, int8_t value) {
  int8_var_array[name][pos] = value;
}
inline void codex_store_float_array(uint32_t name, uint64_t pos, float value) {
  float_var_array[name][pos] = value;
}
inline void codex_store_double_array(uint32_t name, uint64_t pos, double value) {
  double_var_array[name][pos] = value;
}
inline void codex_store_triple_array(uint32_t name, uint64_t pos, triple value) {
  triple_var_array[name][pos] = value;
}
inline void codex_store_hash_array(uint32_t name, uint64_t pos, uint32_t value) {
  hash_var_array[name][pos] = value;
}

//return variable:
inline string codex_return_string(uint32_t name) {
  return string_var[name];
}
inline int64_t codex_return_int64(uint32_t name) {
  return int64_var[name];
}
inline int32_t codex_return_int32(uint32_t name) {
  return int32_var[name];
}
inline int16_t codex_return_int16(uint32_t name) {
  return int16_var[name];
}
inline int8_t codex_return_int8(uint32_t name) {
  return int8_var[name];
}
inline bool codex_return_bool(uint32_t name) {
  return bool_var[name];
}
inline float codex_return_float(uint32_t name) {
  return float_var[name];
}
inline double codex_return_double(uint32_t name) {
  return double_var[name];
}
inline triple codex_return_triple(uint32_t name) {
  return triple_var[name];
}
inline uint32_t codex_return_hash(uint32_t name) {
  return hash_var[name];
}
//array types:
inline string codex_return_string_array(uint32_t name, uint64_t pos) {
  return string_var_array[name][pos];
}
inline int64_t codex_return_int64_array(uint32_t name, uint64_t pos) {
  return int64_var_array[name][pos];
}
inline int32_t codex_return_int32_array(uint32_t name, uint64_t pos) {
  return int32_var_array[name][pos];
}
inline int16_t codex_return_int16_array(uint32_t name, uint64_t pos) {
  return int16_var_array[name][pos];
}
inline int8_t codex_return_int8_array(uint32_t name, uint64_t pos) {
  return int8_var_array[name][pos];
}
inline bool codex_return_bool_array(uint32_t name, uint64_t pos) {
  return bool_var_array[name][pos];
}
inline float codex_return_float_array(uint32_t name, uint64_t pos) {
  return float_var_array[name][pos];
}
inline double codex_return_double_array(uint32_t name, uint64_t pos) {
  return double_var_array[name][pos];
}
inline triple codex_return_triple_array(uint32_t name, uint64_t pos) {
  return triple_var_array[name][pos];
}
inline uint32_t codex_return_hash_array(uint32_t name, uint64_t pos) {
  return hash_var_array[name][pos];
}
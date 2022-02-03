#pragma once

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
thread_local vector <long double> active_triple;



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
inline long double codex_get_triple(uint64_t input) {
  return active_triple[input];
}

struct fc2_type_string {uint32_t name;vector <string> value;};
struct fc2_type_int64 {uint32_t name;vector <int64_t> value;};
struct fc2_type_int32 {uint32_t name;vector <int32_t> value;};
struct fc2_type_int16 {uint32_t name;vector <int16_t> value;};
struct fc2_type_int8 {uint32_t name;vector <int8_t> value;};
struct fc2_type_bool {uint32_t name;vector <bool> value;};
struct fc2_type_float {uint32_t name;vector <float> value;};
struct fc2_type_double {uint32_t name;vector <double> value;};
struct fc2_type_triple {uint32_t name;vector <long double> value;};
struct fc2_type_chart {uint32_t name;vector <ifstream> value;};
struct fc2_type_quantum {uint32_t name;vector <ofstream> value;};
vector <fc2_type_string> string_var;
vector <fc2_type_int64> int64_var;
vector <fc2_type_int32> int32_var;
vector <fc2_type_int16> int16_var;
vector <fc2_type_int8> int8_var;
vector <fc2_type_bool> bool_var;
vector <fc2_type_float> float_var;
vector <fc2_type_double> double_var;
vector <fc2_type_triple> triple_var;

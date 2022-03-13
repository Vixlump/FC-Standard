#pragma once
#define FCS_ERROR
uint64_t deprications = 0;
uint64_t error_level = 0;
uint64_t error_cap = 0;
string error_trace("S:");
bool error_debug_mode = true;

inline void terminate_all() {
  exit(42);
}

void error_stream() {
    stringstream error_lineto_string;
    error_lineto_string << line+1;
    stringstream error_thread_labelto_string;
    error_thread_labelto_string << thread_label;
    error_level++;
    error_trace=(error_trace+"|"+script_reader[line]);
    error_trace=(error_trace+"[L"+error_lineto_string.str()+"]");
    error_trace=(error_trace+"[T"+error_thread_labelto_string.str()+"]");
    if (error_cap>0) {
      if (error_cap==error_level) {
        terminate_all();
      } else if (error_level>error_cap) {
        cout<<"Program is damaged contact Lumpology!"<<endl;
        terminate_all();
      }
    }
    if (error_debug_mode==true) {cout<<"Error["<<error_trace<<"]"<<endl;}
}

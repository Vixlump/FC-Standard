#pragma once

void debug_point() {
  cout<<"Hit[N="<<file_name<<" L="<<line + 1<<" T="<<thread_label<<"]"<<endl;
}
void debug_info() {
  cout<<"FC Debug Report:"<<endl;
  cout<<"First Script["<<original_file_name<<"]"<<endl;
  cout<<"Current Script["<<file_name<<"]"<<endl;
  cout<<"Current Script Length["<<active_script.size()<<"]"<<endl;
  cout<<"Adapted Threads["<<adapted_threads<<"]"<<endl;
  cout<<"Known Threads["<<known_threads<<"]"<<endl;
  cout<<"Current Thread["<<thread_label<<"]"<<endl;
  cout<<"Encountered Depricated Features["<<deprications<<"]"<<endl;
  cout<<"Maximum Permited Errors["<<error_cap<<"]"<<endl;
  cout<<"Current Errors Level["<<error_level<<"]"<<endl;
  cout<<"Error Level Tracer["<<error_trace<<"]"<<endl;
  cout<<"Codex ID["<<codex_id<<"]"<<endl;
}
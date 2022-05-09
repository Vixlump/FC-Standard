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

inline void error_handler() {
  cout<<"Error["<<"N="<<file_name<<" "<<error_trace<<"]"<<endl;
      string error_manager;
      cout<<"**Error was detected, debug mode is active, entering error manager**"<<endl;
      cout<<"**Note: current FC error checking is out of date and rarely informs of the correct error**"<<endl;
      cout<<"**Type _help for a list of commands, or type _exit to terminate the program**"<<endl;
      do {
        error_manager == "";
        cout<<"**[Error Manager - "<<fc_version<<"]~";
        cin>>error_manager;
        cout<<"**"<<endl;
        if (error_manager=="_help") {
          cout<<"**Commands:**"<<endl;
          cout<<"**[_continue] skip this error and continue program**"<<endl;
          cout<<"**[_trace] output current error information, L = Line Number, T = Thread Lable**"<<endl;
          cout<<"**[_codexid] output current program Codex ID**"<<endl;
          cout<<"**[_rawid] output raw hash(UIRN) that caused error**"<<endl;
          cout<<"**[_level] output number of detected errors**"<<endl;
          cout<<"**[_deprications] output number of detected deprications**"<<endl;
          cout<<"**[_dump] outputs raw hash information for current codex**"<<endl;
          cout<<"**[_jump] type a line within the program to jump to**"<<endl;
          cout<<"**[_view] view specific line in script**"<<endl;
          cout<<"**[_testid] check hash(UIRN) of input text**"<<endl;
          cout<<"**[_match] type string text and see if line matches hash(UIRN) info of error**"<<endl;
          cout<<"**[_script] output full text version of script**"<<endl;
          cout<<"**[_setlevel] set error level to new value**"<<endl;
          cout<<"**[_exit] terminate program**"<<endl;
          cout<<"**[_help] output index of error manager commands**"<<endl<<endl;
        } else if (error_manager=="_continue"||error_manager=="_skip") {
          break;
        } else if (error_manager=="_trace") {
          cout<<error_trace<<endl;
        } else if (error_manager=="_codexid") {
          cout<<"**Current Codex ID["<<codex_id<<"]**"<<endl;
        } else if (error_manager=="_rawid") {
          cout<<"**Error Was Triggered By UIRN["<<active_script[line]<<"]**"<<endl;
        } else if (error_manager=="_level") {
          cout<<"**Current Error Level["<<error_level<<"]**"<<endl;
        } else if (error_manager=="_deprications") {
          cout<<"**Current Deprications["<<deprications<<"]**"<<endl;
        } else if (error_manager=="_dump") {
          for (uint64_t i = 0; i < active_script.size(); i++) {
            cout<<"**UIRN["<<active_script[i]<<"] Line["<<i<<"]**"<<endl;
          }
        } else if (error_manager=="_jump") {
          cout<<"**Current line is["<<line<<"] Type line to jump to: ";
          error_manager = "";
          cin>>error_manager;
          line = stoull(error_manager.c_str());
          cout<<"**"<<endl<<"**line is now["<<line<<"]**"<<endl;
        } else if (error_manager=="_view") {
          cout<<"**Type line to view: ";
          error_manager = "";
          cin>>error_manager;
          cout<<"**"<<endl<<"**Text["<<script_reader[stoull(error_manager.c_str())]<<"] Text UIRN["<<COREFC(script_reader[stoull(error_manager.c_str())].c_str())<<"]**"<<endl;
        } else if (error_manager=="_testid") {
          cout<<"**Type string to convert to UIRN: ";
          error_manager = "";
          cin>>error_manager;
          cout<<"**"<<endl<<"**UIRN of string is["<<COREFC(error_manager.c_str())<<"]**"<<endl;
        } else if (error_manager=="_match") {
          cout<<"**Type string to compare to problem UIRN: ";
          error_manager = "";
          cin>>error_manager;
          cout<<"**"<<endl<<"**UIRN of string is["<<COREFC(error_manager.c_str())<<"] Problem UIRN is["<<active_script[line]<<"]**"<<endl;
          if (COREFC(error_manager.c_str())==active_script[line]) {cout<<"**[TRUE] string and error ARE the same**"<<endl;} else {cout<<"**[FALSE] string and error are NOT the same**"<<endl;}
        } else if (error_manager=="_script") {
          for (uint64_t i2 = 0; i2<script_reader.size(); i2++) {
            cout<<"**Text["<<script_reader[i2]<<"] Line["<<i2<<"]**"<<endl;
          }
        } else if (error_manager=="_setlevel") {
          cout<<"**Current Error Level is["<<error_level<<"] Type Error Level to set: ";
          error_manager = "";
          cin>>error_manager;
          error_level = stoull(error_manager.c_str());
          cout<<"**"<<endl<<"**Error Level is now["<<error_level<<"]**"<<endl;
        } else if (error_manager=="_exit"||error_manager=="_quit") {
          terminate_all();
        } else {
          cout<<"**Error:"<<error_manager<<" is not a valid command**"<<endl;
          cout<<"**Type _help for a list of commands, or type _exit to terminate the program**"<<endl;
        }
      } loop;
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
    if (error_debug_mode==true) {
      error_handler();
    }
}

#pragma once
#define FCS_X

void xternal_file();
void xternal_address();
void xternal_web();

void xternal_stream() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("+file"):
				xternal_file();
				break;
			case COREFC("+address"):
				xternal_address();
				break;
			case COREFC("+python"):
				break;
			case COREFC("+shell"):
				{
					fc_getline();
					string input = "_shell" + to_string(thread_label);
					codex_store_int32(COREFC(input.c_str()), system(codex_get_string(active_script[line]).c_str()));
					break;
				}
			case COREFC("+web"):
				#ifdef ASPECTUFXTOOLS
				xternal_web();
				#endif
				break;
			//standard:
       		case COREFC("x*")://sexit
        	case COREFC("~~~*")://uexit
          		return;
        	case COREFC("%")://abstract register
          		abstract_register();
          		break;
        	case COREFC("**")://debug point
          		debug_point();
          		break;
        	case COREFC("")://whitespace
        	case COREFC("*null")://do nothing
          		fc_nothing();
          		break;
        	case COREFC("*~~~")://channelswap stream
          		channelswap_stream();
          		break;
      		default:
        		error_stream("*x->*error");
        		break;
		}
	} loop;
}

#ifdef ASPECTUFXTOOLS
size_t xternal_web_download_writedata(char *ptr, size_t size, size_t nmemb, void *userdata) {
    std::ofstream *out = static_cast<std::ofstream *>(userdata);
    size_t nbytes = size * nmemb;
    out->write(ptr, nbytes);
    return nbytes;
}

void xternal_web_download() {
	fc_getline();
	string input = codex_get_string(active_script[line]);
	fc_getline();
	uint64_t input2 = active_script[line];
	CURL *curl = NULL;
	CURLcode res;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, input.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, xternal_web_download_writedata);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &quantum_var[input2]);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
	}
}

void xternal_web() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_download"):
				xternal_web_download();
				break;
			case COREFC("_ret"):
				return;
			default:
				error_stream("+web->*error");
				break;
		}
	} loop;
}

#endif

void xternal_file_open() {
	uint64_t input;
	fc_getline();
	switch (active_script[line]) {
		case COREFC("_chart"):
			fc_getline();
			input = active_script[line];
			fc_getline();
			chart_var[input].open(codex_get_string(active_script[line]));
			break;
		case COREFC("_quantum"):
			fc_getline();
			input = active_script[line];
			fc_getline();
			quantum_var[input].open(codex_get_string(active_script[line]));
			break;
		case COREFC("_array"):
			{
				fc_getline();
				if (active_script[line]==COREFC("_chart")) {
					fc_getline();
					fc_getline();
					fc_getline();
					//chart_var_array[active_script[line-2]][codex_get_int64(active_script[line-1])].open(active_script[line]);
					break;
				} else if (active_script[line]==COREFC("_quantum")) {
					fc_getline();
					fc_getline();
					fc_getline();
					//quantum_var_array[active_script[line-2]][codex_get_int64(active_script[line-1])].open(active_script[line]);
					break;
				} else {
					error_stream("+file->_open->_array->*error");
				}
				break;
			}
		default:
			error_stream("+file->_open->*error");
			break;
	}
}
void xternal_file_close() {
	fc_getline();
	switch (active_script[line]) {
		case COREFC("_chart"):
			fc_getline();
			chart_var[active_script[line]].close();
			break;
		case COREFC("_quantum"):
			fc_getline();
			quantum_var[active_script[line]].close();
			break;
		default:
			error_stream("+file->_close->*error");
			break;
	}
}
void xternal_file_write() {
	fc_getline();
	uint64_t name = active_script[line];
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_text"):
				fc_getline();
				quantum_var[name]<<codex_get_string(active_script[line]);
				break;
			case COREFC("_end"):
				quantum_var[name]<<endl;
				break;
			case COREFC("_break"):
				quantum_var[name]<<"\n";
				break;
			case COREFC("_ret"):
				return;
			case COREFC("_line"):
				fc_getline();
				quantum_var[name]<<codex_get_string(active_script[line])<<"\n";
				break;
			default:
				fc_getline();
				quantum_var[name]<<codex_get_string(active_script[line])<<"\n";
				break;
		}
	} loop;
}
void xternal_file_read() {
	fc_getline();
	uint64_t name = active_script[line];
	fc_getline();
	switch (active_script[line]) {
		case COREFC("_line"):
			{
				string i;
				getline(chart_var[name], i);
				fc_getline();
				codex_store_string(active_script[line], i);
				break;
			}
		case COREFC("_all"):
			{
				fc_getline();
				uint64_t i2 = active_script[line];
				fc_getline();
				uint64_t i3 = active_script[line];
				string i5;
				while (getline(chart_var[i2], i5)) {
					codex_add_string_array(i3, i5);
				}
				break;
			}
		default:
			break;
	}
}
void xternal_file() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_read"):
				xternal_file_read();
				break;
			case COREFC("_write"):
				xternal_file_write();
				break;
			case COREFC("_open"):
				xternal_file_open();
				break;
			case COREFC("_close"):
				xternal_file_close();
				break;
			case COREFC("_ret"):
				return;
			default:
				error_stream("+file->*error");
				break;
		}
	} loop;
}

void xternal_address() {

}
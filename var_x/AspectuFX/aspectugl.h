map<uint64_t, vector<uint64_t>> buffer_render_var;

void AspectuGL() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("_setup"):
				break;
			case COREFC("_colour"):
				break;
			case COREFC("_shape"):
			case COREFC("_start"):
				break;
			case COREFC("_stop"):
				break;
			case COREFC("_background"):
				break;
			case COREFC("_translate"):
				break;
			case COREFC("_render"):
				break;
			case COREFC("_ret"):
				return;
			default:
				error_stream("+AspectuGL->*error");
				break;
		}
	} loop;
}

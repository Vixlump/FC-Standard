void AspectuGL() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("_colour"):
				break;
			case COREFC("_shape"):
			case COREFC("_start"):
				break;
			case COREFC("_stop"):
				break;
			case COREFC("_ret"):
				return;
			default:
				error_stream("+AspectuGL->*error");
				break;
		}
	} loop;
}

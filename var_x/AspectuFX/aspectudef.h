void AspectuDef() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_window"):
				break;
			case COREFC("_getinput"):
				break;
			case COREFC("_ret"):
				return;
			default:
				error_stream("+AspectuDev->*error");
				break;
		}
	} loop;
}

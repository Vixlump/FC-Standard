void AspectuNet() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_tcp"):
				break;
			case COREFC("_udp"):
				break;
			case COREFC("_ftp"):
				break;
			case COREFC("_url"):
				break;
			case COREFC("_ret"):
				return;
			default:
				error_stream("+AspectuNet->*error");
				break;
		}
	} loop;
}

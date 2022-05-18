void AspectuKit() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_ret"):
				return;
			default:
				error_stream("+AspectuKit->*error");
				break;
		}
	} loop;
}

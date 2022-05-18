void AspectuDef() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_window"):
				{
					fc_getline();
					uint64_t name = active_script[line];
					fc_getline();
					fc_getline();
					fc_getline();
					aspectu_def_window[name].aspectu_window = SDL_CreateWindow(
						codex_get_string(active_script[line-2]).c_str(),
						SDL_WINDOWPOS_UNDEFINED,
						SDL_WINDOWPOS_UNDEFINED,
						codex_get_int64(active_script[line-1]),
						codex_get_int64(active_script[line]),
						SDL_WINDOW_OPENGL);
					aspectu_def_window[name].aspectu_surface = SDL_GetWindowSurface(aspectu_def_window[name].aspectu_window);
					aspectu_def_window[name].aspectu_render = SDL_CreateRenderer(aspectu_def_window[name].aspectu_window,-1,SDL_RENDERER_ACCELERATED);
					break;
				}
			case COREFC("_ret"):
				return;
			default:
				error_stream("+AspectuDev->*error");
				break;
		}
	} loop;
}

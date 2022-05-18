void AspectuTest() {
	SDL_Window *window = NULL;                    // Declare a pointer
	SDL_Renderer *renderer = NULL;
    SDL_Init(SDL_INIT_EVERYTHING);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "Aspectu",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        1920,                               // width, in pixels
        1080,                               // height, in pixels
        SDL_WINDOW_SHOWN                  // flags - see below
    );
    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        cout<<"AspectuGL/SDL Had An Error:\n"<<SDL_GetError()<<"\n";
        return;
    }
    renderer =  SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_Rect rect; rect.x = 50; rect.y = 50; rect.w = 50; rect.h = 50;
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
}

#pragma once
#define FCS_A
#include "AspectuFX/aspectufx.h"
//Aspectu Dependancies
struct aspectu_type_system {
	SDL_Window * aspectu_window = NULL;
	SDL_Renderer * aspectu_render = NULL;
	SDL_Surface * aspectu_surface = NULL;
};

map <uint64_t, aspectu_type_system> aspectu_def_window;

void AspectuGL();
void AspectuDef();
void AspectuKit();
void AspectuAux();
void AspectuCont();
void AspectuNet();
void AspectuTest();

void aspectu_stream() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("+AspectuGL"):
				AspectuGL();
				break;
			case COREFC("+AspectuDef"):
				AspectuDef();
				break;
			case COREFC("+AspectuKit"):
				AspectuKit();
				break;
			case COREFC("+AspectuAux"):
				break;
			case COREFC("+AspectuCont"):
				break;
			case COREFC("+AspectuNet"):
				break;
			case COREFC("+AspectuTest"):
				AspectuTest();
				break;
			//standard:
       		case COREFC("a*")://sexit
        	case COREFC("~~~*")://uexit
          		return;
        	case COREFC("%")://abstract register
          		abstract_register();
          		break;
        	case COREFC("**")://debug point
          		debug_point();
          		break;
        	case COREFC("")://whitespace
          		break;
        	case COREFC("*~~~")://channelswap stream
          		channelswap_stream();
          		break;
          	case COREFC("@*")://assignment wrap
          		assignment_wrap();
          		break;
			default:
				error_stream("*a->*error");
				break;
		}
	} loop;
}

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
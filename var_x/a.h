#pragma once
#define FCS_A
#include "AspectuFX/aspectufx.h"
//Aspectu Dependancies
struct aspectu_type_system {
	SDL_Window * aspectu_window;
	SDL_Surface * aspectu_surface;
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
				error_stream();
				break;
		}
	} loop;
}

void AspectuDef() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("_window"):
				break;
			case COREFC("_ret"):
				return;
			default:
				error_stream();
				break;
		}
	} loop;
}
void AspectuKit() {

}

void AspectuTest() {
	SDL_Window *window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "Aspectu",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return;
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
}



void AspectuGL() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("_ret"):
				return;
			default:
				error_stream();
				break;
		}
	} loop;
}
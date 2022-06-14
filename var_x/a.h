#pragma once
#define FCS_A
#include "AspectuFX/aspectufx.h"
//Aspectu Dependancies
struct aspectu_type_system {
	//SDL_Window * aspectu_window = NULL;
	//SDL_Renderer * aspectu_render = NULL;
	//SDL_Surface * aspectu_surface = NULL;
};

map <uint64_t, aspectu_type_system> aspectu_def_window;

#include "AspectuFX/aspectugl.h"
#include "AspectuFX/aspectudef.h"
#include "AspectuFX/aspectukit.h"
void AspectuAux();
void AspectuCont();
#include "AspectuFX/aspectunet.h"
#include "AspectuFX/aspectutest.h"

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
				AspectuNet();
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
        	case COREFC("*null")://do nothing
          		fc_nothing();
          		break;
        	case COREFC("*~~~")://channelswap stream
          		channelswap_stream();
          		break;
			default:
				error_stream("*a->*error");
				break;
		}
	} loop;
}
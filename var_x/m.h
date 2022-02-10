#pragma once

void math_stream() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("+fun"):
			case COREFC("+function")://solves for one values
				break;
			case COREFC("+graph")://solves for multiple values
				break;
			case COREFC("+calculate")://preforms one mathematical function
				break;
			//standard:
       		case COREFC("m*")://sexit
        	case COREFC("~~~*")://uexit
          		return;
        	case COREFC("%")://abstract register
          		abstract_register();
          		break;
        	case COREFC("@*")://assignment wrap
          	assignment_wrap();
          		break;
        	case COREFC("**")://debug point
          		debug_point();
          		break;
        	case COREFC("")://whitespace
          		break;
        	case COREFC("*~~~")://channelswap stream
          		channelswap_stream();
          		break;
      		default:
        		error_stream();
        		break;
        }
	} loop;
}
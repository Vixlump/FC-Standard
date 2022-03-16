#pragma once
#define FCS_X

void xternal_stream() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("+file"):
				break;
			case COREFC("+address"):
				break;
			//standard:
       		case COREFC("x*")://sexit
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
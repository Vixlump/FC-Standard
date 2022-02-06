#pragma once

void reserved_stream() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("+tap"):
				break;
			case COREFC("+debug"):
				debug_info();
				break;
			case COREFC("+stop"):
			case COREFC("+exit"):
			case COREFC("+terminate"):
				exit(42);
				break;
			//standard:
       		case COREFC("r*")://sexit
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
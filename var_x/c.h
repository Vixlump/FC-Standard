#pragma once

void control_stream() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("+case"):
				break;
			case COREFC("+if"):
				break;
			case COREFC("+goto"):
				fc_getline();
				line = codex_get_assignment(active_script[line]);
				break;
			case COREFC("+loop"):
				break;
			case COREFC("+while"):
				break;
			case COREFC("+for"):
				break;
			case COREFC("+inspect"):
				break;
			//standard:
       		case COREFC("c*")://sexit
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
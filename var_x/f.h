#pragma once
#define FCS_F

void functional_time() {

}
void functional_hash() {

}

void functional_stream() {
	do {
		fc_getline();
		switch (active_script[line]) {
			case COREFC("+time"):
				functional_time();
				break;
			case COREFC("+hash")://64/32/16/8
				functional_hash();
				break;
			//standard:
       		case COREFC("f*")://sexit
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
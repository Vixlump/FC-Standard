#pragma once

//work in progress

struct fcint128 {uint64_t pos = 0;uint64_t neg = 0;};

bool fcint128_is_pos(fcint128 & value) {
	if (value.pos==0 && value.neg==0) {
		return true;
	} else if (value.pos>0 && value.neg==0) {
		return true;
	} else if (value.pos==0 && value.neg>0) {
		return false;
	} else {
		return true;
	}
}

inline fcint128 fcint128_add(fcint128 x, fcint128 y) {
	fcint128 reassembler_fcint128;
	if ((fcint128_is_pos(x)==true)&&(fcint128_is_pos(y)==true)) {
		reassembler_fcint128.pos = x.pos + y.pos;
		return reassembler_fcint128;
	} else if ((fcint128_is_pos(x)==true)&&(fcint128_is_pos(y)==false)) {
		if (x.pos => y.neg) {reassembler_fcint128.pos = x.pos - y.neg;} else if (x.pos < y.neg) {reassembler_fcint128.neg = y.neg - x.pos;}
		return reassembler_fcint128;
	} else if ((fcint128_is_pos(x)==false)&&(fcint128_is_pos(y)==true)) {
		if (x.pos => y.neg) {reassembler_fcint128.pos = x.pos - y.neg;} else if (x.pos < y.neg) {reassembler_fcint128.neg = y.neg - x.pos;}
		return reassembler_fcint128;
	} else if ((fcint128_is_pos(x)==false)&&(fcint128_is_pos(y)==false)) {
		reassembler_fcint128.neg = x.neg + y.neg;
		return reassembler_fcint128;
	}
}

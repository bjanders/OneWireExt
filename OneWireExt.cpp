#include "OneWireExt.h"

// owTempToStr()
// Converts a 1-Wire temperature device temperature 
// to a string with 0.1 preceission, without using
// floating point calculations
//
// Arguments:
// s: Target string, should be at least 7 bytes long "-xxx.x\0"
// 
void owTempToStr(char *s, short val) {
	char sign[2] = { 0, 0 };
	if (val < 0) {
		// Get two's complement and add the minus sign
		val = ~val + 1;
		sign[0] = '-';
	}
	// The decimal part is split up on 4 bits, i.e. 16 parts, 1000/16 = 62.5,
	// but 62 is sufficient for our needs and avoids floating point operations.
	// Add 50 to get proper rounding
	sprintf(s, "%s%d.%d", sign, val >> 4, ((val & 0xf) * 62 + 50) / 100);
}

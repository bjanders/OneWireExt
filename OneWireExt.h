#pragma once

const int OW_ADDRESS_LEN = 8;

const int OW_TEMP_READ_SCRATCH = 0xbe;
const int OW_TEMP_CONVERT = 0x44;

void owTempToStr(char *s, short val);

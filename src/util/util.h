#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>

int util_initialize(void);
int util_decode(char *in_s, char *out_s, FILE *out_f);
int util_encode(char *in_s, char *out_s);

#endif

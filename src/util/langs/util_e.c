#include <stdio.h>
#include "util_e.h"

static const char *map = "\0ET"
                         "IANM"
                         "SURW"
                         "DKGO"
                         "HVF\0"
                         "L\0PJ"
                         "BXCY"
                         "ZQ\0\0"
                         "54\0""3"
                         "\0\0\0""2"
                         "\0\0+\0"
                         "\0\0\0""1"
                         "6=/\0"
                         "\0\0\0\0"
                         "7\0\0\0"
                         "8\0""90"
                         "\0\0\0\0"
                         "\0\0\0\0"
                         "\0\0\0\0"
                         "?_\0\0"
                         "\0\0\"\0"
                         "\0.\0\0"
                         "\0\0@\0"
                         "\0\0'\0"
                         "\0-\0\0"
                         "\0\0\0\0"
                         "\0\0;!"
                         "\0(\0\0"
                         "\0\0\0,"
                         "\0\0\0\0"
                         ":\0\0\0"
                         "\0\0\0\0";
static char enc[128] = {0};

void initialize_e(void) {
    for (unsigned char i = 0, *ii = (char*)map; i < 128; ++i, ++ii) {
        enc[*ii] = i;
    }
}

int decode_e(char *in, char *out, char *offset, char *open_par) {
    static const char *map = "\0ET"
                             "IANM"
                             "SURW"
                             "DKGO"
                             "HVF\0"
                             "L\0PJ"
                             "BXCY"
                             "ZQ\0\0"
                             "54\0""3"
                             "\0\0\0""2"
                             "\0\0+\0"
                             "\0\0\0""1"
                             "6=/\0"
                             "\0\0\0\0"
                             "7\0\0\0"
                             "8\0""90"
                             "\0\0\0\0"
                             "\0\0\0\0"
                             "\0\0\0\0"
                             "?_\0\0"
                             "\0\0\"\0"
                             "\0.\0\0"
                             "\0\0@\0"
                             "\0\0'\0"
                             "\0-\0\0"
                             "\0\0\0\0"
                             "\0\0;!"
                             "\0(\0\0"
                             "\0\0\0,"
                             "\0\0\0\0"
                             ":\0\0\0"
                             "\0\0\0\0";
    char res = 0;
    char o = 1;
    if (*in == '|') {
        *out = ' ';
        *offset = o;
        return 0;
    }
    for (char *i = in; *i != '.'; ++i, ++o) {
        if (*i != '*' && *i != '=') {
            return 1;
        }
        res <<= 1;
        res += 1;
        res += *i == '=';
    }
    if (res < 128 && !map[res]) {
        return 1;
    }
    if (*open_par && map[res] == '(') {
        *out = ')';
        *open_par = 0;
    } else {
        if (!*open_par && map[res] == '(') {
            *open_par = 1;
        }
        *out = map[res];
    }
    *offset = o;
    return 0;
}

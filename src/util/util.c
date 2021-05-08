#include <string.h>
#include "util.h"
#include "langs/util_e.h"

#define LANG_ENG 0
#define LANG_JAP 1
#define LANG_CHN 2

int util_initialize(void) {
    initialize_e();
    return 0;
}

int util_decode(char *in_s, char *out_s, FILE *out_f) {
    if (!in_s && !out_s) {
        return 1;
    }
    char lang = LANG_ENG;
    char *cur_ptr = in_s;
    char buf[4] = {0};
    char offset = 0;
    char offset_out = 0;
    char *i = in_s;
    char *ii = out_s;
    char open_par_e = 0;
    for (; *i; i += offset) {
        switch (lang) {
        case LANG_ENG:
            offset_out = 1;
            if (decode_e(i, buf, &offset, &open_par_e)) {
                return 1;
            }
            break;
        }
        if (out_s) {
            memcpy(ii, buf, offset_out);
            ii += offset_out;
        }
        if (out_f) {
            fprintf(out_f, "%s", buf);
        }
    }
    if (out_s) {
        *ii = 0;
    }
    if (out_f) {
        fputc(10, out_f);
    }
    return 0;
}

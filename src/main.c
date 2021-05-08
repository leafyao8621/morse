#include "util/util.h"

int main(void) {
    char buf[1000];
    int ret = util_decode("***.===.***.|*=**.*.*=.**=*.|"
                          "===**.=****.**===.*====.|"
                          "*=*=*.=***=.=**=*.|"
                          "**==**.**==*=.|"
                          "=*==*=.**===.*=*=*."
                          "***==.=*==*=.=**=*.*****."
                          "=***=.*====.", buf, stdout);
    printf("ret: %d\n", ret);
    printf("buf: %s\n", buf);
    util_initialize();
    return 0;
}

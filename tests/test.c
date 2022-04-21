#include <stdio.h>

#include "skrivarn.h"

int main() {

    skrivarn_trace("This is a trace");
    skrivarn_info("This is an info");
    skrivarn_warn("This is a warning");
    skrivarn_error("This is an error");

    return 0;
}

#include "myassert.h"
#include <stdio.h>
#include <stdlib.h>

void myfassert(char *msg)
{
    fputs("Assertion failed", stderr);
    fputs(msg, stderr);
    abort();
}

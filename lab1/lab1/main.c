#include <stdio.h>
#include "taylor.h"

int main(int argc, const char * argv[]) {
    
    printf("%lf",  fsqrt(1.2));
    printf("\n%lf",  fsqrt_erro(1.6));
    printf("\n%lf",  fcossin(0.2));
    printf("\n%lf", fcossin_erro(0.3));
    return 0;
}

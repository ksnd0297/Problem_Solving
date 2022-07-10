#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a = 17;

    clock_t s = 0, e = 0;
    int c = 0;
    int p = 0;

    s = clock();
    p = 0;
    for (unsigned long long int i = 0; i < 100; i++) {
        sleep(1);
        a -= (a >> 3 << 3);
        p = p + 1;
    }
    e = clock();
    printf("%lf\n", (double)(e - s));

    s = clock();
    // for(int i = 0 ; i < 100000000; i ++) {c = (a >> 3 << 3);}
    for (unsigned long long int i = 0; i < 100000000; i++) { 
        c = a % 8; 
        p = p + 1;
    }
    e = clock();
    printf("%lf\n", (double)(e - s));


    return 0;
}
#include <stdio.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

uint_fast64_t FastExpo(uint_fast64_t a, uint_fast64_t b, uint_fast64_t m) {
    a = a%m;
    if(b==0) {
        return 1;
    } else if(b==1) {
        return a;
    } else if (b%2 == 0) {
        return FastExpo(a*a%m, floor(b/2), m); 
    } else {
        return a*FastExpo(a, b-1, m)%m;
    }
}

bool Witness(uint_fast64_t a, uint_fast64_t n) {
    uint_fast64_t u = n-1;
    uint_fast64_t t = 0;
    uint_fast64_t xNext;

    while ( ((u >> 1) << 1) == u) {
        u >>= 1;
        t++;
    }
    uint_fast64_t x0 = FastExpo(a, u, n);

    for (int i = 1; i <= t; i++) {
        xNext = (x0*x0) % n;
        if (xNext == 1 && x0 != 1 && x0 != n-1) {
            return true;
        }
        x0 = xNext;
    }

    if(xNext != 1) {
        return true;
    }
    
    return false;
}

bool MillRab(uint_fast64_t n, int s) {
    for(int i = 1; i <= s; i++) {
        uint_fast64_t a =  (uint_fast64_t) ((rand() % (n-1)) + 1);
        if (Witness(a, n)) {
            return true;
        }
    }
    return false;
}

int main(int argc, char * argv[]) {
    bool isComposite;

    if(strcmp(argv[1], "-n") != 0 || ((strcmp(argv[3], "-a") != 0) && (strcmp(argv[3], "-s") != 0))) {
        printf("please enter numbers in right order of format: ./ \n");
        return 0;
    }
    if (strcmp(argv[3], "-a") == 0) {
        uint_fast64_t n = strtoull(argv[2], NULL, 10);
        uint_fast64_t a = strtoull(argv[4], NULL, 10);
        isComposite = Witness(a, n);
        if (!isComposite) {
            printf("%llu is prime according to Witness \n", n);
        } else {
            printf("%llu is not prime according to Witness \n", n);
        }
    } else {
        uint_fast64_t n = strtoull(argv[2], NULL, 10);
        uint_fast64_t s = strtoull(argv[4], NULL, 10);
        isComposite = MillRab(n, s);
        if (!isComposite) {
            printf("%llu is prime according to Witness \n", n);
        } else {
            printf("%llu is not prime according to Witness \n", n);
        }
    }
    return 0;
}
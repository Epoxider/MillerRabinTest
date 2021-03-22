#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

uint_fast64_t FastExpo(uint_fast64_t a, uint_fast64_t b, uint_fast64_t m) {
    a = a%m;
    if(b==0) {
        return 1;
    } else if(b==1) {
        return a;
    } else if (b%2 == 0) {
        return FastExpo(a*a%m, b/2, m); 
    } else {
        return a*FastExpo(a, b-1, m)%m;
    }
} 
  
int main(int argc, char * argv[]) { 

    clock_t start = clock();

    uint_fast64_t a = strtoull(argv[1], NULL, 10);
    uint_fast64_t b = strtoull(argv[2], NULL, 10);
    uint_fast64_t m = strtoull(argv[3], NULL, 10);
    uint_fast64_t answer = FastExpo(a, b, m);

    clock_t end = clock();
    
    double time = (double) (end-start)/CLOCKS_PER_SEC;

    printf("Answer is: %llu \n", answer);
    printf("time spend: %.6f \n", time);

    return 0; 
}
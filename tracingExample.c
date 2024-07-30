#include <stdio.h>
#include <stdlib.h>

int main(){
    
int factor1, factor2;
factor1 = 1;
factor2 = 1;

while (factor1 * factor2 < 100) {
    printf("%d\n", factor1 * factor2);
    if (factor1 > factor2) { /* If factor1 is larger increment factor2, and vice versa */
        factor2 = factor2 + 1;
    } else {
        factor1 = factor1 + 1;
    }
}

printf("All done!\n");
}
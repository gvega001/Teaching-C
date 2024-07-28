#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int foo(int x, int y) {
	return x + y;
}

void print_if(int xs[10], bool (*predicate)(int)) {
    for (int i = 0; i < 10; i++) {
        if (predicate(xs[i])) {
            printf("%d\n", xs[i]);
        }
    }
}

bool p(int x) {
    return x % 2 == 0;
}

int main(void) {
	int xs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	int (*f)(int, int) = foo; 
	
	printf("%d\n", f(3, 4));
	
	return 0;
}
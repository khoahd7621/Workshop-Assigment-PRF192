//Enter a positive integer then print out its factorial

#include <stdio.h>

double factorial( int n) {
    double p = 1;
    int i;
    for (i = 2; i <= n; i++) p *= i;
    return p;
}

int main () {
    int n;
	printf("Enter a positive integer: ");	
    do {
        scanf("%d", &n);
	}
    while (n < 0);
        printf("%lf", factorial(n));
return 0;
}


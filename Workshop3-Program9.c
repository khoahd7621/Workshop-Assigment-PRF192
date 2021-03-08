//Enter two positive integers then print out
//their greatest common divisor and least common multiple

#include <stdio.h>

int gcd (int a, int b) {
    while ( a != b ) {
    if (a > b) a -= b;
    else b -= a; 
	}
    return a;
}

int lcm (int a, int b) {
	return a*b/gcd(a,b);
}

int main () {
	int a, b, d, m;
	printf("Enter two positive integers: ");
	do {
	scanf("%d%d", &a, &b);
    }
    while ( a <= 0 || b <= 0);
    d = gcd(a,b);
    m = lcm(a,b);
    printf("Greatest common divisor of %d and %d: %d\n", a, b, d);
    printf("Least common multiple of %d and %d: %d\n", a, b, m);
return 0;
}


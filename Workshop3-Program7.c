//Print out the sum of nonnegative integer decimal digits

#include <stdio.h>

int sumDigits(int n) {
    int sum = 0;
    while (n >= 0){
	int temp = n % 10;
	       n = n / 10;
	     sum = sum + temp;
	}
    return sum ;
}
int main () {
	int n = 2, s;
	printf("Enter number: ");
	do {
	    scanf("%d", n);
	    if ( n >= 0) {
	    s = sumDigits(n);
	    }
    }
    while (n >= 0);
	printf("Sum of %d decimal digits: %d", n, s);
return 0;
}


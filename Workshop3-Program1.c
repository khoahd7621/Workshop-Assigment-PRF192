//Accept a positive integer n, n>=2
//then print out primes between 2 and n

#include <stdio.h>
#include <math.h>

int prime(int n) {
	int m = sqrt(n);
	int s = 1;
    int i;
    if (n < 2) s = 0;
    for (i = 2; i <= m; i++)
        if (n % i == 0) {
		s = 0;
		}
    return s; 
}

int main ()
{
	int n, i, s;
    printf("Enter positive interger: ");
    scanf("%d", &n);
	printf("Prime numbers between 2 and %d are: ", n);
	if ( n <= 3)
		printf("Error! Condition is not satisfied or between two numbers do not have integer.");
	for ( i = 3; i < n; i++)
	{
	    s = prime(i);
        if (s == 1)
        printf("%d ", i);
    }
    return 0;
}

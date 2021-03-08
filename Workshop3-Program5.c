//Print out the value at the nth position in Fibonacci sequence

#include <stdio.h>

double fibo(int n) {
    int t1 = 1, t2 = 1, f = 1;
    int i;
    for (i = 3; i <= n; i++) {
        f  = t1 + t2;
        t1 = t2;
        t2 = f;
    }
 return f;
} 

int main () {
	int n; 
	printf("Enter the nth element in the Fibonacci sequence: "); 
	do {
	scanf("%d", &n); 
	}
    while (n < 1);
    printf("%lf", fibo(n));
return 0;
}


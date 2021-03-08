//Enter a non-negative integer then print
//out its minimum and maximum digits

#include <stdio.h>

void printMinMaxDigits(int n) {                              
     int max, min;
     max = n % 10;
	 min = n % 10;
	 while( n > 0) {
		int temp = n % 10;
		       n/=10;
		if ( max < temp) {
			 max = temp;
		}
		if ( min > temp) {
			 min = temp;
		}
     }
     printf("Minimum of digits: %d\n", min);
     printf("Maximum of digits: %d\n", max);    
}

int main () {
	int n;
	printf("Enter integer: ");
	scanf("%d", &n);
	printMinMaxDigits(n);
return 0;
}


//Enter the integral part and fraction of a real 
//number then print out the this real number

#include <stdio.h>

double makeDouble(int ipart, int fraction) {
    double df = fraction;
    while (df >= 1) df = df / 10;
    if ( ipart < 0) return ipart - df;
    else return ipart + df;
}

int main () {
	int ipart, fraction;
	double value;
	printf("Enter ipart of real number: ");
	scanf("%d", &ipart);
	printf("Enter fraction of real number: ");
	do {
	scanf("%d", &fraction); 
	}
    while (fraction < 0);
    value = makeDouble(ipart,fraction);
    printf("%lf", value);
return 0;
}


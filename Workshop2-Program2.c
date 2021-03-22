//Program 2: Yearly Personal Income Tax

#include <stdio.h>
#include <stdlib.h>

int main()
{
	long pa = 9000000, pd = 3600000;
	long tf, n, ti, m;
	printf("Your income this year: ");
	scanf("%ld", &m);
	printf("Number of dependents: ");
	scanf("%ld", &n);
	tf = 12 * (pa + n * pd);
	printf("Tax-free income: %ld\n", tf);
	ti = m - tf;
	if (ti <= 0)
	{
		printf("Taxable income: 0\n");
		printf("Income tax: 0\n");
	}
	else if (ti > 0 && ti <= 5000000)
	{
    		printf("Taxable income: %ld\n", ti);
    		printf("Income tax: %ld\n", ti*5/100);
	}
	else if (ti >= 5000001 && ti <= 10000000)
	{
    		printf("Taxable income: %ld\n", ti);
    		printf("Income tax: %ld\n", ti*10/100);
	}
    	else if (ti >= 10000001 && ti <= 18000000)
	{
    		printf("Taxable income: %ld\n", ti);
    		printf("Income tax: %ld\n", ti*15/100);
	}
    	else
	{
		printf("Taxable income: %ld\n", ti);
    		printf("Income tax: %ld\n", ti*20/100);
	}
	return 0;    
}

//Write a program that will accept a number (>=1 000 000 000)
//then show whether the number is an ISBN or not.

#include <stdio.h>
#include <stdlib.h>

int checkISBN(int n) 
{
	int N[10];
	int C[9];
	int T = 0;
	int i, j;
	for (i = 9; i >= 0; i--)
	{
		N[i] = n % 10;
		n = n / 10;
	}
	for (i = 0; i < 9; i++)
		for (j = i; j < i+1; j++)
		{
			C[j] = N[i]*(10-i);
			T += C[j];
		}
	T += N[9];
	if ((T % 11) == 0)
		printf("This is a valid ISBN!\n");
	else
		printf("This is not a valid ISBN!\n");
}

int main() {
	int n, check;
	check = 1;
	printf("ISBN Validator\n==============\n");
	while (check == 1) {
		do 
		{
			printf("Enter ISBN (0 to exit): ");
			scanf("%d", &n);
			if (n < 0)
				printf("Wrong input!!! Enter again!\n");
		}
		while (n < 0);
		if (n != 0)
			checkISBN(n);
		else check = 0;
	}
	printf("Bye! Have a nice day!");
	return 0;
}

/*
Develop a C-program that helps user managing an 1-D array of real numbers(maximum of 100 elements) , 
with initial number of elements is 0, using the following simple menu:
1- Add  a value
2- Search a value
3- Print out the array 
4- Print out values in a range
5- Print out the array in ascending order 
Others- Quit
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100

int menu()
{   
	int choice;
	printf("\n==========================MENU=========================");
	printf("\n| 1- Add a value                             Press: 1 |");
	printf("\n| 2- Search a value                          Press: 2 |");
	printf("\n| 3- Print out the array                     Press: 3 |");
	printf("\n| 4- Print out values in a range             Press: 4 |");
	printf("\n| 5- Print out the array in ascending order  Press: 5 |");
	printf("\n| 6- Quit                                    Press: 6 |");
	printf("\n=======================================================\n");
	printf("\nEnter Your Choice: ");
	scanf("%d", &choice);
	return choice;
}

int isFull(int n)
{
	return n == MAX_VALUE;
}

int isEmpty(int n)
{
	return n == 0;
}

void add(int*a, int*pn)
{
	int value;
	printf("\nInput an added value: ");
	scanf("%d", &value);
	a[*pn] = value;
	(*pn)++;
}

void search(int*a, int n)
{
	int x, t = -1;
	printf("\nInput the search value: ");
	scanf("%d", &x);
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == x)
			t = i;
	if (t < 0)
		printf("\nNot found!\n");
	else
		printf("\nPosition is found: %d\n", t);
}

void printArray(int*a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		j = a[i];
		printf("%d ", j);
	}
}

void printRange(int*a, int n)
{
	int maxVal, minVal, t = -1;
	printf("\nEnter the range [a..b]:\n");
	printf("\na = ");
	scanf("%d", &minVal);
	printf("\nb = ");
	scanf("%d", &maxVal);
	printf("\n");
	int i;
	for (i = 0; i < n; i++)
		if (a[i] >= minVal && a[i] <= maxVal)
		{
			printf("%d ", a[i]);
			t = i;
		}
	if ( t < 0)
		printf("No value between range!\n");
}

void printASC(int*a, int n)
{
	int** adds = (int**)calloc(n, sizeof(int*));
	int i, j;
	for (i = 0; i < n; i++)
		adds[i] = &a[i];
	int*t;
	for (i = 0; i < n - 1; i ++)
		for ( j = n - 1; j > i; j--)
	 		if (*adds[j] < *adds[j-1])
	 		{
	 			t = adds[j];
	 			adds[j] = adds[j-1];
	 			adds[j-1] = t;
			}
	for (i = 0; i < n; i++)
		printf("%d ", *adds[i]);
	free(adds);
}

int main()
{
	int a[MAX_VALUE];
	int n = 0;
	int userChoice, check = 1;
    do
    {
		userChoice = menu();
    	switch(userChoice)
		{
			case 1:
				if (isFull(n))
					printf("\nSorry! The Array is full!\n");
				else
				{
					add(a, &n);
					printf("\nAdded!\n");
				}
		        break;
		    case 2:
		    	if (isEmpty(n))
					printf("\nSorry! The Array is empty!\n");
				else
					search(a, n);
			    break;
			case 3:
				if (isEmpty(n))
					printf("\nSorry! The Array is empty!\n");
				else
					printArray(a, n);
				break;
			case 4:
				if (isEmpty(n))
					printf("\nSorry! The Array is empty!\n");
				else
					printRange(a, n);
				break;
			case 5:
				if (isEmpty(n))
					printf("\nSorry! The Array is empty!\n");
				else
					printASC(a, n);
				break;
		    default:
		    	if (userChoice == 6)
		    		check = 0;
		    	else 
					printf("\n>>>Wrong input!!!!\n");					
	    }
	}
	while (check == 1);
	printf("\nGood Bye!");
	getch();
}

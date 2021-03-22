//Program 3: Print out sum of integers

#include <stdio.h>

int main()
{
    int a, sum = 0; 
    printf("Enter integers number: ");
    while (a != 0)
    {
    	scanf("%d", &a);
        sum = sum + a;
    }
    printf("Sum of integers entered: %d", sum);
    return 0;
}

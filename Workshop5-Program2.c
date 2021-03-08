#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int intRandom()
{
	srand(time(NULL));
	int random = 1 + rand()%10;
	return random;
}

int main() {
	int total, x, y, z; 
	int count1, count2, a, b;
	printf(" Ball Lottery \n");
	printf("==============\n");
	printf("Total sought: ");
    do
    {
	    scanf("%d", &total);
    }
    while (total < 2 || total > 20);
    count1 = 1;
    count2 = 2;
    do
    {   
    	x = intRandom();
	    for (a = 1; a <= 20000; a++)
            for (b = 1; b <= 20000; b++)
	        {}
    	y = intRandom();
    	for (a = 1; a <= 20000; a++)
            for (b = 1; b <= 20000; b++)
	        {}
        z = x + y;
        printf("Result of picks %d and %d: %d + %d\n", count1, count2, x, y);
        count1++;
        count2++;
    }
    while (z != total);
    count2 -= 1;
    printf("You got your total in %d picks!\n", count2);
    printf("Bye! Sayonara!!!\n");
    getch();
}

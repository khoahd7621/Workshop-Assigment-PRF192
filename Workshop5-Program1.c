#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int intRandom()
{
	srand(time(NULL));
	int random = 1 + rand()%6;
	return random;
}

int main() {
	int total, x, y, z, a, b, count;
	printf(" Dice Thrower \n");
	printf("==============\n");
	printf("Total sought: ");
    do
    {
	    scanf("%d", &total);
	    if (total < 2 || total > 12)
	    	printf("Total must be an integer in range [2..12]\n");
	    	printf("Total sought: ");
    }
    while (total < 2 || total > 12);
    count = 1;
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
        printf("Result of throw %d: %d + %d\n", count, x, y);
        count++;
    }
    while (z != total);
    count -= 1;
    printf("You got your total in %d throws!\n", count);
    printf("Bye! Sayonara!!!\n");
    getch();
}

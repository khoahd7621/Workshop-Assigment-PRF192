#include <stdio.h>
#include <math.h>

int getUserChoice()
{   int choice;
	printf("\n==================MENU=======================");
	printf("\n| 1. Quadratic equation.     Press: 1       |");
	printf("\n| 2. Bank deposit problem.   Press: 2       |");
	printf("\n| 3. Exit the program.       Press: Anykeys |");
	printf("\n=============================================\n");
	printf("\nEnter Your Choice: ");
	scanf("%d%*c", &choice);
	return choice;
}

void quadEquation()
{
	float a, b, c, d, x, y;
	printf("\nQuadratic equation: ax^2 + bx + c = 0 (a different from 0)\n");
	printf("\nPlease enter coefficient a, b, c: ");
	scanf("%f%f%f", &a, &b, &c);
	if (a != 0) {
		d = b*b - 4*a*c;
		if (d == 0)
			printf("\nEquation has double solution x1 = x2 = %f\n", -b/(2*a));
		else if ( d >= 0)
			printf("\nEquation has two real solutions: x1 = %f, x2 = %f\n", (-b+sqrt(d))/(2*a), (-b-sqrt(d))/(2*a));
		else printf("\nEquation has no solution!\n");
	}
	else printf("\nWrong condition of a!\n");
}

void bank() {
	float x, y, z, m;
	do {
	printf("\nEnter your deposit: ");
	scanf("%f", &x);
    }
    while (x <= 0);
	do {
	printf("\nEnter yearly rate (between 0.1 and 1.0): ");
	scanf("%f", &y);
    }
    while (y <= 0 || y > 1);
    do {
	printf("\nEnter number of year: ");
	scanf("%f", &z);
    }
    while (z <= 0);  
    m = x*pow(1+y,z);
    printf("\nYour amount after this duration: %f\n", m); 
}

int main()
{   int userChoice;
    do
    {   userChoice = getUserChoice();
        switch(userChoice)
		{   case 1: quadEquation();
		            break;
		    case 2: bank();
			        break; 
		    default: printf("\nGood Bye!");
	    }
	}
	while (userChoice>0 && userChoice<3);
	return 0;
}

#include <stdio.h>

int getUserChoice()
{   int choice;
	printf("\n==========================MENU==============================");
	printf("\n| 1. Processing date data.                  Press: 1       |");
	printf("\n| 2. Character data.                        Press: 2       |");
	printf("\n| 3. Exit the program.                      Press: Anykeys |");
	printf("\n============================================================\n");
	printf("\nEnter Your Choice: ");
	scanf("%d%*c", &choice);
	return choice;
}

int validDate(int d, int m, int y)
{	
    int maxd = 31;
    if ((d < 1) || (d > 31) || (m < 1) || (m > 12))
    return 0;
    if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
        maxd = 30;
    if ( m == 2) {
        if ((y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)))
 	    maxd = 29;
        else
        maxd = 28;
	}
	return d <= maxd;	 
}

void date()
{
	int d, m, y, s;
	printf("\nEnter day, month, year: ");
	scanf("%d%d%d", &d, &m, &y);
	s = validDate(d,m,y);
	if ( s == 1)
	    printf("\nValid Date!");
	else
	    printf("\nInvalid Date!");
}

void data()
{
	char c1, c2, t, c;
    printf("Enter character 1: ");
    scanf("%c",&c1);
    fflush(stdin);     
    printf("Enter character 2: ");
    scanf("%c",&c2);  
    if ( c1 > c2 )
    {    	
        t = c1; 
        c1 = c2; 
        c2 = t;
    }
    for( c = c1; c <= c2; c++)
	{
        printf("%c: %d, %xh\n", c, c, c);
    }
}

int main()
{   int userChoice;
    do
    {   userChoice = getUserChoice();
        switch(userChoice)
		{   case 1: date();
		            break;
		    case 2: data();
			        break; 
		    default: printf("\nGood Bye!");
	    }
	}
	while (userChoice>0 && userChoice<3);
	return 0;
}

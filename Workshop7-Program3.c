//Develop a C-program that allows user:
//– Adding a new soft drink
//– Printing out items which belong to a known make.
//– Printing out items whose volumes are between v1 and v2 ( integers)
//– Printing the list in ascending order based on volumes then prices

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100
#define MAXL 20

int menu()
{   
	int choice;
	printf("\n==================================== M E N U ======================================");
	printf("\n| 1- Add a new soft drink.                                               Press: 1 |");
	printf("\n| 2- Printing out items which belong to a same origin. (Country)         Press: 2 |");
	printf("\n| 3- Printing out items whose volumes are between [(ml)__and__(ml)].     Press: 3 |");
	printf("\n| 4- Printing the list in ascending order based on volumes then prices.  Press: 4 |");
	printf("\n| 5- Quit.                                                               Press: 5 |");
	printf("\n===================================================================================\n");
	printf("\nEnter Your Choice: ");
	scanf("%d", &choice);
	fflush(stdin);
	return choice;
}

int isFull(int n)
{
	return n == MAXN;
}

int isEmpty(int n)
{
	return n == 0;
}

char* lTrim(char s[])
{
	int i = 0;
	while (s[i] == ' ')	i++;
	if (i > 0) strcpy(&s[0], &s[i]);
	return s;
}

char* rTrim(char s[])
{
	int i = strlen(s)-1;
	while (s[i] == ' ') i--;
	s[i+1] = '\0';
	return s;
}

char* trim(char s[])
{
	rTrim(lTrim(s));
	char *ptr = strstr(s, "  ");
	while (ptr != NULL)
	{
		strcpy(ptr, ptr+1);
		ptr = strstr(s, "  ");
	}
	return s;
}

char* nameStr (char s[])
{
	trim(s);
	strlwr(s);
	int L = strlen(s);
	int i;
	for (i = 0; i < L; i++)
		if (i == 0 || (i > 0 && s[i-1] == ' '))
			s[i] = toupper(s[i]);
	return s;
}

void addSoftDrink(char name[][MAXL], char make[][MAXL], int volume[], int price[], int duration[], int *pn)
{
	char names[MAXL], makes[MAXL];
	int volumes, prices, durations;
	printf("\n--Enter Information Of Soft Drinks--\n");
	printf("Name: ");
	scanf("%[^\n]", names);
	fflush(stdin);
	printf("Made in: ");
	scanf("%[^\n]", makes);
	fflush(stdin);
	printf("Volume (ml): ");
	scanf("%d", &volumes);
	printf("Price (VND): ");
	scanf("%d", &prices);
	printf("Duration (Days): ");
	scanf("%d", &durations);
	printf("\nAdded!\n");
	nameStr(names);
	nameStr(makes);
	strcpy(name[*pn], names);
	strcpy(make[*pn], makes);
	volume[*pn] = volumes;
	price[*pn] = prices;
	duration[*pn] = durations;
	(*pn)++;
}

void printList(char name[][MAXL], char make[][MAXL], int volume[], int price[], int duration[], int n)
{
	printf("\nName: %s\n", name[n]);
	printf("Made in: %s\n", make[n]);
	printf("Volume: %d ml\n", volume[n]);
	printf("Price: %d VND\n", price[n]);
	printf("Duration: %d Days\n", duration[n]);
}

void printBaseMake(char name[][MAXL], char make[][MAXL], int volume[], int price[], int duration[], int n)
{
	char makes[MAXL];
	printf("\nEnter origin of soft drink you wanna print: ");
	scanf("%[^\n]", makes);
	fflush(stdin);
	nameStr(makes);
	int i, check;
	check = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(makes, make[i]) == 0)
		{
			printf("\n>>List of Soft Drink base on %s:\n", make[i]);
			printList(name, make, volume, price, duration, i);
			check = 1;
		}
	}
	if (check == 0)
		printf("\nThere are not any soft drinks on the list based on %s!!!\n", makes);
}

void printBaseVol(char name[][MAXL], char make[][MAXL], int volume[], int price[], int duration[], int n)
{
	int maxVol, minVol;
	printf("\nEnter the MIN and MAX mil of soft drinks you wanna print: \n");
	printf("Min (ml): ");
	scanf("%d", &minVol);
	printf("Max (ml): ");
	scanf("%d", &maxVol);
	int i, check = 0;
	for (i = 0; i <= n; i++)
		if ((volume[i] >= minVol) && (volume[i] <= maxVol))
		{
			printList(name, make, volume, price, duration, i);
			check = 1;
		}
	if (check == 0)
		printf("\nThere are not any soft drinks between %d ml and %d ml!!!\n", minVol, maxVol);
}

void printAsc(char name[][MAXL], char make[][MAXL], int volume[], int price[], int duration[], int *pn)
{
	int i, j;
	for (i = 0; i < (*pn)-1; i++)
	{
		for (j = (*pn)-1; j > i; j--)
		{
			if (price[j]+duration[j] < price[j-1]+duration[j-1])
			{
				char transName[MAXL];
				strcpy(transName, name[j-1]);
				strcpy(name[j-1], name[j]);
				strcpy(name[j], transName);
				
				char transMake[MAXL];
				strcpy(transMake, make[j-1]);
				strcpy(make[j-1], make[j]);
				strcpy(make[j], transMake);
				
				int transVol;
				transVol = volume[j-1];
				volume[j-1] = volume[j];
				volume[j] = transVol;
				
				int transPri;
				transPri = price[j-1];
				price[j-1] = price[j];
				price[j] = transPri;
				
				int transDur;
				transDur = duration[j-1];
				duration[j-1] = duration[j];
				duration[j] = transDur;
			}
		}
	}
	for (i = 0; i < *pn; i++)
		printList(name, make, volume, price, duration, i);
}

int main()
{
	int userChoice, check = 1;
	char name[MAXN][MAXL];
	char make[MAXN][MAXL];
	int volume[MAXN];
	int price[MAXN];
	int duration[MAXN];
	int n = 0;
    do
    {
		userChoice = menu();
    	switch(userChoice)
		{
			case 1:
				if (isFull(n))
					printf("\nSorry! The List is full!\n");
				else
					addSoftDrink(name, make, volume, price, duration, &n);
		        break;
		    case 2:
		    	if (isEmpty(n))
					printf("\nSorry! The List is empty!\n");
				else
					printBaseMake(name, make, volume, price, duration, n);
			    break;
			case 3:
				if (isEmpty(n))
					printf("\nSorry! The List is empty!\n");
				else
					printBaseVol(name, make, volume, price, duration, n);
				break;
			case 4:
				if (isEmpty(n))
					printf("\nSorry! The List is empty!\n");
				else
					printAsc(name, make, volume, price, duration, &n);
				break;
		    default:
		    	if (userChoice == 5)
		    		check = 0;
		    	else 
					printf("\n>>Wrong Input!!!\n");					
	    }
	}
	while (check == 1);
	printf("\nGood Bye!");
	getch();
}

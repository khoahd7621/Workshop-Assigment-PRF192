//Write a C-program that helps user managing a list of
//100 student names using the following menu:
//1- Add a student
//2- Remove a student
//3- Search a student
//4- Print the list in ascending order
//5- Quit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 100

int menu()
{
	int choice;
	printf("\n=======================MENU=======================");
	printf("\n| 1- Add a student                      Press: 1 |");
	printf("\n| 2- Remove a student                   Press: 2 |");
	printf("\n| 3- Search a student                   Press: 3 |");
	printf("\n| 4- Print the list in ascending order  Press: 4 |");
	printf("\n| 5- Quit                               Press: 5 |");
	printf("\n==================================================\n");
	printf("\nEnter Your Choice: ");
	scanf("%d", &choice);
	fflush(stdin); 
	return choice;
}

int isFull(int *pn)
{
	return *pn == MAX_VALUE;
}

int isEmpty(int *pn)
{
	return *pn == 0;
}

char* lTrim (char s[])
{
	int i = 0;
	while (s[i] == ' ')	i++;
	if (i > 0) strcpy(&s[0], &s[i]);
	return s;
}

char* rTrim (char s[])
{
	int i = strlen(s) - 1;
	while (s[i] == ' ') i--;
	s[i+1] = '\0';
	return s;
}

char* trim (char s[])
{
	rTrim(lTrim(s));
	char *ptr = strstr(s, "  ");
	while (ptr != NULL)
	{
		strcpy(ptr, ptr + 1);
		ptr = strstr(s, "  ");
	}
	return s;
}

void addStudent(char names[MAX_VALUE][31], int *pn)
{
	char name[31];
	int i, exist;
	do
	{
		printf("\nEnter name of student: ");
		scanf("%[^\n]", name);
		fflush(stdin);
		strupr(name);
		trim(name);
		exist = 1;
		for (i = 0; i < *pn; i++)
			if (strcmp(name, names[i]) == 0)
			{
				printf("\nName of student has exist! Enter again!\n");
				exist = 0;
				i = *pn - 1;
			}
	}
	while (exist == 0);
	strcpy(names[*pn], name);
	(*pn)++;
}

void removeStudent(char names[MAX_VALUE][31], int *pn)
{
	printf("\nList of student: \n");
	int i, j;
	for (i = 0; i < *pn; i++)
		printf("[%d]Name: %s\n", i, names[i]);
	int remove;
	printf("\nEnter number of student you wanna remove: ");
	scanf("%d", &remove);
	if (remove >= 0 && remove < *pn)
	{
		for (j = remove + 1; j < *pn; j++)
			strcpy(names[j-1], names[j]);
		printf("\nRemoved!!!\n");
	}
	else
		printf("\nUnremove!!!\n");
}

void searchStudent(char names[MAX_VALUE][31], int *pn)
{
	char name[31];
	printf("\nEnter name of student you wanna searh: ");
	scanf("%[^\n]", name);
	fflush(stdin);
	strupr(name);
	int i, x;
	int check = 0;
	for (i = 0; i < *pn; i++)
		{
			x = strcmp(names[i], name);
			if (x == 0)
			{
				printf("\nFound it!\n");
				printf("\nResult: Name[%d]: %s\n", i, names[i]); 
				check = 1;
			}
		}
	if (check == 0)
		printf("\nNot found!\n");
}

void printStudent(char names[MAX_VALUE][31], int *pn)
{
	int i, j;
   	for (i = 0; i < *pn-1; i++)
     	for (j = *pn-1; j > i; j--)
     		if (strcmp(names[j] , names[j-1]) < 0)
     			{
     				char trans[31];
		            strcpy(trans, names[j]);
		            strcpy(names[j], names[j-1]);
		            strcpy(names[j-1], trans);
				}
	for (i = 0; i < (*pn); i++)
		printf("Name[%d]: %s \n", i, names[i]);
}

int main()
{
	int userChoice, check = 1;
	char names[MAX_VALUE][31];
	int n = 0;
    do
    {
		userChoice = menu();
    	switch(userChoice)
		{
			case 1:
				if (isFull(&n))
					printf("\nSorry! The Array is full!\n");
				else
					addStudent(names, &n);					
					printf("\nAdded!\n");
		        break;
		    case 2:
		    	if (isEmpty(&n))
					printf("\nSorry! The Array is empty!\n");
				else
					removeStudent(names, &n);
			    break;
			case 3:
				if (isEmpty(&n))
					printf("\nSorry! The Array is empty!\n");
				else
					searchStudent(names, &n);
				break;
			case 4:
				if (isEmpty(&n))
					printf("\nSorry! The Array is empty!\n");
				else
					printStudent(names, &n);
				break;
		    default:
		    	if (userChoice == 5)
		    		check = 0;
		    	else 
					printf("\n>>>Wrong input!!!!\n");
				break;					
	    }
	}
	while (check == 1);
	printf("\nGood Bye!");
	getch();
}

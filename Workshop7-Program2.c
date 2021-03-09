//Develop a C-program that allows user:
//1- Adding a new employee
//2- Find data about employees using a name inputted.
//3- Remove an employee based on a code inputted
//4- Print the list in descending order based on salary + allowance.
//5- Quit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 100

int menu()
{
	int choice;
	printf("\n=======================MENU=======================");
	printf("\n| 1- Add a new employee                 Press: 1 |");
	printf("\n| 2- Search a data of employee          Press: 2 |");
	printf("\n| 3- Remove an employee                 Press: 3 |");
	printf("\n| 4- Print the list in descending order Press: 4 |");
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

void addEmployee(char code[][9], char name[][21], int salaries[], int allowances[], int*pn)
{
	char codes[9], names[21];
	int salary, allowance, totals = 0;
	printf("\n!--Please Enter Employee Information--!\n");
	fflush(stdin);
	printf("Employee Code: ");
	scanf("%[^\n]", codes);
	fflush(stdin);
	printf("Employee Name: ");
	scanf("%[^\n]", names);
	printf("Employee Salary (VND): ");
	scanf("%d", &salary);
	printf("Employee Allowances(VND): ");
	scanf("%d", &allowance);
	trim(codes);
	nameStr(names);
	strcpy(code[*pn], codes);
	strcpy(name[*pn], names);
	salaries[*pn] = salary;
	allowances[*pn] = allowance;
	(*pn)++;
}

void printList(char code[][9], char name[][21], int salaries[], int allowances[], int n)
{
	printf("\nCode: %s\n", code[n]);
	printf("Name: %s\n", name[n]);
	printf("Salary: %d VND\n", salaries[n]);
	printf("Allowances: %d VND\n", allowances[n]);
}

void printBasedName(char code[][9], char name[][21], int salaries[], int allowances[], int n)
{
	char names[21];
	printf("\nEnter NAME of employee you wanna find the information: ");
	scanf("%[^\n]", names);
	nameStr(names);
	int check, i;
	check = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(names, name[i]) == 0)
		{
			printf("\n-- Information of Employee --\n");
			printList(code, name, salaries, allowances, i);
			check = 1;
		}
	}
	if (check == 0)
		printf("\nNot found information of employee was entered!\n");
}

void removeEmployee(char code[][9], char name[][21], int salaries[], int allowances[], int*pn)
{
	int i;
	char codes[9];
	printf("Enter CODE of employee you wanna REMOVE: ");
	scanf("%[^\n]", codes);
	trim(codes);
	int check = 0;
	for (i = 0; i < *pn; i++)
	{
		if (strcmp(code[i], codes) == 0)
		{
			int j;
			for (j = i + 1; j < *pn; j++)
			{
				strcpy(code[j-1], code[j]);
				strcpy(name[j-1], name[j]);
				salaries[j-1] = salaries[j];
				allowances[j-1] = allowances[j];
			}
			check = 1;
			(*pn)--;
		}
	}
	if (check == 1)
		printf("\nRemoved!\n");
	else
		printf("\nUnremove!\n");
}

void printDec(char code[MAX_VALUE][9], char name[][21], int salaries[], int allowances[], int*pn)
{
	int i, j;
	for (i = 0; i < *pn-1; i++)
     	for (j = *pn-1; j > i; j--)
		{
			if ((salaries[j] + allowances[j]) > (salaries[j-1] + allowances[j-1]))
			{
				char trscode[9];
		        strcpy(trscode, code[j]);
		        strcpy(code[j], code[j-1]);
		        strcpy(code[j-1], trscode);
		        
				char trsname[21];
		        strcpy(trsname, name[j]);
		        strcpy(name[j], name[j-1]);
		        strcpy(name[j-1], trsname);
		        
		        int trssa;
		        trssa = salaries[j];
		        salaries[j] = salaries[j-1];
		        salaries[j-1] = trssa;
		        
		        int trsall;
		        trsall = allowances[j];
		        allowances[j] = allowances[j-1];
		        allowances[j-1] = trsall;
			}
		}
	printf("\n---List of employees---\n");
	for (i = 0; i < *pn; i++)
	{
		printList(code, name, salaries, allowances, i);
		printf("\n");
	}
}

int main()
{
	int userChoice, check = 1;
	char code[MAX_VALUE][9];
	char name[MAX_VALUE][21];
	int salaries[MAX_VALUE];
	int allowances[MAX_VALUE];
	int n = 0;
    do
    {
		userChoice = menu();
    	switch(userChoice)
		{
			case 1:
				if (isFull(&n))
					printf("\nSorry! The List is full!\n");
				else
					addEmployee(code, name, salaries, allowances, &n);			
					printf("\nAdded!\n");
		        break;
		    case 2:
		    	if (isEmpty(&n))
					printf("\nSorry! The List is empty!\n");
				else
					printBasedName(code, name, salaries, allowances, n);
			    break;
			case 3:
				if (isEmpty(&n))
					printf("\nSorry! The List is empty!\n");
				else
					removeEmployee(code, name, salaries, allowances, &n);
				break;
			case 4:
				if (isEmpty(&n))
					printf("\nSorry! The List is empty!\n");
				else
					printDec(code, name, salaries, allowances, &n);
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

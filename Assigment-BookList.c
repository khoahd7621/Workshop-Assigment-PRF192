#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 5
#define MAXL 50

int getUserChoice()
{
	int choice;
	printf("\n==================MENU=======================");
	printf("\n| 1. Add a book into a list.       Press: 1 |");
	printf("\n| 2. Print out all books in list.  Press: 2 |");
	printf("\n| 3. Search a book.                Press: 3 |");
	printf("\n| 4. Update a book.                Press: 4 |");
	printf("\n| 5. Remove a book.                Press: 5 |");
	printf("\n| 6. Exit the program.             Press: 6 |");
	printf("\n=============================================\n");
	printf("\nEnter Your Choice: ");
	scanf("%d%*c", &choice);
	return choice;
}

int getUpChoice()
{
	int choices;
	printf("\nWhat part of book you wanna update?\n");
	printf("Press 1 to update title\n");
	printf("Press 2 to update quantity\n");
	printf("Press 3 to leave this function'\n");
	printf("Type your choose: ");
	printf("\nEnter Your Choice: ");
	scanf("%d%*c", &choices);
	return choices;
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

void printList(char book[][MAXL], int quantity[], int n)
{
	printf("\n--All books in List--\n");
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nTitle: %s\n", book[i]);
		printf("Quantity: %d\n", quantity[i]);
	}
}

void addBook(char books[], char book[][MAXL], int quantity[], int quantities, int *pn) 
{
	strcpy(book[*pn], books);
	quantity[*pn] = quantities;
	(*pn)++;
}

int search(char books[], char book[][MAXL], int n)
{
	int i;
	for (i = 0; i < n; i++)
		if (strcmp(books, book[i]) == 0)
			return i;
	return -1;
}

void updateBook(char book[][MAXL], int quantity[],int pos, int *pn)
{
	
}

void removeBook(char book[][MAXL], int quantity[],int pos, int *pn)
{
	int i;
	for (i = pos + 1; i < (*pn); i++)
	{
		char trsBook[MAXL];
		strcpy(trsBook, book[i-1]);
		strcpy(book[i-1], book[i]);
		strcpy(book[i], trsBook);
				
		int trsQuan;
		trsQuan = quantity[i-1];
		quantity[i-1] = quantity[i];
		quantity[i] = trsQuan;
	}
	(*pn)--;
	printf("\nThis book has been removed from list successfully!\n");
}

int main()
{
	char book[MAXN][MAXL];
	int quantity[MAXN];
	int n = 0;
	char books[MAXL];
	int quantities;
	int pos;
	int userChoice, check = 0;
    do
    {
		userChoice = getUserChoice();
        switch(userChoice)
		{   
			case 1:
				if (isFull(n) == 1)
					printf("\nThe book list is full!!");
				else
				{
					printf("\nEnter information about the book:\n");
					printf("Title of the book: ");
					scanf("%[^\n]", books);
					fflush(stdin);
					printf("Quantity of the book: ");
					scanf("%d", &quantities);
					nameStr(books);
					addBook(books, book, quantity, quantities, &n);
					printf("\nAdded!!\n");
				}
		    	break;
		    case 2:
		    	if (isEmpty(n) == 1)
					printf("\nThe book list is empty!!");
				else
					printList(book, quantity, n);
			    break;
		    case 3:
		    	if (isEmpty(n) == 1)
					printf("\nThe book list is empty!!");
				else
				{
					printf("\nEnter title of the book you wanna search: ");
					scanf("%[^\n]", books);
					fflush(stdin);
					nameStr(books);
					pos = search(books, book, n);
					if (pos < 0 || pos >= n)
						printf("\nThis book is not existed!!\n");
					else
					{
						printf("\nFound it!\n");
						printf("Quantity of book %s is: %d\n", book[pos], quantity[pos]);
					}
				}
			    break;
		    case 4:
		    	if (isEmpty(n) == 1)
					printf("\nThe book list is empty!!");
				else
				{
					printf("\nEnter title of book you wanna update: ");
					scanf("%[^\n]", books);
					fflush(stdin);
					nameStr(books);
					pos = search(books, book, n);
					if (pos < 0 || pos >= n)
						printf("\nThis book is not existed!\n");
					else
					{
						printf("\nFound it!!\n");
						int ch, leave = 0;
						do
						{
							ch = getUpChoice();
							switch (ch)
							{
								case 1:
								{
									char bookss[MAXL];
									printf("\nEnter new title for book: ");
									scanf("%[^\n]", bookss);
									nameStr(bookss);
									int*poss = &pos;
									strcpy(book[*poss], bookss);
									break;
								}
								case 2:
								{
									int quantitiess;
									printf("\nEnter new quantity for book: ");
									scanf("%d", &quantitiess);
									int*poss = &pos;
									quantity[*poss] = quantitiess;
									break;
								}
								default:
									if (ch == 3)
										leave = 1;
									else
										printf("\nWrong Input!!! Enter again!\n");
							}
						}
						while (leave == 0);
						printf("\nUpdated!!!\n");
					}
				} 
			    break;
		    case 5:
		    	if (isEmpty(n) == 1)
					printf("\nThe book list is empty!!");
				else
				{
					printf("\nEnter title of book you wanna remove: ");
					scanf("%[^\n]", books);
					fflush(stdin);
					nameStr(books);
					pos = search(books, book, n);
					if (pos < 0 || pos >= n)
						printf("\nThis book is not existed!\n");
					else
						removeBook(book, quantity, pos, &n);
				}
				break;   
		    default:
		    	if (userChoice == 5)
		    		check = 1;
		    	else 
					printf("\n>>Wrong Input!!!\n");
	    }
	}
	while (check == 0);
	printf("\nGood Bye! See you again!\n");
	return 0;
}

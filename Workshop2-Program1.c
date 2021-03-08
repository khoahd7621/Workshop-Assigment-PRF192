//Inputting a simple expression containing one of four operators +, -, *, /

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    char c;
    printf("Enter simple expression: ");
	scanf("%d %c %d", &a, &c, &b);
    	switch (c)
		{
			case '+':
                printf("%d + %d = %d\n", a, b, a + b);
                break;
            case '-':
                printf("%d - %d = %d\n", a, b, a - b);
                break;
            case '*':
                printf("%d * %d = %d\n", a, b, a * b);
                break;
            case '/':
                if ( b == 0) {
                    printf("Cannot devide 0\n"); }
                else {
                    printf("%d / %d = %d\n", a, b, a / b); }
                break;
    	}
    return 0;
}

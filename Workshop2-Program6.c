//Program 6: Print out ASCII code table

#include <stdio.h>

int main()
{
    int code;
    for (code = 0; code <256; code++)
    	printf("%6c, %6d, %6o, %6x\n", code, code, code, code); 
    return 0;
}

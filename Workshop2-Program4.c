//Program 4: Carry out some times: accept two integers

#include <stdio.h>

int main()
{
    int x, y;
    
    do
    {
        printf("Enter number x and y: ");
        scanf("%d%d", &x, &y);
        int t = x;
            x = y;
            y = t;
        printf("x = %d, y = %d\n", x, y);
    }
    while (x != 0 && y !=0);
    return 0;
}

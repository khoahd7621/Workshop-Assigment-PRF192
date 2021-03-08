//Program 5: Print out the number of vowels, consonants and others

#include <stdio.h>

#define ENTER 10

int main() {
    
    int others = 0, vowels = 0, consonants = 0;
    char c;
    
    printf("Enter a string: ");
    
    while ( c != ENTER)
    {   c = getchar();
    
        if ((('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')))
        {
        switch (c) {
        	case 'a':
            case 'i':
            case 'u':
            case 'e':
            case 'o':
            case 'A':
            case 'I':
            case 'U':
            case 'E':
            case 'O':
        	     vowels = vowels + 1;
        	     break;
        	default:
			     consonants = consonants + 1;
			}        
        }
        else
            others = others + 1;
    }
    
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonant: %d\n", consonants);
    printf("Number of others: %d\n", others-1);
    
    return 0;
}

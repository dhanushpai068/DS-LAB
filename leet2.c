#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100000

char stringStack[SIZE][SIZE];
int numberStack[SIZE];
int top = -1, ntop = -1;

int main()
{
    char s[SIZE], current[SIZE] = "";
    char temp[SIZE];

    int count = 0, k;

    printf("Enter encoded string: ");
    scanf("%s", s);

    for(int i = 0; s[i] != '\0'; i++)
    {
        if(isdigit(s[i]))
        {
            count = count * 10 + (s[i] - '0');
        }

        else if(s[i] == '[')
        {
            top++;
            strcpy(stringStack[top], current);

            ntop++;
            numberStack[ntop] = count;

            current[0] = '\0';
            count = 0;
        }

        else if(s[i] == ']')
        {
            k = numberStack[ntop];
            ntop--;

            strcpy(temp, current);
            current[0] = '\0';

            for(int j = 0; j < k; j++)
            {
                strcat(current, temp);
            }

            strcat(stringStack[top], current);
            strcpy(current, stringStack[top]);

            top--;
        }

        else
        {
            int len = strlen(current);
            current[len] = s[i];
            current[len + 1] = '\0';
        }
    }

    printf("Decoded string: %s", current);

    return 0;
}
Displaying leetcode-1.c.

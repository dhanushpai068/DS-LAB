/* Program 2: Infix to Postfix Conversion Using a Stack */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }

    return stack[top--];
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main()
{
    char infix[MAX], postfix[MAX], ch;
    int i = 0, j = 0;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    while ((ch = infix[i++]) != '\0')
    {
        if (isalnum((unsigned char)ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1 && stack[top] == '(')
            {
                pop();
            }
        }
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch)
                    && ch != '^')))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
    {
        if (stack[top] == '(')
        {
            pop();
        }
        else
        {
            postfix[j++] = pop();
        }
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

#include <stdio.h>
#include <ctype.h>
int top = -1;
int stack[25];
int push(char e)
{
    stack[++top] = e;
}
int pop()
{
    return stack[top--];
}
int main()
{
    char postfix[25];
    char *p;
    printf("Enter the postfix epression : ");
    scanf("%s", &postfix);
    int n1, n2, n3, num;
    p = postfix;
    while (*p != '\0')
    {
        if (isdigit(*p))
        {
            num = *p - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch (*p)
            {
            case '+':
                n3 = n2 + n1;
                break;
            case '-':
                n3 = n2 - n1;
                break;
            case '*':
                n3 = n2 * n1;
                break;
            case '/':
                n3 = n2 / n1;
                break;
            }
            push(n3);
        }
        p++;
    }
    printf("\nThe result of postfix expression %s = %d", postfix,pop());
    return 0;
}
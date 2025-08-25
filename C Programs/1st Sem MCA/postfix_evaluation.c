// Program to evaluate postfix expression

#include <stdio.h>
#include <ctype.h>

int top = -1;
int stack[25];

void push(char e)
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
	printf("\n-----------------------------------------------------------");
	printf("\n                    POSTFIX EVALUATION                     ");
	printf("\n                   --------------------                    ");
	printf("\n\n Enter the postfix epression : ");
	scanf("%s", postfix);
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
	            		case '+': n3 = n2 + n1;
	                		  break;
	            		case '-': n3 = n2 - n1;
	                		  break;
	            		case '*': n3 = n2 * n1;
	                		  break;
	            		case '/': n3 = n2 / n1;
	                		  break;
	            	}
	            	push(n3);
	        }
	        p++;
	}
	printf("\n The result of postfix expression %s = %d", postfix,pop());
	printf("\n\n-----------------------------------------------------------\n\n");
	return 0;
}

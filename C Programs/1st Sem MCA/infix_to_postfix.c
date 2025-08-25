// Program to convert infix expression to postfix expression

#include <stdio.h>
#include <ctype.h>

int top = -1;
char stack[25];

void push(char e)
{
	stack[++top] = e;
}

char pop()
{
	if (top == -1)
    	{
        	return '\0';
    	}
    	else
    	{
       		 return stack[top--];
    	}
}

int priority(char e)
{
	if (e == '+' || e == '-')
    	{
       		 return 1;
    	}
    	if (e == '*' || e == '/')
    	{
       		 return 2;
    	}
    	return 0;
}

int main()
{
	char infix[25], postfix[25];
    	char *i, *p;
	printf("\n-----------------------------------------------------------");
	printf("\n                  INFIX TO POSTFIX CONVERSION              ");
	printf("\n                 -----------------------------             ");
    	printf("\n\n Enter the infix epression : ");
 	scanf("%s", infix);
    	i = infix;
    	p = postfix;
	while (*i != '\0')
	{
		if (isalnum(*i))
	        {
	        	*p = *i;
	            	p++;
	        }
	        else if (*i == '(')
	        {
	            	push(*i);
	        }
	        else if (*i == ')')
	        {

	        	while (stack[top] != '(')
	            	{
	                	*p = pop();
	                	p++;
	            	}
	            	pop();
	        }
	        else
	        {
	            	while (priority(stack[top]) >= priority(*i))
	            	{
	                	*p = pop();
	               		 p++;
	            	}
	            	push(*i);
	        }
	        i++;
	}
	while (top != -1)
	{
		*p = pop();
	        p++;
	}
	*p = '\0';
	printf("\n The postfix expression is : %s", postfix);
	printf("\n\n-----------------------------------------------------------\n\n");
	return 0;
}

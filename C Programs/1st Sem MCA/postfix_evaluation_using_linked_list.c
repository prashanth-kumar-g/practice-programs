// Program to evaluate postfix expression using linked list implemented as stack

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
} *new=NULL, *top=NULL;

void push(char ele)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->data=ele;
	new->next=NULL;
	if(top==NULL)
	{
		top=new;
	}
	else
	{
		new->next=top;
		top=new;
	}
}

int pop()
{
    if(top==NULL)
	{
		return '\0';
	}
	else
	{
		struct node *temp=top;
		top=top->next;
		char value=temp->data;
		temp->next=NULL;
		free(temp);
		return value;
	}
}

int main()
{
	char postfix[25];
    	char *p;
	printf("\n-----------------------------------------------------------");
	printf("\n           POSTFIX EVALUATION (STACK LINKEDLIST)           ");
	printf("\n          ---------------------------------------          ");
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

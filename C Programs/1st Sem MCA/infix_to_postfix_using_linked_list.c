// Program to covert infix expression to postfix expression using linked list implemented as stack

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

struct node
{
	char data;
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

char pop()
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

int priority(char ele)
{
	if(ele=='+' || ele=='-')
	{
		return 1;
	}
	if(ele=='*' || ele=='/')
	{
		return 2;
	}
	return 0;
}

int main()
{
	char infix[25],postfix[25];
	char *i,*p;
	printf("\n----------------------------------------------------------------------");
	printf("\n            INFIX TO POSTFIX CONVERSION (STACK LINKEDLIST)            ");
	printf("\n           ------------------------------------------------           ");
	printf("\n\n Enter the infix expression : ");
	scanf("%s",infix);
	i=infix;
	p=postfix;
	while(*i!='\0')
	{
		if(isalnum(*i))
		{
			*p=*i;
			p++;
		}
		else if(*i=='(')
		{
			push(*i);
		}
		else if(*i==')')
		{
			while(top!=NULL && top->data!='(')
			{
				*p=pop();
				p++;
			}
			pop();
		}
		else
		{
			while(top!=NULL && priority(top->data)>=priority(*i))
			{
				*p=pop();
				p++;
			}
			push(*i);
		}
		i++;
	}
	while(top!=NULL)
	{
		*p=pop();
		p++;
	}
	*p='\0';
	printf("\n The postfix expression is : %s",postfix);
	printf("\n\n------------------------------------------------------------------------\n\n");
	return 0;
}

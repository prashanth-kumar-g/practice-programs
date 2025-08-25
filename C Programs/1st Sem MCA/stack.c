// Program for stack operations

#include<stdio.h>
#include<stdlib.h>

int n;
int top=-1;

void push(int s[], int e)
{
	if(top==n-1)
	{
		printf("\n Stack is Full \n");
	}
	else
	{
		top++;
		s[top]=e;
		printf("\n The Element %d is Pushed \n",s[top]);
	}
}

void pop(int s[])
 {
	if(top==-1)
	{
		printf("\n Stack is Empty \n");
	}
	else
	{
		printf("\n The Element %d is Popped \n",s[top]);
		top--;
	}
}

void peek(int s[])
{
	if(top==-1)
	{
		printf("\n Stack is Empty \n");
	}
	else
	{
		printf("\n The Peek Element is %d \n",s[top]);
	}
}

void display(int s[])
{
	if(top==-1)
	{
		printf("\n Stack is Empty \n");
	}
	else
	{
		printf("\n The Elements of Stack are \n");
		for(int i=top;i>=0;i--)
		{
			printf("\n  %d",s[i]);
		}
		printf("\n");
	}
}

int main()
{
	printf("\n Enter the Size of Stack : ");
	scanf("%d",&n);
	int stack[n],ch,ele;
	while(1)
	{
		printf("\n-----------------------------------------------------");
		printf("\n                  STACK OPERATIONS                   ");
		printf("\n                 ------------------                  ");
		printf("\n   1) Push  2) Pop  3) Peek  4) Display  5) Exit     ");
		printf("\n-----------------------------------------------------");
		printf("\n\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter the Element to be Pushed : ");
				scanf("%d",&ele);
				push(stack,ele);
				break;
			case 2: pop(stack);
				break;
			case 3: peek(stack);
				break;
			case 4: display(stack);
				break;
			case 5: printf("\n Exiting...\n\n");
				exit(0);
			default: printf("\n Invalid Choice, Select Again.\n");
				 break;
		}
	}
	return 0;
}

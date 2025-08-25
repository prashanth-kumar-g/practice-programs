// Program for stack operations implementation using linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
} *new=NULL, *top=NULL;

void push(int ele)
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
	printf("\n The Element %d is Pushed \n",top->data);
}

void pop()
{
	if(top==NULL)
	{
		printf("\n Stack is Empty \n");
	}
	else
	{
		struct node *temp=top;
		top=top->next;
		printf("\n The Element %d is Popped \n",temp->data);
		temp->next=NULL;
		free(temp);
	}
}

void peek()
{
	if(top==NULL)
	{
		printf("\n Stack is Empty \n");
	}
	else
	{
		printf("\n The Peek Element is %d \n",top->data);
	}
}

void display()
{
	if(top==NULL)
	{
		printf("\n Stack is Empty \n");
	}
	else
	{
		struct node *temp=top;
		printf("\n The Elements of Stack are \n");
		while(temp!=NULL)
		{
			printf("\n  %d",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

int main()
{
	int ch,ele;
	while(1)
	{
		printf("\n----------------------------------------------------------------------------------");
		printf("\n                        STACK OPERATIONS USING LINKEDLIST                         ");
		printf("\n                       -----------------------------------                        ");
		printf("\n           1) Push     2) Pop     3) Peek     4) Display     5) Exit              ");
		printf("\n----------------------------------------------------------------------------------");
		printf("\n\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter the Element to be Pushed : ");
				scanf("%d",&ele);
				push(ele);
				break;
			case 2: pop();
				break;
			case 3: peek();
				break;
			case 4: display();
				break;
			case 5: printf("\n Exiting... \n\n");
				exit(0);
			default: printf("\n Invalid Choice, Select Again. \n");
				 break;
		}
	}
	return 0;
}

// Program for circular queue operations using linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
} *new=NULL, *front=NULL, *rear=NULL;

void enqueue(int ele)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->data=ele;
	new->next=NULL;
	if(front==NULL)
	{
		rear=new;
		front=new;
		rear->next=front;
	}
	else
	{
		rear->next=new;
		rear=new;
		rear->next=front;
	}
	printf("\n The Element %d is Inserted \n",rear->data);
}

void dequeue()
{
	if(front==NULL)
	{
		printf("\n Circular Queue is Empty \n");
	}
	else if(front->next==front)
	{
		struct node *temp=front;
		front=NULL;
		rear=NULL;
		printf("\n The Element %d is Deleted \n",temp->data);
		temp->next=NULL;
		free(temp);
	}
	else
	{
		struct node *temp=front;
		front=front->next;
		rear->next=front;
		printf("\n The Element %d is Deleted \n",temp->data);
		temp->next=NULL;
		free(temp);
	}
}

void display()
{
	if(front==NULL)
	{
		printf("\n Circular Queue is Empty \n");
	}
	else
	{
		struct node *temp=front;
		printf("\n The Elements of Circular Queue are : ");
		while(temp->next!=front)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);
	}
}

int main()
{
	int ch,ele;
	while(1)
	{
		printf("\n----------------------------------------------------------------------------------");
		printf("\n                    CIRCULAR QUEUE OPERATIONS USING LINKEDLIST                    ");
		printf("\n                   --------------------------------------------                   ");
		printf("\n             1) Enqueue     2) Dequeue     3) Display     4) Exit                 ");
		printf("\n----------------------------------------------------------------------------------");
		printf("\n\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter the Element to be Inserted : ");
				scanf("%d",&ele);
				enqueue(ele);
				break;
			case 2: dequeue();
				break;
			case 3: display();
				break;
			case 4: printf("\n Exiting... \n\n");
				exit(0);
			default: printf("\n Invalid Choice, Select Again. \n");
				 break;
		}
	}
	return 0;
}

// Program for circular queue operations

#include<stdio.h>
#include<stdlib.h>

int front=-1;
int rear=-1;
int n;

void enqueue(int a[], int e)
{
	if(((rear+1)%n==front) || (front==0 && rear==n-1))
	{
		printf("\n Circular Queue is Full \n");
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		a[rear]=e;
		printf("\n The Element %d is Inserted \n",a[rear]);
	}
	else
	{
		rear=(rear+1)%n;
		a[rear]=e;
		printf("\n The Element %d is Inserted \n",a[rear]);
	}

}

void dequeue(int a[])
{
	if(front==-1 && rear==-1)
	{
		printf("\n Circular Queue is Empty \n");
	}
	else if(front==rear)
	{
		printf("\n The Element %d is Deleted \n",a[rear]);
		front=-1;
		rear=-1;
	}
	else
	{
		printf("\n The Element %d is Deleted \n",a[front]);
		front=(front+1)%n;
	}
}

void display(int a[])
{
	if(front==-1 && rear==-1)
	{
		printf("\n Circular Queue is Empty \n");
	}
	else
	{
		printf("\n The Elements of Circular Queue are : ");
		int i=front;
		while(i!=rear)
		{
			printf("%d ",a[i]);
			i=(i+1)%n;
		}
		printf("%d \n",a[rear]);
	}
}

int main()
{
	printf("\n Enter the Size of Circular Queue : ");
	scanf("%d",&n);
	int cqueue[n],ch,ele;
	while(1)
	{
		printf("\n----------------------------------------------------");
		printf("\n               CIRCULAR QUEUE OPERATIONS            ");
		printf("\n              ---------------------------           ");
		printf("\n   1) Enqueue   2) Dequeue   3) Display   4) Exit   ");
		printf("\n----------------------------------------------------");
		printf("\n\n Enter your choice : ");
 		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter the Element to be Inserted : ");
				scanf("%d",&ele);
				enqueue(cqueue,ele);
				break;
			case 2: dequeue(cqueue);
				break;
			case 3: display(cqueue);
				break;
			case 4: printf("\n Exiting... \n\n");
				exit(0);
			default : printf("\n Invalid Choice, Select Again. \n");
				  break;
		}
	}
	return 0;
}

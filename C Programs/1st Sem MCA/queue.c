// Program for queue operations

#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;
int n;

void Enqueue(int q[], int e)
{
	if (rear == n - 1)
    	{
        	printf("\n Queue is Full \n");
    	}
    	else
    	{
        	if (front == -1)
        	{
            		front = 0;
        	}
        	rear++;
        	q[rear] = e;
        	printf("\n The Element %d is Inserted \n", q[rear]);
    	}
}

void Dequeue(int q[])
{
	if (rear == -1 || front > rear)
    	{
        	printf("\n Queue is Empty \n");
    	}
    	else
    	{
        	printf("\n The Element %d is Deleted \n", q[front]);
        	front++;
    	}
}

void Display(int q[])
{
	if (rear == -1 || front > rear)
    	{
        	printf("\n Queue is Empty \n");
    	}
    	else
    	{
        	printf("\n The Elements of Queue are : ");
        	for (int i = front; i <= rear; i++)
        	{
         	   	printf("%d ", q[i]);
        	}
        	printf("\n");
    	}
}

int main()
{
	printf("\n Enter the size of the Queue : ");
    	scanf("%d", &n);
    	int queue[n], ch, ele;
    	while(1)
    	{
        	printf("\n----------------------------------------------------");
		printf("\n                QUEUE OPERATIONS                    ");
		printf("\n               ------------------                   ");
	        printf("\n   1) Enqueue   2)Dequeue   3) Display   4) Exit"    );
	        printf("\n----------------------------------------------------");
	        printf("\n\n Enter your choice : ");
	        scanf("%d", &ch);
	        switch (ch)
	        {
		        case 1: printf("\n Enter the Element to be Inserted : ");
		        	scanf("%d", &ele);
		        	Enqueue(queue, ele);
		        	break;
		        case 2: Dequeue(queue);
		        	break;
		        case 3: Display(queue);
		            	break;
		        case 4: printf("\n Exiting... \n\n");
		            	exit(0);
		        default: printf("\n Invalid Choice, Select Again. \n");
		            	 break;
		}
	}
	return 0;
}

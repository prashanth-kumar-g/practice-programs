// Menu-Driven Program to Sort and Remove Duplicates from Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
} *new=NULL, *head=NULL, *tail=NULL;

void insert(int ele)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->data=ele;
	new->next=NULL;
	if(tail==NULL)
	{
		head=new;
		tail=new;
	}
	else
	{
		tail->next=new;
		tail=new;
	}
	printf("\n The Element %d is Inserted \n",tail->data);
}

void display()
{
	if(head==NULL)
	{
		printf("\n Linked List is Empty \n");
	}
	else
	{
		printf("\n The Elements of Linked List are : ");
		struct node *temp=head;
		while(temp!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

int length()
{
	if(head==NULL)
	{
		return 0;
	}
	else
	{
		struct node *temp=head;
		int count=0;
		while(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
		return count;
	}
}

void sort()
{
	if(head==NULL)
	{
		printf("\n Linked List is Empty \n");
	}
	else if(head->next==NULL)
	{
		printf("\n The Linked List is Sorted \n");
	}
	else
	{
		for(int i=1;i<=length();i++)
		{
			struct node *ptr1=head;
			struct node *ptr2=ptr1->next;
			for(int j=1;j<=length()-i;j++)
			{
				if(ptr1->data > ptr2->data)
				{
					int temp=ptr1->data;
					ptr1->data=ptr2->data;
					ptr2->data=temp;
				}
				ptr1=ptr2;
				ptr2=ptr2->next;
			}
		}
		printf("\n The Linked List is Sorted \n");
	}
}

void removeDuplicates()
{
	if(head==NULL)
	{
		printf("\n Linked List is Empty \n");
	}
	else if(head->next==NULL)
	{
		printf("\n Duplicates are Remove from Linked List \n");
	}
	else
	{
		struct node *ptr1=head;
		while(ptr1!=NULL)
		{
			struct node *ptr2=ptr1;
			while(ptr2->next!=NULL)
			{
				if(ptr1->data==ptr2->next->data)
				{
					struct node *dup=ptr2->next;
					ptr2->next=ptr2->next->next;
					if(ptr2->next==NULL)
					{
						tail=ptr2;
					}
					free(dup);
				}
				else
				{
					ptr2=ptr2->next;
				}
			}
			ptr1=ptr1->next;
		}
		printf("\n Duplicates are Removed from Linked List \n");
	}
}

int main()
{
	int ch,ele,pos;
	while(1)
	{
		printf("\n-----------------------------------------------------------------");
		printf("\n                     LINKED LIST OPERATIONS                      ");
		printf("\n                    ------------------------                     "); 
		printf("\n  1) Insert  2) Display  3) Sort  4) Remove Duplicates  5) Exit  ");
		printf("\n-----------------------------------------------------------------");
		printf("\n\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter the Element to be Inserted : ");
				scanf("%d",&ele);
				insert(ele);
				break;
			case 2: display();
				break;
			case 3: sort();
				break;
			case 4: removeDuplicates();
				break;
			case 5: printf("\n Exiting... \n\n");
				exit(0);
			default: printf("\n Invalid Choice, Select Again. \n");
				 break;
		}
	}
	return 0;
}

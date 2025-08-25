// Program for doubly linked list operations

#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
} *new=NULL, *head=NULL, *tail=NULL;

void insertFront(int ele)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->prev=NULL;
	new->data=ele;
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
		tail=new;
	}
	else
	{
		new->next=head;
		head->prev=new;
		head=new;
	}
	printf("\n The Element %d is Inserted at Front \n",head->data);
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
			printf("%d<-->",temp->data);
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

void insertEnd(int ele)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->prev=NULL;
	new->data=ele;
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
		tail=new;
	}
	else
	{
		tail->next=new;
		new->prev=tail;
		tail=new;
	}
	printf("\n The Element %d is Inserted at End \n",tail->data);
}

void deleteFront()
{
	if(head==NULL)
	{
		printf("\n Linked List is Empty \n");
	}
	else if(head->next==NULL)
	{
		struct node *temp=head;
		head=NULL;
		tail=NULL;
		printf("\n The Element %d is Deleted at Front \n",temp->data);
		free(temp);
	}
	else
	{
		struct node *temp=head;
		head=head->next;
		head->prev=NULL;
		printf("\n The Element %d is Deleted at Front \n",temp->data);
		temp->next=NULL;
		free(temp);
	}
}

void deleteEnd()
{
	if(head==NULL)
	{
		printf("\n Linked List is Empty \n");
	}
	else if(head->next==NULL)
	{
		struct node *temp=head;
		head=NULL;
		tail=NULL;
		printf("\n The Element %d is Deleted at End \n",temp->data);
		free(temp);
	}
	else
	{
		struct node *temp=tail;
		tail=tail->prev;
		tail->next=NULL;
		printf("\n The Element %d is Deleted at End \n",temp->data);
		temp->prev=NULL;
		free(temp);
	}
}

void insertBetween(int ele,int pos)
{
	new=(struct node*)malloc(sizeof(struct node));
	new->prev=NULL;
	new->data=ele;
	new->next=NULL;
	if(head==NULL)
	{
		printf("\n Linked List is Empty \n");
	}
	else if(pos>length() || pos<1)
	{
		printf("\n Invalid Position to Insert Element \n");
	}
	else if(pos==1)
	{
		new->next=head;
		head->prev=new;
		head=new;
		printf("\n The Element %d is Inserted at Position %d \n",new->data,pos);
	}
	else
	{
		struct node *temp=head;
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		new->prev=temp;
		new->next=temp->next;
		temp->next=new;
		new->next->prev=new;
		printf("\n The Element %d is Inserted at Position %d \n",new->data,pos);
	}
}

void deleteBetween(int pos)
{
	if(head==NULL)
	{
		printf("\n Linked List is Empty \n");
	}
	else if(pos>length() || pos<1)
	{
		printf("\n Invalid Position to Delete Element \n");
	}
	else if(pos==1)
	{
		struct node *temp=head;
		if(head->next==NULL)
		{
			head=NULL;
			tail=NULL;
		}
		else
		{
			head=head->next;
			head->prev=NULL;
		}
		printf("\n The Element %d is Deleted at Position %d \n",temp->data,pos);
		temp->next=NULL;
		free(temp);
	}
	else
	{
		struct node *temp=head;
		for(int i=1;i<pos;i++)
		{
			temp=temp->next;
		}
		if(temp->next==NULL)
		{
			temp->prev->next=NULL;
		}
		else
		{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
		}
		printf("\n The Element %d is Deleted at Position %d \n",temp->data,pos);
		temp->prev=NULL;
		temp->next=NULL;
		free(temp);
	}
}

void search(int ele)
{
	if(head==NULL)
	{
		printf("\n Linked List is Empty \n");
	}
	else
	{
		struct node *temp=head;
		int loc=0;
		while(temp->data!=ele)
		{
			if(temp->next==NULL)
			{
				loc=-1;
				break;
			}
			loc++;
			temp=temp->next;
		}
		if(loc==-1)
		{
			printf("\n The Element %d does not exist \n",ele);
		}
		else
		{
			printf("\n The first occurance of Element %d is found at Position %d \n",temp->data,loc+1);
		}
	}
}

int main()
{
	int ch,ele,pos;
	while(1)
	{
		printf("\n--------------------------------------------------------------------");
		printf("\n                    DOUBLY LINKED LIST OPERATIONS                   ");
		printf("\n                   -------------------------------                  ");
		printf("\n   1) Insert at Front   2) Insert in Between   3) Insert at End     ");
		printf("\n   4) Delete at front   5) Delete in Between   6) Delete at End     ");
		printf("\n   7) Display      8) Search     9) Length     10) Exit             ");
		printf("\n--------------------------------------------------------------------");
		printf("\n\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter the Element to be Inserted at Front : ");
				scanf("%d",&ele);
				insertFront(ele);
				break;
			case 2: printf("\n Enter the Element to be Inserted in Between : ");
				scanf("%d",&ele);
				printf("\n Enter the Position at which Element be Inserted : ");
				scanf("%d",&pos);
				insertBetween(ele,pos);
				break;
			case 3: printf("\n Enter the Element to be Inserted at End : ");
				scanf("%d",&ele);
				insertEnd(ele);
				break;
			case 4: deleteFront();
				break;
			case 5: printf("\n Enter the Position at which Element be Deleted : ");
				scanf("%d",&pos);
				deleteBetween(pos);
				break;
			case 6: deleteEnd();
				break;
			case 7: display();
				break;
			case 8: printf("\n Enter the Element to be Searched : ");
				scanf("%d",&ele);
				search(ele);
				break;
			case 9: if(length()==0)
				{
					printf("\n Linked List is Empty \n");
				}
				else
				{
					printf("\n The Length of Linked List is %d \n",length());
				}
				break;
			case 10: printf("\n Exiting... \n\n");
				 exit(0);
			default: printf("\n Invalid Choice, Select again. \n");
				 break;
		}
	}
	return 0;
}

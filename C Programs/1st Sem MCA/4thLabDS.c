// Menu-Driven Program to Trasform a Linked List by extracting all nodes at even poisitions, reversing their order,
// and appending them sequentially at to the end while maintaining the relative order of odd-positioned nodes

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
} *head=NULL, *tail=NULL;

struct Node* createNode(int ele)
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=ele;
	newNode->next=NULL;
	return newNode;
}

void Insert(int ele)
{
	struct Node* new=createNode(ele);
	if(head==NULL)
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

void Delete()
{
	if(head==NULL)
	{
		printf("\n Linked List is Empty \n");
	}
	else if(head->next==NULL)
	{
		struct Node *temp=head;
		head=NULL;
		tail=NULL;
		printf("\n The Element %d is Deleted \n",temp->data);
		free(temp);
	}
	else
	{
		struct Node *temp=head;
		while(temp->next!=tail)
		{
			temp=temp->next;
		}
		tail=temp;
		temp=temp->next;
		printf("\n The Element %d is Deleted \n",temp->data);
		tail->next=NULL;
		free(temp);
	}
}

void Display(struct Node* head)
{
	struct Node *temp=head;
	while(temp!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

struct Node* Reverse(struct Node* head)
{
	struct Node *prev=NULL, *curr=head, *next=NULL;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}

void Transform()
{
	if(head==NULL)
	{
		printf("\n Linked List is Empty \n");
	}
	else if(head->next==NULL || head->next->next==NULL)
	{
		printf("\n The Elements of Linked List are : ");
		Display(head);
		printf("\n Too few Elements in Linked List to Transform\n");
	}
	else
	{
		printf("\n The Elements of Current Linked List are : ");
		Display(head);
		struct Node *odd=head,*oddHead=odd;
		struct Node *even=head->next,*evenHead=even;
		while(odd!=NULL && even!=NULL && even->next!=NULL)
		{
			odd->next=even->next;
			odd=odd->next;
			even->next=odd->next;
			even=even->next;
		}
		odd->next=NULL;
		tail=odd;
		printf("\n The Odd-Positioned Elements in Linked List are : ");
		Display(oddHead);
		printf("\n The Even-Positioned Elements in Linked List are : ");
		Display(evenHead);
		struct Node *reversedEven=Reverse(evenHead);
		printf("\n The Reversed Even-Positioned Elements in Linked List are : ");
		Display(reversedEven);
		tail->next=reversedEven;
		while(tail->next!=NULL)
		{
			tail=tail->next;
		}
		printf("\n The Elements of Linked List after Transforming are : ");
		Display(head);
	}
}

int main()
{
	int ch,ele;
	while(1)
	{
		printf("\n---------------------------------------------------------------------------");
		printf("\n                       LINKED LIST OPERATIONS                              ");
		printf("\n                      ------------------------                             ");
		printf("\n  1) Insert   2) Delete   3) Display   4) Transform and Display   5) Exit  ");
		printf("\n---------------------------------------------------------------------------");
		printf("\n\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter the Element to be Inserted : ");
				scanf("%d",&ele);
				Insert(ele);
				break;
			case 2: Delete();
				break;
			case 3: if(head==NULL)
				{
					printf("\n Linked List is Empty\n");
				}
				else
				{
					printf("\n The Elements of Linked List are : ");
					Display(head);
				}
				break;
			case 4: Transform();
				break;
			case 5: printf("\n Exiting... \n\n");
				exit(0);
			default: printf("\n Invalid Choice, Select Again. \n");
				 break;
		}
	}
	return 0;
}

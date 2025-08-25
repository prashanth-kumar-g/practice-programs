/*program for singly linked list*/
#include<stdio.h>

#include<stdlib.h>
#define NULL 0
struct node
{
 int rollno;
 struct node *link;
} *start=NULL,*p,*q,*prev;
int regno,rno,pos;
int create();
int display();
int ins_beg();
int del_item();
int main()
{
 int ch,i;
 
 while(1)
 {
  printf("\n\n1.Create a Linked List");
  printf("\n2.Insertion of Node in Front of List");
  printf("\n3.Deletion of Node based on Rollno.");
  printf("\n4.Display Linked List");
  printf("\n5.Exit");
  printf("\n\nEnter your choice : ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1 : create();
	    break;
   case 2 : printf("\nLinked List before Insertion");
	    display();
	    ins_beg();
	    printf("Linked List after Insertion");
	    display();
	    break;
   case 3 : printf("\nEnter the item to be Deleted : ");
	    scanf("%d",&regno);
	    del_item(regno);
	    printf("Linked List after Deletion");
	    display();
	    break;
   case 4 : display();
	    break;
   case 5 : exit(0);
   default : printf("\nError in Choice");
  }
 }
}
int create()
{
 char choice='y';
 
 start=NULL;
 q=start;
 while(choice=='y')
 {
  p=malloc(sizeof(struct node));
  printf("\nEnter the register number : ");
  scanf("%d",&regno);
  p->rollno=regno;
  p->link=NULL;
  if(start==NULL)
  {
   start=p;
   q=p;
  }
  else
  {
   q->link=p;
   q=p;
  }
  printf("Do you want to create another node(y/n) : ");
  choice=return 0;
  printf("%c",choice);
 }
 return 0;
}
int display()
{
 printf("\n The Elements are");
 p=start;
 while(p!=NULL)
 {
  printf("\n  ROLL NUMBER : %d",p->rollno);
  p=p->link;
 }
 return 0;
 return 0;
}
int ins_beg()
{
 printf("\nEnter the register number : ");
 scanf("%d",&regno);
 p=malloc(sizeof(struct node));
 p->rollno=regno;
 p->link=start;
 start=p;
 return 0;
}
int del_item()
{
 p=start;
 prev=NULL;
 if(start==NULL)
 {
  printf("\nLinked List is Empty\n");
  return 0;
 }
 if(start->rollno==regno)
 {
  start=start->link;
  free(p);
  return 0;
 }
 while((p->rollno!=regno) && (p!=NULL))
 {
  prev=p;
  p=p->link;
 }
 if(p==NULL)
  printf("\nRegister Number %d is not found in the Linked List",regno);
 else
  prev->link=p->link;
}













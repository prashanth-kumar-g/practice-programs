// linked list
#include<iostream>

#include<stdlib.h>
int main()
{
 struct node
 {
  int data;
  struct node *link;
 };
 clrscr();

 struct node *head;
 struct node *second;
 struct node *third;

 head=(struct node *)malloc(sizeof(struct node));
 second=(struct node *)malloc(sizeof(struct node));
 third=(struct node *)malloc(sizeof(struct node));

 head->data=35;
 head->link=second;

 second->data=36;
 second->link=third;

 third->data=37;
 third->link=NULL;

 struct node *ptr;
 ptr=head;
 cout<<"\nThe Elements are\n";
 while(ptr!=NULL)
 {
  cout<<"\n "<<ptr->data;
  ptr=ptr->link;
 }

 free(head);
 free(second);
 free(third);

 return 0;
}
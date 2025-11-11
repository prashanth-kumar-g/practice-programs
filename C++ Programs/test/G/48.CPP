// linked list (allocating memory at a time)
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

 struct node *start;

 start=(struct node *)malloc(3*sizeof(struct node));

 start->data=35;
 start->link=(start+1);

 (start+1)->data=36;
 (start+1)->link=(start+2);

 (start+2)->data=37;
 (start+2)->link=NULL;

 struct node *ptr;
 ptr=start;
 cout<<"\nThe Elements are\n";
 while(ptr!=NULL)
 {
  cout<<"\n "<<ptr->data;
  ptr=ptr->link;
 }

 free(start);

 return 0;
}
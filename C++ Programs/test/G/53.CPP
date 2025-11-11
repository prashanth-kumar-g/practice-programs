// linked list inserting in between
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

 int n;
 cout<<"\nEnter the size : ";
 cin>>n;

 struct node *start;
 start=(struct node *)malloc(n*sizeof(struct node));

 cout<<"Enter the elements : ";
 for(int i=0;i<n;i++)
 {
  cin>>(start+i)->data;
  (start+i)->link=(start+i+1);
 }
 (start+(n-1))->link=NULL;

 struct node *ptr;
 ptr=start;
 cout<<"\nThe Elements before inserting  :  ";
 while(ptr!=NULL)
 {
  cout<<ptr->data<<"  ";
  ptr=ptr->link;
 }

 struct node *ins;
 int pos;
 cout<<"\n\nEnter the element to be inserted and its position : ";
 cin>>ins->data>>pos;
 ptr=start;
 for(i=0;i<pos-1;i++)
 {
  ptr=ptr->link;
 }
 ins->link=ptr->link;
 ptr->link=ins;

 ptr=start;
 cout<<"\nThe Elements after inserting  :  ";
 while(ptr!=NULL)
 {
  cout<<ptr->data<<"  ";
  ptr=ptr->link;
 }


 free(start);

 return 0;
}
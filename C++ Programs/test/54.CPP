// linked list inserting at end
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
 cout<<"\n\nEnter the element to be inserted at end : ";
 cin>>ins->data;
 ptr=start;
 while(ptr->link!=NULL)
 {
  ptr=ptr->link;
 }
 ptr->link=ins;
 ins->link=NULL;

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
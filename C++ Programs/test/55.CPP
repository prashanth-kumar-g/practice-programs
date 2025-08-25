// linked list deletion at beginning
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
 cout<<"\nThe Elements before deletion  :  ";
 while(ptr!=NULL)
 {
  cout<<ptr->data<<"  ";
  ptr=ptr->link;
 }

 struct node *del;
 del=(struct node *)malloc(sizeof(struct node));
 del=start;           // del pointer is now pointing to start pointer
 start=start->link;    // start pointer now points to its next node
 free(del);   // first node element gets deleted

 ptr=start;
 cout<<"\n\nThe Elements after deletion  :  ";
 while(ptr!=NULL)
 {
  cout<<ptr->data<<"  ";
  ptr=ptr->link;
 }


 free(start);

 return 0;
}
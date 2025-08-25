// linked list deletion at end
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
 ptr=start;            // ptr is pointing to start
 del=start->link;      // del pointer is now pointing to next node of start pointer (since start->link is pointing to its next node, and del is  pointing to start->link, so del now directly points to next node of start pointer)
 while(del->link!=NULL)
 {
  ptr=ptr->link;      // after completion of loop, ptr pointer will point to (pos-1)th node of start pointer
  del=del->link;      // after completion of loop, del pointer will point to (pos)th node of start pointer
 }
 ptr->link=NULL;
 //free(del);   // (pos)th node gets deleted

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
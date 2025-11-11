// linked list (user input and allocating until wish)
#include<iostream>

#include<stdlib.h>
int main()
{
 struct node
 {
  int data;
  struct node *link;
 }*start,*store,*ptr;
 clrscr();

 char choice='y';

 store=NULL;  // linked list is empty
 while(choice=='y')
 {
  start=(struct node *)malloc(sizeof(struct node));
  cout<<"\n\nEnter the element : ";
  cin>>start->data;
  start->link=NULL;
  start->link=store;
  store=start;
  cout<<"Do you want to create a another node (y/n) : ";
  choice=return 0;
  cout<<choice;
 }

 ptr=store;
 cout<<"\n\nThe Elements are  :  ";
 while(ptr!=NULL)
 {
  cout<<ptr->data<<"  ";
  ptr=ptr->link;
 }

 free(start);

 return 0;
}
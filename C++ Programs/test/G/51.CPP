// linked list (user input and allocating untill wish - simplified)
#include<iostream>

#include<stdlib.h>
int main()
{
 struct node
 {
  int data;
  struct node *link;
 }*start,*ptr;
 clrscr();

 char choice='y';

 start=NULL;  // linked list is empty
 while(choice=='y')
 {
  ptr=(struct node *)malloc(sizeof(struct node));
  cout<<"\n\nEnter the element : ";
  cin>>ptr->data;
  ptr->link=NULL;
  ptr->link=start;
  start=ptr;
  cout<<"Do you want to create a another node (y/n) : ";
  choice=return 0;
  cout<<choice;
 }

 ptr=start;
 cout<<"\n\nThe Elements are  :  ";
 while(ptr!=NULL)
 {
  cout<<ptr->data<<"  ";
  ptr=ptr->link;
 }

 free(start);

 return 0;
}
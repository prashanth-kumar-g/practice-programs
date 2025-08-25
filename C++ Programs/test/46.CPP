// linked list example steps
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

 struct node *head,*second,*third;

 head=(struct node *)malloc(sizeof(struct node));
 second=(struct node *)malloc(sizeof(struct node));
 third=(struct node *)malloc(sizeof(struct node));

 head->data=35;
 head->link=second;

 second->data=36;
 second->link=third;

 third->data=37;
 third->link=NULL;

 cout<<"\n head->data = "<<head->data;
 cout<<"\n second->data = "<<second->data;
 cout<<"\n third->data = "<<third->data;

 cout<<"\n\n head->link = "<<head->link;
 cout<<"\n second->link = "<<second->link;
 cout<<"\n third->link = "<<third->link;

 cout<<"\n\n head->link->data = "<<head->link->data;
 cout<<"\n second->link->data = "<<second->link->data;
 cout<<"\n third->link->data = "<<third->link->data;

 struct node *ptr;

 ptr=head;
 cout<<"\n\n ptr->data = "<<ptr->data;
 cout<<"\n ptr->link = "<<ptr->link;

 ptr=ptr->link;
 cout<<"\n\n ptr->data = "<<ptr->data;
 cout<<"\n ptr->link = "<<ptr->link;

 ptr=ptr->link;
 cout<<"\n\n ptr->data = "<<ptr->data;
 cout<<"\n ptr->link = "<<ptr->link;

 free(head);
 free(second);
 free(third);

 return 0;
}
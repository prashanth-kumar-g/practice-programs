//program to implement operations on queue
#include<iostream>

#include<iomanip>
#include<stdlib.h>
const int max=5;
class queue
{
 private : int qu[max];
	   int front,rear;
 public : queue()
	  {
	   front=-1;
	   rear=-1;
	  }
	  void addq();
	  void delq();
	  void showq();
};
void queue::addq()
{
 int item;
 if(rear==max-1)
 {
  cout<<"Queue is full"<<endl;
  return;
 }
 rear++;
 cout<<"Enter item to be inserted : ";
 cin>>item;
 qu[rear]=item;
 if(front==-1)
  front=0;
}
void queue::delq()
{
 int item;
 if(front==-1)
 {
  cout<<"Queue is empty"<<endl;
  return;
 }
 item=qu[front];
 cout<<"Item deleted is "<<item<<endl;
 if(front==rear)
  front=rear=-1;
 else
  front++;
}
void queue::showq()
{
 if(front==-1)
  cout<<"Queue is empty"<<endl;
 else
 {
  cout<<"Queue elements are"<<endl;
  for(int i=front;i<=rear;i++)
  cout<<setw(3)<<qu[i]<<endl;
 }
}
int main()
{
 queue q;
 int choice;
 clrscr();
 do
 {
  cout<<"\nQueue Operations"<<endl;
  cout<<" 1.insert"<<endl;
  cout<<" 2.delete"<<endl;
  cout<<" 3.display"<<endl;
  cout<<" 4.exit"<<endl;
  cout<<"\nEnter your choice : ";
  cin>>choice;
  switch(choice)
  {
   case 1 : q.addq();
	    break;
   case 2 : q.delq();
	    break;
   case 3 : q.showq();
	    break;
   case 4 : exit(0);
   default : cout<<"Wrong Choice"<<endl;
  }
 }
 while(1);
}

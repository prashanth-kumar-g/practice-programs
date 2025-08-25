/*program using stack*/
#define maxstk 3
#include<stdio.h>

int top=-1,stack[maxstk];
int main()
{
 int push(int);
 int display();
 int pop();
 int item,choice;
 
 while(1)
 {
  printf("\nStack Simulator");
  printf("\n 1.Push");
  printf("\n 2.Display");
  printf("\n 3.Pop");
  printf("\n 4.Exit");
  printf("\n\nEnter your choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1: printf("Enter the element to be added : ");
	   scanf("%d",&item);
	   push(item);
	   break;
   case 2: display();
	   break;
   case 3: pop();
	   break;
   case 4: exit();
   default: printf("Error in choice\n");
  }
 }
}
int push(int item)
{
 if(isfull())
 {
  printf("The element %d cannot be pushed to the stack\n",item);
  printf("Stack Overflow\n");
  return 0;
 }
 else
 {
  top++;
  stack[top]=item;
  printf("The element %d is pushed to the stack\n",item);
  if(top==maxstk-1)
  {
   printf("Stack is full\n");
  }
 }
}
int display()
{
 int p;
 p=top;
 if(p==(-1))
 {
  printf("\nStack is empty\n");
  return 0;
 }
 else
 {
  printf("Elements in the stack are : ");
  while(p!=(-1))
  {
   printf("\n%d",stack[p]);
   p--;
  }
  printf("\n");
  return 0;
 }
}
int pop()
{
 int item;
 if(isempty())
 {
  printf("Cannot pop the element\n");
  printf("Stack Underflow\n");
  return 0;
 }
 else
 {
  item=stack[top];
  top--;
  printf("The popped element is %d",item);
  printf("\n");
  if(top==-1)
  {
   printf("Stack is empty\n");
  }
 }
 return 0;
}
int isempty()
{
 if(top==-1)
  return 1;
 else
  return 0;
}
int isfull()
{
 if(top==maxstk-1)
  return 1;
 else
  return 0;
}







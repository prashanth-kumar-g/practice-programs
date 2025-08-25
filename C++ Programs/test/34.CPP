// returning a pointer to a structure from the function
#include<iostream>

#include<stdlib.h>
struct point
{
 int x;
 int y;
};
struct point* fun(int a,int b)
{
 struct point *ptr=(struct point *)malloc(sizeof(struct point));
 ptr->x=a;
 ptr->y=b+5;
 return(ptr);
}
void print(struct point *ptr)
{
 cout<<"\n "<<ptr->x;
 cout<<"\n "<<ptr->y;
}
int main()
{
 clrscr();

 struct point *ptr1=fun(2,3);

 struct point *ptr2;
 ptr2=fun(6,9);

 struct point *ptr3;
 ptr3->x=7;
 ptr3->y=5;
 fun(ptr3->x,ptr3->y);

 cout<<"\nThe values are\n";
 print(ptr1);
 cout<<"\n";
 print(ptr2);
 cout<<"\n";
 print(ptr3);

 free(ptr);
 return 0;
}
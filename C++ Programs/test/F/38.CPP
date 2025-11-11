// dangling pointer
#include<iostream>

#include<stdlib.h>
int *func1()
{
 int a=35;
 return(&a);
}
int main()
{
 clrscr();

 // case 1 : deallocating of a memory block
 int *ptr1=(int *)malloc(3*sizeof(int));
 ptr1[0]=10;    // ptr1=10;
 ptr1[1]=11;    // ptr1+1=11;
 ptr1[2]=12;    // ptr1+2=12;
 free(ptr1);    // ptr1 is now a dangling pointer

 // case 2 : function returning local variable address
 int *ptr2=func1();   // ptr2 is now a dangling pointer

 // case 3 : if a variable goes out of scope
 int *ptr3;
 {
  int a=35;  // scope of a starts here
  ptr3=&a;
 }           // scope of a ends here
	   // here variable goes out of scope which means ptr3 is pointing
	   // to a location which is freed and hence ptr3 is also now
	   // a dangling pointer

 return 0;
}
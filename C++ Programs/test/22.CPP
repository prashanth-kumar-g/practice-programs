// dynamic memory allocation
#include<iostream>

#include<stdlib.h>
int main()
{
 int *p;
 p=(int *)malloc(3*(sizeof(int)));

 clrscr();
				     // p[0]
 *p=11;                              // p[1]
 *(p+1)=12;                          // p[2]
 *(p+2)=13;

 cout<<"\np = "<<p;
 cout<<"\n(p+1) = "<<p+1;
 cout<<"\n(p+2) = "<<p+2;
 cout<<"\n\n*p = "<<*p;
 cout<<"\n*(p+1) = "<<*(p+1);
 cout<<"\n*(p+2) = "<<*(p+2);        // *(p+i) = p[i]
 cout<<"\n\np[0] = "<<p[0];          // *p = p[0]
 cout<<"\np[1] = "<<p[1];
 cout<<"\np[2] = "<<p[2];

 free(p);

 return 0;
}
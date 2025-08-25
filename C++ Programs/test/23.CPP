// dynamic memory allocation(input using user)
#include<iostream>

#include<stdlib.h>
int main()
{
 int *p,n,i;
 clrscr();
 cout<<"\nEnter the size : ";
 cin>>n;
 p=(int *)malloc(n*(sizeof(int)));

 cout<<"Enter the elements : ";
 for(i=1;i<=n;i++)                        // for(i=1;i<=n;i++)
 {                                        // {
  cin>>*(p+i);                            //  cin>>p[i];
 }                                        // }

 cout<<"\n\nThe addresses are  :  ";
 for(i=1;i<=n;i++)
 {
  cout<<"(p+"<<i<<") = "<<(p+i)<<"  ";
 }

 cout<<"\n\n\nThe elements are  :  ";
 for(i=1;i<=n;i++)
 {
  cout<<"*(p+"<<i<<") = "<<*(p+i)<<"  ";
 }

 cout<<"\n\nThe elements are  :  ";       // *(p+i) = p[i]
 for(i=1;i<=n;i++)                        // *p = p[0]
 {
  cout<<"p["<<i<<"] = "<<p[i]<<"  ";
 }

 free(p);

 return 0;
}

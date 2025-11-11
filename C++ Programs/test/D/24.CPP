// dynamic memory allocation and sort array
#include<iostream>

#include<stdlib.h>
int main()
{
 int *p,n,i,j,temp;
 clrscr();
 cout<<"\nEnter the size : ";
 cin>>n;
 p=(int *)malloc(n*(sizeof(int)));

 cout<<"Enter the elements : ";
 for(i=1;i<=n;i++)                       // for(i=1;i<=n;i++)
 {                                       // {
  cin>>*(p+i);                           //  cin>>p[i];
 }                                       // }

 cout<<"\nElements before sorting  :  ";
 for(i=1;i<=n;i++)                       // for(i=1;i<=n;i++)
 {                                       // {
  cout<<*(p+i)<<"  ";                    //  cout<<p[i]<<"  ":
 }                                       // }

 for(i=1;i<=n;i++)                       // for(i=1;i<=n;i++)
 {                                       // {
  for(j=1;j<=n-1;j++)                    //  for(j=1;j<=n;j++)
  {                                      //  {
   if(*(p+j) > *(p+j+1))                 //   if(p[j] > p[j+1];
   {                                     //   {
    temp = *(p+j);                       //    temp = p[j];
    *(p+j) = *(p+j+1);                   //    p[j] = p[j+1];
    *(p+j+1) = temp;                     //    p[j+1] = temp;
   }                                     //   }
  }                                      //  }
 }                                       // }

 cout<<"\nElements after sorting   :  ";
 for(i=1;i<=n;i++)                       // for(i=1;i<=n;i++)
 {                                       // {
  cout<<*(p+i)<<"  ";                    //  cout<<p[i]<<"  ";
 }

 free(p);                               // }

 return 0;
}
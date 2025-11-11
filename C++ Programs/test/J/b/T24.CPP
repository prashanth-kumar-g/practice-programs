// program to make a geometric series, print it and find the sum of it
#include<iostream>


/*

    Example:

    1    2    4    8   16   32   64   128   256   512


    Here:

    first term (a) -  1
    common ratio (r) -  2
    no. of terms (n) -  10


    Working:

    1   2   4   8   16   32  (i=i*r)

*/

int main()
{
 int a,r,n,i,sum=0;
 clrscr();
 cout<<"\nEnter the first term : ";
 cin>>a;
 cout<<"Enter the common ratio : ";
 cin>>r;
 cout<<"Enter the no. of terms : ";
 cin>>n;
 cout<<"\n";
 i=a;
 while(n>=1)
 {
  cout<<" + "<<i;
  sum=sum+i;
  i=i*r;
  n--;
 }
 cout<<" = "<<sum;
 return 0;
}
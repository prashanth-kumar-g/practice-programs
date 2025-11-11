// program to make a changing geometric series (one layer *),
// print it and find the sum of it
#include<iostream>

#include<iomanip>

/*

    Example:

      1    2    8    64    1024   32768    209752
	2    4     8    16     32      64


    Here:

    first term (a) -  1
    first ratio (fr) -  2
    next ratio (nr) -  2
    no. of terms (n) -  7


    Working:

    1    2    8    64    1024  (i=i*j)
      2    4     8    16       (j=j*nr)

*/

int main()
{
 int a,fr,nr,n;
 double i,j,sum=0;
 clrscr();
 cout<<"\nEnter the first term : ";
 cin>>a;
 cout<<"Enter the first ratio : ";
 cin>>fr;
 cout<<"Enter the next difference : ";
 cin>>nr;
 cout<<"Enter the no. of terms : ";
 cin>>n;
 cout<<"\n";
 i=a;
 j=nr;
 cout<<setiosflags(ios::fixed);
 while(n>=1)
 {
  cout<<" + "<<i;
  sum=sum+i;
  i=i*j;
  j=j*nr;
  n--;
 }
 cout<<" = "<<sum;
 return 0;
}
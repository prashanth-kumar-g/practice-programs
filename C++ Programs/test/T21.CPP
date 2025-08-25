// program to make a changing arithmetic series (one layer *),
// print it and find the sum of it
#include<iostream>

#include<iomanip>

/*

    Example:

      1    3    7    15     31     63      127
	2    4     8    16     32      64


    Here:

    first term (a) -  1
    first difference (fd) -  2
    next ratio (nr) -  2
    no. of terms (n) -  7


    Working:

    1    3    7    15    31  (i=i+j)
      2    4     8    16     (j=j*nr)

*/

int main()
{
 int a,fd,nr,n,i,j,sum=0;
 clrscr();
 cout<<"\nEnter the first term : ";
 cin>>a;
 cout<<"Enter the first difference : ";
 cin>>fd;
 cout<<"Enter the next ratio : ";
 cin>>nr;
 cout<<"Enter the no. of terms : ";
 cin>>n;
 cout<<"\n";
 i=a;
 j=fd;
 cout<<setiosflags(ios::fixed);
 while(n>=1)
 {
  cout<<" + "<<i;
  sum=sum+i;
  i=i+j;
  j=j*nr;
  n--;
 }
 cout<<" = "<<sum;
 return 0;
}
// program to make a changing geometric series (one layer +),
// print it and find the sum of it
#include<iostream>

#include<iomanip>

/*

    Example:

      1    2    8    48    384    3840    46080
	2    4     6     8      10     12


    Here:

    first term (a) -  1
    first ratio (fr) -  2
    next difference (nd) -  2
    no. of terms (n) -  7


    Working:

    1    2    8    48    384  (i=i*r)
      2    4     6     8      (j=j+nd)

*/

int main()
{
 int a,fr,nd,n,j;
 double i,sum=0;
 clrscr();
 cout<<"\nEnter the first term : ";
 cin>>a;
 cout<<"Enter the first ratio : ";
 cin>>fr;
 cout<<"Enter the next difference : ";
 cin>>nd;
 cout<<"Enter the no. of terms : ";
 cin>>n;
 cout<<"\n";
 i=a;
 j=fr;
 cout<<setiosflags(ios::fixed);
 while(n>=1)
 {
  cout<<" + "<<i;
  sum=sum+i;
  i=i*j;
  j=j+nd;
  n--;
 }
 cout<<" = "<<sum;
 return 0;
}
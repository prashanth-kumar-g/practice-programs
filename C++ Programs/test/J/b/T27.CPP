// program to make a changing geometric series (two layer ++),
// print it and find the sum of it
#include<iostream>

#include<iomanip>

/*

    Example:

      1    2    10    100  1700  44200   1635400
	2    5     10    17    26     37
	  3     5     7     9     11


    Here:

    first term (a) -  1
    first ratio (fr) -  2
    second ratio (sr) -  3
    next difference (nd) -  2
    no. of terms (n) -  7


    Working:

    1    2    10    100    1700  (i=i*j)
      2    5     10    100       (j=j+k)
	3     5     7            (k=k+nd)

*/

int main()
{
 int a,fr,sr,nd,n,j,k;
 double i,sum=0;
 clrscr();
 cout<<"\nEnter the first term : ";
 cin>>a;
 cout<<"Enter the first ratio : ";
 cin>>fr;
 cout<<"Enter the second ratio : ";
 cin>>sr;
 cout<<"Enter the next difference : ";
 cin>>nd;
 cout<<"Enter the no. of terms : ";
 cin>>n;
 cout<<"\n";
 i=a;
 j=fr;
 k=sr;
 cout<<setiosflags(ios::fixed);
 while(n>=1)
 {
  cout<<" + "<<i;
  sum=sum+i;
  i=i*j;
  j=j+k;
  k=k+nd;
  n--;
 }
 cout<<" = "<<sum;
 return 0;
}
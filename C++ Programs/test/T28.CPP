// program to make a changing geometric series (two layer +*),
// print it and find the sum of it
#include<iostream>

#include<iomanip>

/*

    Example:

      1    2     10     110    2530   118910   11296450
	2     5      11     23      47     95
	  3      6      12     24      48


    Here:

    first term (a) -  1
    first ratio (fr) -  2
    second ratio (sr) -  3
    next ratio (nd) -  2
    no. of terms (n) -  7


    Working:

    1    2    10    110    2530  (i=i*j)
      2    5     11    23        (j=j+k)
	3     6     12           (k=k*nd)

*/

int main()
{
 int a,fr,sr,nr,n,j;
 double i,k,sum=0;
 clrscr();
 cout<<"\nEnter the first term : ";
 cin>>a;
 cout<<"Enter the first ratio : ";
 cin>>fr;
 cout<<"Enter the second ratio : ";
 cin>>sr;
 cout<<"Enter the next ratio : ";
 cin>>nr;
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
  k=k*nr;
  n--;
 }
 cout<<" = "<<sum;
 return 0;
}
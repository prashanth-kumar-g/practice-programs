// program to make a changing geometric series (two layer *+),
// print it and find the sum of it
#include<iostream>

#include<iomanip>

/*

    Example:

      1    2     12      360   75600     142884000
	2     6      30      210    1890
	  3       5       7       9


    Here:

    first term (a) -  1
    first ratio (fr) -  2
    second ratio (sr) -  3
    next difference (nd) -  2
    no. of terms (n) -  7


    Working:

    1    2    12    360     75600  (i=i*j)
      2    6     30     210        (j=j*k)
	3     5      7             (k=k+nd)

*/

int main()
{
 int a,fr,sr,nd,n,k;
 double i,j,sum=0;
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
  j=j*k;
  k=k+nd;
  n--;
 }
 cout<<" = "<<sum;
 return 0;
}
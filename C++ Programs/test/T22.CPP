// program to make a changing arithmetic series (two layer **),
// print it and find the sum of it
#include<iostream>

#include<iomanip>

/*

    Example:

      1     3      9       45       477       10845
	2      6       36       432     10368
	  3        6       12       24


    Here:

    first term (a) -  1
    first difference (fd) -  2
    second difference (sd) -  3
    next ratio (nr) -  2
    no. of terms (n) -  7


    Working:

    1    3     9       45      477  (i=i+j)
      2     6      36      432      (j=j*k)
	3      6       12           (k=k*nd)

*/

int main()
{
 int a,fd,sd,nr,n;
 double i,j,k,sum=0;
 clrscr();
 cout<<"\nEnter the first term : ";
 cin>>a;
 cout<<"Enter the first difference : ";
 cin>>fd;
 cout<<"Enter the second difference : ";
 cin>>sd;
 cout<<"Enter the next ratio : ";
 cin>>nr;
 cout<<"Enter the no. of terms : ";
 cin>>n;
 cout<<"\n";
 i=a;
 j=fd;
 k=sd;
 cout<<setiosflags(ios::fixed);
 while(n>=1)
 {
  cout<<" + "<<i;
  sum=sum+i;
  i=i+j;
  j=j*k;
  k=k*nr;
  n--;
 }
 cout<<" = "<<sum;
 return 0;
}
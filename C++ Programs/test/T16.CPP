// program to make a changing arithmetic series (one layer),
// print it and find the sum of it

/*

    Example:

    1    3    6   10   15   21   28   36   45    55
      2    3    4    5    6    7    8    9    10


    Here:

    first term (a) -  1
    first difference (fd) -  2
    next difference (nd) -  1
    no. of terms (n) -  10


    Working:

    1    3    6   10   15  (i=i+j)
      2    3    4    5     (d=d+nd)

*/

#include<iostream>

int main()
{
 int a,fd,nd,d,n,i,sum=0;
 clrscr();
 cout<<"\nEnter the first term : ";
 cin>>a;
 cout<<"Enter the first difference : ";
 cin>>fd;
 cout<<"Enter the next difference : ";
 cin>>nd;
 cout<<"Enter the no. of terms : ";
 cin>>n;
 cout<<"\n";
 i=a;
 d=fd;
 while(n>=1)
 {
  cout<<" + "<<i;
  sum=sum+i;
  i=i+d;
  d=d+nd;
  n--;
 }
 cout<<" = "<<sum;
 return 0;
}

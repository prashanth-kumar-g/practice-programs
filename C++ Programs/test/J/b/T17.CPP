// program to make a changing arithmetic series (two layer),
// print it and find the sum of it

/*

    Example:

    1    3    8   17    31   51   78  113   157   211
      2    5    9    14   20   27   35   44    54
	3    4    5    6    7    8    9    10


    Here:

    first term (a) -  1
    first difference (fd) -  2
    second difference (sd) -  3
    next difference (nd) -  1
    no. of terms (n) -  10


    Working:

    1   3    8   17    31  (i=i+j)
      2   5    9    14     (j=j+d)
	3    4    5        (d=d+nd)

*/

#include<iostream>

int main()
{
 int a,fd,sd,nd,d,n,i,j,sum=0;
 clrscr();
 cout<<"\nEnter the first term : ";
 cin>>a;
 cout<<"Enter the first difference : ";
 cin>>fd;
 cout<<"Enter the second difference : ";
 cin>>sd;
 cout<<"Enter the next difference : ";
 cin>>nd;
 cout<<"Enter the no. of terms : ";
 cin>>n;
 cout<<"\n";
 i=a;
 j=fd;
 d=sd;
 while(n>=1)
 {
  cout<<" + "<<i;
  sum=sum+i;
  i=i+j;
  j=j+d;
  d=d+nd;
  n--;
 }
 cout<<" = "<<sum;
 return 0;
}



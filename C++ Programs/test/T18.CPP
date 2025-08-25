// program to make a changing arithmetic series (three layer),
// print it and find the sum of it

/*

    Example:

    1    3    8    20    44    86   153    253   395    589
      2    5    12    24    42    67   100    142   194
	3    7     12    18    25    33    42    52
	  4     5     6     7     8     9     10


    Here:

    first term (a) -  1
    first difference (fd) -  2
    second difference (sd) -  3
    third difference (td) -  4
    next difference (nd) -  1
    no. of terms (n) -  10


    Working:

    1    3    8    20    44   86  (i=i+j)
      2    5    12    24   42     (j=j+k)
	3    7     12   18        (k=k+d)
	  4     5     6           (d=d+nd)

*/

#include<iostream>

int main()
{
 int a,fd,sd,td,nd,d,n,i,j,k,sum=0;
 clrscr();
 cout<<"\nEnter the first term : ";
 cin>>a;
 cout<<"Enter the first difference : ";
 cin>>fd;
 cout<<"Enter the second difference : ";
 cin>>sd;
 cout<<"Enter the third difference : ";
 cin>>td;
 cout<<"Enter the next difference : ";
 cin>>nd;
 cout<<"Enter the no. of terms : ";
 cin>>n;
 cout<<"\n";
 i=a;
 j=fd;
 k=sd;
 d=td;
 while(n>=1)
 {
  cout<<" + "<<i;
  sum=sum+i;
  i=i+j;
  j=j+k;
  k=k+d;
  d=d+nd;
  n--;
 }
 cout<<" = "<<sum;
 return 0;
}

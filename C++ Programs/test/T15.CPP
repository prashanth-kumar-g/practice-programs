// program to make a arithmetic series, print it and find the sum of it
#include<iostream>


/*

    Example:

    1    5    9   13   17   21   25   29   33   37


    Here:

    first term (a) -  1
    common difference (d) -  4
    no. of terms (n) -  10


    Working:

    1   5   9   13   17   21  (i=i+d)

*/

int main()
{
 int a,d,n,i,sum=0;
 clrscr();
 cout<<"\nEnter the first term : ";
 cin>>a;
 cout<<"Enter the common difference : ";
 cin>>d;
 cout<<"Enter the no. of terms : ";
 cin>>n;
 cout<<"\n";
 i=a;
 while(n>=1)
 {
  cout<<" + "<<i;
  sum=sum+i;
  i=i+d;
  n--;
 }
 cout<<" = "<<sum;
 return 0;
}
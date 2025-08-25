// program to make a changing arithmetic series (four layer),
// print it and find the sum of it

/*

    Example:

    1    3    8    20    48    107   219   414    731    1219
      2    5    12    28    59    112   195   317    488
	3    7     16    31    53    83    122   171
	  4     9     15    22    30    39    49
	     5     6     7     8     9     10


    Here:

    first term (a) -  1
    first difference (fd) -  2
    second difference (sd) -  3
    third difference (td) -  4
    fourth difference (frd) -  5
    next difference (nd) -  1
    no. of terms (n) -  10


    Working:

    1    3   8    20   48    107    219  (i=i+j)
      2    5   12   28    59    112      (j=j+k)
	3    7   16    31    53          (k=k+l)
	  4    9    15    22             (l=l+d)
	    5     6     7                (d=d+nd)

*/

#include<iostream>

int main()
{
 int a,fd,sd,td,frd,nd,d,n,i,j,k,l,sum=0;
 clrscr();
 cout<<"\nEnter the first term : ";
 cin>>a;
 cout<<"Enter the first difference : ";
 cin>>fd;
 cout<<"Enter the second difference : ";
 cin>>sd;
 cout<<"Enter the third difference : ";
 cin>>td;
 cout<<"Enter the fourth difference : ";
 cin>>frd;
 cout<<"Enter the next difference : ";
 cin>>nd;
 cout<<"Enter the no. of terms : ";
 cin>>n;
 cout<<"\n";
 i=a;
 j=fd;
 k=sd;
 l=td;
 d=frd;
 while(n>=1)
 {
  cout<<" + "<<i;
  sum=sum+i;
  i=i+j;
  j=j+k;
  k=k+l;
  l=l+d;
  d=d+nd;
  n--;
 }
 cout<<" = "<<sum;
 return 0;
}

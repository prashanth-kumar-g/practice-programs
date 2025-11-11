// passing array into function
#include<iostream>

int arrsum(int a[],int n)
{
 int i,sum=0;
 for(i=1;i<=n;i++)
 {
  sum=sum+a[i];
 }
 return(sum);
}
int main()
{
 int n,i,a[10];
 clrscr();
 cout<<"\nEnter the size : ";
 cin>>n;
 cout<<"Enter the elements : ";
 for(i=1;i<=n;i++)
 {
  cin>>a[i];
 }
 cout<<"\nSum of elements = "<<arrsum(a,n);
 return 0;
}

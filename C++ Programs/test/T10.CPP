// program to print given numbers of prime number
#include<iostream>

int main()
{
 long int n,c,i,j,flag;
 clrscr();
 cout<<"\nEnter the number of terms : ";
 cin>>n;
 cout<<"\n";
 c=1;
 for(i=2;c<=n;i++)
 {
  flag=0;
  for(j=2;j*j<=i;j++)
  {
   if(i%j==0)
   {
    flag=1;
    break;
   }
  }
  if(flag==0)
  {
   cout<<"  "<<i;
   c++;
  }
 }
 return 0;
}







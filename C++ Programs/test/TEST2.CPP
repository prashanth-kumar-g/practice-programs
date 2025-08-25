#include<iostream>

#include<math.h>
int main()
{
 int x=1,y,a=0;
 clrscr();
 cout<<"\nEnter a number : ";
 cin>>y;
  while(x%y!=0)
  {
   x=x%y;
   a++;
   if(a>4)
    break;
   x=x*10;
  }
  cout<<"\n count = "<<a;
  return 0;
}
// passing array of structures as argument
#include<iostream>

struct point
{
 int x;
 int y;
};
void print(struct point arr[])
{
 int i;
 cout<<"\nThe values are\n";
 for(i=0;i<2;i++)
 {
  cout<<"\n "<<arr[i].x;
  cout<<"\n "<<arr[i].y;
 }
}
int main()
{
 clrscr();
 struct point arr[2]={ {1,2}, {3,4} };
 print(arr);
 return 0;
}
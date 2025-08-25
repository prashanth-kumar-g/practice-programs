// array and pointers arithmetic
#include<iostream>

int main()
{
 int i,a[3];
 int *p;
 clrscr();
 cout<<"\nEnter three elements : ";
 for(i=1;i<=3;i++)
 {
  cin>>a[i];
 }       // a+i = &a[i]
 p=a;    // a = &a[0]
 cout<<"\nThe address of elements using variable itself  are";
 for(i=1;i<=3;i++)
 {
  cout<<"\n"<<" &a["<<i<<"] = "<<&a[i];
 }
 cout<<"\nThe address of elements using pointers are";
 for(i=1;i<=3;i++)
 {
  cout<<"\n"<<" p + "<<i<<" = "<<p+i;
 }                                                       // p+i = &p[i]
 cout<<"\nThe address of elements using pointers are";   // p = &p[0]
 for(i=1;i<=3;i++)
 {
  cout<<"\n"<<" &p["<<i<<"] = "<<&p[i];
 }
 cout<<"\nThe elements using variable itself are";
 for(i=1;i<=3;i++)
 {
  cout<<"\n"<<" a["<<i<<"] = "<<a[i];
 }
 cout<<"\nThe elements using pointers are";
 for(i=1;i<=3;i++)
 {
  cout<<"\n"<<" *(p + "<<i<<") = "<<*(p+i);
 }                                              // *(p+i) = p[i]
 cout<<"\nThe elements using pointers are";     // *p = p[0]
 for(i=1;i<=3;i++)
 {
  cout<<"\n"<<" p["<<i<<"] = "<<p[i];
 }
 return 0;
}





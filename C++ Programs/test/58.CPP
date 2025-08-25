// union
#include<iostream>

#include<string.h>
int main()
{
 union money
 {
  int rice;
  char car[10];
  float pounds;
 } m1;
 clrscr();

 cout.precision(2);


 /*m1.rice=24;                       // we can use only one member at a time
 strcpy(m1.car,"suzuki");
 m1.pounds=35.74;                  // since last member will be initialised
 cout<<"\nm1.rice = "<<m1.rice;
 cout<<"\nm1.car = "<<m1.car;
 cout<<"\nm1.pounds = "<<m1.pounds; // it will be considered
 */

 /*
 m1.rice=24;                    // to use all members, use it at a time and print it and again initialise and print it
 cout<<"\nm1.rice =  "<<m1.rice;

 strcpy(m1.car,"suzuki");
 cout<<"\nm1.car = "<<m1.car;

 m1.pounds=35.74;
 cout<<"\nm1.pounds = "<<m1.pounds;
 */

 return 0;
}

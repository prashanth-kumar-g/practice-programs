// returning a structure variable from the function
#include<iostream>

#include<string.h>
struct point
{
 int x;
 int y;
};
struct point edit(struct point p)
{
 (p.x)++;
 p.y=p.y+5;
 return(p);
}
void print(struct point p)
{
 cout<<"\n "<<p.x;
 cout<<"\n "<<p.y;
}
int main()
{
 clrscr();

 struct point p1={23,45};
 struct point p2={56,90};

 p1=edit(p1);
 p2=edit(p2);

 cout<<"\nThe values are\n";
 print(p1);
 cout<<"\n";
 print(p2);

 return 0;
}
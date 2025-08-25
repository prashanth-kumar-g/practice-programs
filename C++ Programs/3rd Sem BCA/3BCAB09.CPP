//program to iluustrate conversion from class to basic type
#include<iostream>

class time
{
 private : int hrs,mins;
 public : time(int h,int m)
	  {
	   hrs=h;
	   mins=m;
	  }
	  void display()
	  {
	   cout<<"\n"<<hrs<<" hours";
	   cout<<" "<<mins<<" mins";
	  }
	  operator int()
	  {
	   return(hrs*60+mins);
	  }
};
int main()
{
 clrscr();
 int x,y,duration;
 cout<<"\nEnter the time in hrs and mins : ";
 cin>>x>>y;
 time t(x,y);
 t.display();
 duration=t;
 cout<<"\n"<<duration<<" mins";
 return 0;
}
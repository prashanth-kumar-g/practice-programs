//program to generate student report using inheritance technique
#include<iostream>

#include<iomanip>
class student
{
 private : char name[20];
	   int reg;
 public : void getdata()
	  {
	   cout<<"\nType Name : ";
	   cin>>name;
	   cout<<"Type Register No. : ";
	   cin>>reg;
	  }
	  void showdata()
	  {
	   cout<<setprecision(2);
	   cout.setf(ios::left,ios::adjustfield);
	   cout<<"\nName : "<<setw(10)<<name<<endl;
	   cout<<"Regisyter No. : "<<setw(3)<<reg<<endl;
	  }
};
class marks:public student
{
 protected : int m1,m2,m3;
	     float perc;
 public : void getmarks()
	  {
	   cout<<"Marks in C++, OS, AFM : ";
	   cin>>m1>>m2>>m3;
	   perc=(m1+m2+m3)/300.00*100;
	  }
	  void showmarks()
	  {
	   cout<<"C++ : "<<setw(5)<<m1<<endl;
	   cout<<"OS : "<<setw(5)<<m2<<endl;
	   cout<<"AFM : "<<setw(5)<<m3<<endl;
	   cout<<"Percantage : "<<setw(5)<<perc<<endl;
	  }
};
class result:public marks
{
 private : char grade;
 public : char getgrade()
	  {
	   if(m1<40 || m2<40 || m3<40)
	    grade='F';
	   else if(perc>=75)
	    grade='A';
	   else if(perc>=60)
	    grade='B';
	   else if(perc>=50)
	    grade='C';
	   else if(perc>=40)
	    grade='D';
	   else
	    grade='F';
	   return grade;
	  }
	  void display()
	  {
	   showdata();
	   showmarks();
	   cout<<"Grade : "<<setw(10)<<getgrade()<<endl;
	  }
};
int main()
{
 result std;
 clrscr();
 cout<<"\nGrade A -> 75% and Above"<<endl;
 cout<<"Grade B -> 60% and 74%"<<endl;
 cout<<"Grade C -> 50% and 59%"<<endl;
 cout<<"Grade D -> 40% and 49%"<<endl;
 cout<<"Grade F -> Below 40%"<<endl;
 std.getdata();
 std.getmarks();
 std.display();
 return 0;
}

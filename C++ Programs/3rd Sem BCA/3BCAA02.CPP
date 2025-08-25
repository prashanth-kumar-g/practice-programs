//program to perform bank transactions
#include<iostream>

#include<iomanip>
class current;
class saving
{
 private : char name[30];
	   int acc_no;
	   float balance;
 public : void getdata()
	  {
	   cout<<"Saving Account Details"<<endl;
	   cout<<"Name : ";
	   cin>>name;
	   cout<<"Account No. : ";
	   cin>>acc_no;
	   cout<<"Balance : ";
	   cin>>balance;
	  }
 friend float totbalance(saving, current);
};
class current
{
 private : char name[30];
	   int acc_no;
	   float balance;
 public : void getdata()
	  {
	   cout<<"\nCurrent Account Details"<<endl;
	   cout<<"Name : ";
	   cin>>name;
	   cout<<"Account No. : ";
	   cin>>acc_no;
	   cout<<"Balance : ";
	   cin>>balance;
	  }
 friend float totbalance(saving, current);
};
float totbalance(saving sav, current cur)
{
 cout<<"\nSaving Balance ="<<setw(5)<<sav.balance<<endl;
 cout<<"Current Balance ="<<setw(5)<<cur.balance<<endl;
 return(sav.balance + cur.balance);
}
int main()
{
 saving s;
 current c;
 clrscr();
 s.getdata();
 c.getdata();
 cout<<"Total Balance ="<<setw(5)<<totbalance(s,c);
 return 0;
}
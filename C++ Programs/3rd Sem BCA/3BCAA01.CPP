// program to prepare shopping list
#include <iostream>

#include <iomanip>
const int size = 3;
class item
{
private:
	char name[30];
	float qty;
	float rate;
	float amt;

public:
	void getdata()
	{
		cout << "\nEnter the details" << endl;
		cout << " Name : ";
		cin >> name;
		cout << " Quantity : ";
		cin >> qty;
		cout << " Rate : ";
		cin >> rate;
	}
	void putdata()
	{
		amt = qty * rate;
		cout << setw(12) << name << setw(12) << qty << setw(12) << rate << setw(12) << amt << endl;
	}
};
int main()
{
	item shop[size];
	clrscr();
	for (int i = 1; i <= size; i++)
	{
		shop[i].getdata();
	}
	cout << endl
		 << "\n*************** The shopping details are ***************\n"
		 << endl;
	cout << setw(12) << "Name" << setw(12) << "Quantity" << setw(12) << "Rate" << setw(12) << "Amount" << endl;
	for (i = 1; i <= size; i++)
	{
		shop[i].putdata();
	}
	return 0;
}
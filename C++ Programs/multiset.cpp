// C++ program to illustrate multiset
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
	// creating vector
	vector<int> v = { 1, 5, 3, 4, 2, 5, 3 };
	// creating set using vector v
	multiset<int> s(v.begin(), v.end());

	// finding 4
	if (s.find(4) == s.end()) {
		cout << "5 not found" << endl;
	}
	else {
		cout << "5 found" << endl;
	}

	// adding 9
	s.insert(9);

	// printing set
	cout << "s: ";
	for (set<int>::iterator i = s.begin(); i != s.end();	i++) {
		cout << *i << " ";
	}
	cout << endl;
	return 0;
}

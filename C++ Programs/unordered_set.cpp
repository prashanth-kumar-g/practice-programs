// C++ Program to illustrate the unordered_set container
#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{

	// creating an unordered_set object
	unordered_set<int> us = { 1, 5, 2, 3, 4 };

	// checking size
	cout << "Size of us: " << us.size() << endl;

	// inserting data
	us.insert(7);

	// finding some key
	if (us.find(3) != us.end()) {
		cout << "3 found!" << endl;
	}
	else {
		cout << "3 not found" << endl;
	}

	// traversing unordered_set using iterators
	cout << "us: ";
	for (auto i = us.begin(); i != us.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	return 0;
}

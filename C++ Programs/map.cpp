// C++ Program to illustrate the map container
#include <iostream>
#include <map>
using namespace std;

int main()
{

	// creating std::map object
	map<int, string> m;

	// adding elements
	m[1] = "ONE";
	m[2] = "TWO";
	m[3] = "THREE";

	// checking size
	cout << "Size of map m: " << m.size() << endl;

	// inserting using insert pair
	m.insert({ 4, "FOUR" });

	// deleting key 2 with its value
	m.erase(2);

	// printing the map
	cout << "Map:-" << endl;
	for (auto i : m) {
		cout << "Key: " << i.first << '\t';
		cout << "Value: " << i.second << endl;
	}

	return 0;
}

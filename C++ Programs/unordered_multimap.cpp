// C++ program to illustrate the unordered_multimap container
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	// creating unordered_map object
	unordered_multimap<int, string> umap;

	// adding elements
	umap.insert({{1,"ONE"}, {2,"TWO"}, {3,"THREE"}});

    // adding duplicate keys
    umap.insert({3,"THREE"});

	// finding some key
	if (umap.find(12) != umap.end()) {
		cout << "Key 12 Found!" << endl;
	}
	else {
		cout << "Key 12 Not Found!" << endl;
	}

	// traversing whole map at once using iterators
	cout << "umap:--" << endl;
	for (auto i = umap.begin(); i != umap.end(); i++) {
		cout << "Key:" << i->first
			<< "\tValue: " << i->second << endl;
	}

	return 0;
}

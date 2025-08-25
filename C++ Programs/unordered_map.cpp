// C++ program to illustrate the unordered_map container
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	// creating unordered_map object
	unordered_map<int, string> umap;

	// inserting key value pairs
	umap[1] = "ONE";
	umap[2] = "TWO";
	umap[3] = "THREE";
	umap.insert({ 4, "FOUR" });

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

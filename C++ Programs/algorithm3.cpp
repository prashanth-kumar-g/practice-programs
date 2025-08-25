// program to demonstrate the functions of algorithm lirary - 3
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	// Initializing vector with array values
	int arr[] = {5, 10, 15, 20, 23, 42, 45};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> vect(arr, arr+n);

	// Sort the array to make sure that lower_bound()
	// and upper_bound() work.
	sort(vect.begin(), vect.end());

	// Returns the first occurrence of 20
	auto q = lower_bound(vect.begin(), vect.end(), 20);

	// Returns the last occurrence of 20
	auto p = upper_bound(vect.begin(), vect.end(), 20);

	cout << "The lower bound is at position: ";
	cout << q-vect.begin() << endl;

	cout << "The upper bound is at position: ";
	cout << p-vect.begin() << endl;

    // binary search
    if(binary_search(vect.begin(),vect.end(),15))
        cout<<"15 exits in vect";
    else
        cout<<"15 doesn't exits in vect";

	return 0;
}

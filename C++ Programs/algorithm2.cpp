// program to demonstrate the functions of algorithm lirary - 2
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // Initializing vector with array values
    int arr[] = {10, 20, 5, 23, 42, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);

    cout << "Occurrences of 20 in vector : ";

    // Counts the occurrences of 20 from 1st to last element
    cout << count(vect.begin(), vect.end(), 20);

    // find() returns iterator to last address if element not present
    find(vect.begin(), vect.end(), 23) != vect.end() ? cout << "\nElement found" : cout << "\nElement not found";

    // search function
    vector<int>sub_vec={23,42,20};
    auto it = search(vect.begin(), vect.end(), sub_vec.begin(), sub_vec.end());
    if (it != vect.end())
        cout << "\nsub_vec found at position : " << (it-vect.begin()) << '\n';
    else
        cout << "\nsub_vec not found\n";
    return 0;
}

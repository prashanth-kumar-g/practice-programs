// program to demonstrate the functions of algorithm lirary - 5
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // Initializing vector with array values
    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);

    cout << "Given Vector is : ";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";

    // modifies vector to its next permutation order
    next_permutation(vect.begin(), vect.end());
    cout << "\nVector after performing next permutation : ";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";

    prev_permutation(vect.begin(), vect.end());
    cout << "\nVector after performing prev permutation : ";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";

    vector<int> vect2 = {10, 15, 5, 23, 20, 45, 42, 20};
    if (is_permutation(vect.begin(), vect.end(), vect2.begin()))
        cout << "\nvect and vect2 contain the same elements.\n";

    return 0;
}
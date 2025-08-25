// program to demonstrate the functions of algorithm lirary - 4
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
void myfunction (int i)
{ 
    cout << ' ' << i*i;
}
int main()
{
    // Initializing vector with array values
    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);

    cout << "Given Vector is:\n";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";

    vect.erase(find(vect.begin(), vect.end(), 10));
    cout << "\nVector after erasing element:\n";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";

    vect.erase(unique(vect.begin(), vect.end()), vect.end());
    cout << "\nVector after removing duplicates:\n";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";

    // Return distance of first to maximum element
    cout << "\nDistance between first to max element: ";
    cout << distance(vect.begin(), max_element(vect.begin(), vect.end()));

    // for_each function
    cout << "\nvector contains:";
    for_each(vect.begin(), vect.end(), myfunction);
    
    return 0;
}
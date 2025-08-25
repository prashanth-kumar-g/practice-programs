// program to demonstrate the functions of algorithm lirary - 1
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric> //For accumulate operation
using namespace std;
bool IsOdd(int i)
{
    return (i % 2) == 1;
}
int main()
{
    // Initializing vector with array values
    int arr[] = {10, 20, 5, 23, 42, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);

    cout << "Vector is: ";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";

    // Sorting the Vector in Ascending order
    sort(vect.begin(), vect.end());

    cout << "\nVector after sorting is: ";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";

    // Sorting the Vector in Descending order
    sort(vect.begin(), vect.end(), greater<int>());

    cout << "\nVector after sorting in Descending order is: ";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";

    // Reversing the Vector (descending to ascending , ascending to descending)
    reverse(vect.begin(), vect.end());

    cout << "\nVector after reversing is: ";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";

    cout << "\nMaximum element of vector is: ";
    cout << *max_element(vect.begin(), vect.end());

    cout << "\nMinimum element of vector is: ";
    cout << *min_element(vect.begin(), vect.end());

    // Starting the summation from 0
    cout << "\nThe summation of vector elements is: ";
    cout << accumulate(vect.begin(), vect.end(), 0);
    
    // partition function
    vector<int>::iterator bound;
    bound = partition(vect.begin(), vect.end(), IsOdd);
    cout<<"\nSame vector partitioned into two halves";
    cout << "\n odd elements:";
    for (vector<int>::iterator it = vect.begin(); it != bound; ++it)
    {
        cout << ' ' << *it;
    }
    cout << "\n even elements:";
    for (vector<int>::iterator it = bound; it != vect.end(); ++it)
    {
        cout << ' ' << *it;
    }

    // merge function
    vector<int>v1={5,15,10,25,20};
    vector<int>v2={3,9,6,15,12};
    vector<int>v3(v1.size()+v2.size());
    cout<<"\nVector 1 is : ";
    for (vector<int>::iterator it=v1.begin(); it!=v1.end(); ++it)
    {
        cout << ' ' << *it;
    }
    cout<<"\nVector 2 is : ";
    for (vector<int>::iterator it=v2.begin(); it!=v2.end(); ++it)
    {
        cout << ' ' << *it;
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    merge (v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    cout<<"\nMerged vector is : ";
    for (vector<int>::iterator it=v3.begin(); it!=v3.end(); ++it)
    {
        cout << ' ' << *it;
    }
    return 0;
}
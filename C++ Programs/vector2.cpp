// program for vectors ( using iterator ) 
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    int ele, size;
    cout << "Enter the size of vector : ";
    cin >> size;
    v.resize(size);
    vector<int>::iterator i;
    cout << "Enter the vector elements : ";
    for (i = v.begin(); i != v.end(); i++)
    {
        cin >> *i;
    }
    cout << "The vector elements are : ";
    for (i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}
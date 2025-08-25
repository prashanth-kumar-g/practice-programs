// program for vectors ( using reference operator  )
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size of vector : ";
    cin>>size;
    vector<int> v(size);
    cout<<"Enter the elements of vector : ";
    for (int i = 0; i < size; i++)
    {
        cin>>v[i];
    }
    cout << "The vector elements are : ";
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
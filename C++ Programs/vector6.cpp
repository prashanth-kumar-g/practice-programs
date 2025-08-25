// program to illustrate the capacity function in vector
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;

    for (int i = 1; i <= 5; i++)
    {
        v.push_back(i);
    }

    cout << "Size : " << v.size();
    cout << "\nCapacity : " << v.capacity();
    cout << "\nMax_Size : " << v.max_size();

    // resizes the vector size to 4
    v.resize(4);

    // prints the vector size after resize()
    cout << "\nSize : " << v.size();

    // checks if the vector is empty or not
    if (v.empty() == false)
    {
        cout << "\nVector is not empty";
    }
    else
    {
        cout << "\nVector is empty";
    }

    // Shrinks the vector
    // v.shrink_to_fit();

    cout << "\nVector elements are: ";
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}
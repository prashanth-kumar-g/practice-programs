// program for vectors and passing vectors in a function
#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
int main()
{
    vector<int> v;
    int ele, size;
    cout << "Enter the size of vector : ";
    cin >> size;
    cout << "Enter the vector elements : ";
    for (int i = 0; i < size; i++)
    {
        cin >> ele;
        v.push_back(ele);
    }
    cout << "The vector elements are : ";
    display(v);
    return 0;
}
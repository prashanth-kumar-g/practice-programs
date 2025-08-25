// program to illustrate iterators in vector
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
    cout << "Output of begin and end : ";
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\nOutput of rbegin and rend : ";
    for (auto i = v.rbegin(); i != v.rend(); i++)
    {
        cout << *i << " ";
    }
}
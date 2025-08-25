// program to illustrate the different methods of accessing elements in vector
#include <iostream>
#include <vector>
using namespace std;

int main()

{
    vector<int> v;

    for (int i = 1; i <= 10; i++)
    {
        v.push_back(i * 10);
    }

    cout << "Reference operator [g] : v[2] = " << v[2];

    cout << "\nfront() : v.front() = " << v.front();

    cout << "\nat : v.at(4) = " << v.at(4);

    cout << "\nback() : v.back() = " << v.back();

    return 0;
}
// Program 01: Basic Input & Output with deque
// Demonstrates different ways of reading and printing deque elements.

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d(5); // fixed size deque

    cout << "Enter the elements of deque: ";

    /* 1️⃣ Using index-based loop for input */
    for (int i = 0; i < d.size(); i++)
        cin >> d[i];

    /* 2️⃣ Using iterator for input */
    for (auto it = d.begin(); it != d.end(); it++)
        cin >> *it;

    /* 3️⃣ Using push_back (dynamic input) */
    int ele;
    for (int i = 0; i < 5; i++)
    {
        cin >> ele;
        d.push_back(ele);
    }

    cout << "\nThe deque elements are: ";

    /* 1️⃣ Using index-based loop for output */
    for (int i = 0; i < d.size(); i++)
        cout << d[i] << " ";

    /* 2️⃣ Using iterator for output */
    for (auto it = d.begin(); it != d.end(); it++)
        cout << *it << " ";

    /* 3️⃣ Using range-based loop for output */
    for (int x : d)
        cout << x << " ";

    return 0;
}

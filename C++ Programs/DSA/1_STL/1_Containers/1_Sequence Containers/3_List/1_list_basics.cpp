// Program 01: Basic Input & Output with list
// Demonstrates different ways of reading and printing list elements.

#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> L;
    int n, ele;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements of list: ";

    /* 1st way: Using push_back() */
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        L.push_back(ele);
    }

    /* 2nd way: Using push_front()
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        L.push_front(ele);
    }
    */

    cout << "\nThe list elements are: ";

    /* 1st way: Using iterator */
    for (list<int>::iterator it = L.begin(); it != L.end(); it++)
        cout << *it << " ";

    /* 2nd way: Using auto iterator
    for (auto it = L.begin(); it != L.end(); it++)
        cout << *it << " ";
    */

    /* 3rd way: Using range-based for loop
    for (int x : L)
        cout << x << " ";
    */

    return 0;
}

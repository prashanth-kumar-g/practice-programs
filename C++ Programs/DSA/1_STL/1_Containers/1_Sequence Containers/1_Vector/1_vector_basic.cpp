// Program 01: Basic Input & Output with vector
// Demonstrates different ways of reading and printing vector elements.

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v(5);

    cout<<"Enter the elements of vector : ";

    /* 1️⃣ Using index-based loop for input */ 
    for (int i = 0; i < v.size(); i++)
    { 
        cin>>v[i];
    }

    /* 2️⃣ Using iterator for input */
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cin >> *it;
    }

    /* 3️⃣ Using push_back (dynamic input) */
    int ele;
    for (int i = 0; i < v.size(); i++)
    {
        cin >> ele;
        v.push_back(ele);
    }

    cout << "The vector elements are : ";
    
    /* 1️⃣ Using index-based loop for output */
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    /* 2️⃣ Using iterator for output */
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it;
    }

    /* 3️⃣ Using range-based loop for output */
    for (int x : v) 
    {
        cout << x << " ";
    }

    return 0;
}
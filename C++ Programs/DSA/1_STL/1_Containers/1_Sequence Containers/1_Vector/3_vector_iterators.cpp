// Program 03: Iterators in vector
// Demonstrates iterator types used with std::vector: iterator, const_iterator, reverse_iterator, and const_reverse_iterator.

#include <iostream>
#include <vector>
using namespace std;

void printVec(const vector<int>& v, const string& msg)
{
    cout << msg << " (size = " << v.size() << "): ";
    for (int x : v) cout << x << " ";
    cout << "\n\n";
}

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};
    printVec(v, "\nInitial vector");

    // ----------------------------------------------------
    // 1️⃣ iterator -> begin(), end()  (modifiable)
    // ----------------------------------------------------
    cout << "1) iterator using begin() & end() (modifiable)\n";

    cout << "   Printing elements: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)  // original type
        cout << *it << " ";
    cout << "\n";

    cout << "   Modifying (+5 to each): ";
    for (auto it = v.begin(); it != v.end(); ++it)  // auto version
        *it = *it + 5;

    printVec(v, "   Vector after modification");


    // ----------------------------------------------------
    // 2️⃣ const_iterator -> cbegin(), cend() (read only)
    // ----------------------------------------------------
    cout << "2) const_iterator using cbegin() & cend() (read only)\n";

    cout << "   Printing elements: ";
    for (auto it = v.cbegin(); it != v.cend(); ++it) // auto as const_iterator
        cout << *it << " ";
    cout << "\n\n";
    // ❌ Modification not allowed here.


    // ----------------------------------------------------
    // 3️⃣ reverse_iterator -> rbegin(), rend() (modifiable)
    // ----------------------------------------------------
    cout << "3) reverse_iterator using rbegin() & rend() (modifiable)\n";

    cout << "   Printing in reverse: ";
    for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit) // original type
        cout << *rit << " ";
    cout << "\n";

    cout << "   Modifying (-5 from each): ";
    for (auto rit = v.rbegin(); rit != v.rend(); ++rit) // auto version
        *rit = *rit - 5;

    printVec(v, "   Vector after modification");


    // ----------------------------------------------------
    // 4️⃣ const_reverse_iterator -> crbegin(), crend() (read only)
    // ----------------------------------------------------
    cout << "4) const_reverse_iterator using crbegin() & crend() (read only)\n";

    cout << "   Printing in reverse: ";
    for (auto rit = v.crbegin(); rit != v.crend(); ++rit) // auto as const_reverse_iterator
        cout << *rit << " ";
    cout << "\n\n";


    printVec(v, "Final vector state");

    return 0;
}

// Program 03: Iterators in deque
// Demonstrates iterator types used with std::deque: iterator, const_iterator, reverse_iterator, and const_reverse_iterator.

#include <iostream>
#include <deque>
using namespace std;

void printDeque(const deque<int>& d, const string& msg)
{
    cout << msg << " (size = " << d.size() << "): ";
    for (int x : d) cout << x << " ";
    cout << "\n\n";
}

int main()
{
    deque<int> d = {10, 20, 30, 40, 50};
    printDeque(d, "\nInitial deque");

    // ----------------------------------------------------
    // 1️⃣ iterator -> begin(), end()  (modifiable)
    // ----------------------------------------------------
    cout << "1) iterator using begin() & end() (modifiable)\n";

    cout << "   Printing elements: ";
    for (deque<int>::iterator it = d.begin(); it != d.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    cout << "   Modifying (+5 to each): ";
    for (auto it = d.begin(); it != d.end(); ++it)
        *it = *it + 5;

    printDeque(d, "   Deque after modification");


    // ----------------------------------------------------
    // 2️⃣ const_iterator -> cbegin(), cend() (read only)
    // ----------------------------------------------------
    cout << "2) const_iterator using cbegin() & cend() (read only)\n";

    cout << "   Printing elements: ";
    for (auto it = d.cbegin(); it != d.cend(); ++it)
        cout << *it << " ";
    cout << "\n\n";
    // (Modifying elements is not allowed here)


    // ----------------------------------------------------
    // 3️⃣ reverse_iterator -> rbegin(), rend() (modifiable)
    // ----------------------------------------------------
    cout << "3) reverse_iterator using rbegin() & rend() (modifiable)\n";

    cout << "   Printing in reverse: ";
    for (deque<int>::reverse_iterator rit = d.rbegin(); rit != d.rend(); ++rit)
        cout << *rit << " ";
    cout << "\n";

    cout << "   Modifying (-5 from each): ";
    for (auto rit = d.rbegin(); rit != d.rend(); ++rit)
        *rit = *rit - 5;

    printDeque(d, "   Deque after modification");


    // ----------------------------------------------------
    // 4️⃣ const_reverse_iterator -> crbegin(), crend() (read only)
    // ----------------------------------------------------
    cout << "4) const_reverse_iterator using crbegin() & crend() (read only)\n";

    cout << "   Printing in reverse: ";
    for (auto rit = d.crbegin(); rit != d.crend(); ++rit)
        cout << *rit << " ";
    cout << "\n\n";

    printDeque(d, "Final deque state");

    return 0;
}

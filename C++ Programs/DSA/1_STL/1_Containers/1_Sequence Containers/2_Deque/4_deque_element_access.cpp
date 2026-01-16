// Program 04: Element Access in deque
// Demonstrates accessing elements using operator[], at(), front(), and back().

#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int>& d, const string& msg)
{
    cout << msg << " (size = " << d.size() << "): ";
    for (int x : d) cout << x << " ";
    cout << "\n\n";
}

int main()
{
    deque<int> d = {10, 20, 30, 40, 50};
    printDeque(d, "\nInitial deque");

    // 1️⃣ operator[]  (no bounds checking)
    cout << "1) Access using operator[]:\n";
    cout << "   d[0] = " << d[0] << "\n";
    cout << "   d[2] = " << d[2] << "\n\n";
    // Note: Accessing invalid index using [] = undefined behavior.

    // 2️⃣ at()  (bounds-checked access)
    cout << "2) Access using at():\n";
    cout << "   d.at(1) = " << d.at(1) << "\n";
    cout << "   d.at(3) = " << d.at(3) << "\n\n";
    // d.at(10); // would throw out_of_range exception

    // 3️⃣ front()  (first element)
    cout << "3) Access first element using front(): " << d.front() << "\n\n";

    // 4️⃣ back()   (last element)
    cout << "4) Access last element using back(): " << d.back() << "\n\n";

    return 0;
}

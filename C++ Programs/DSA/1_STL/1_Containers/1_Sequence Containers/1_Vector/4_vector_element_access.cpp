// Program 04: Element Access in vector
// Demonstrates accessing elements using operator[], at(), front(), back(), and data().

#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int>& v, const string& msg)
{
    cout << msg << " (size = " << v.size() << "): ";
    for (int x : v) cout << x << " ";
    cout << "\n\n";
}

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};
    printVec(v, "\nInitial vector");

    // 1️⃣ operator[]  (no bounds checking)
    cout << "1) Access using operator[]:\n";
    cout << "   v[0] = " << v[0] << "\n";
    cout << "   v[2] = " << v[2] << "\n\n";
    // Note: Accessing invalid index using [] = undefined behavior.

    // 2️⃣ at()  (safe, bounds-checked access)
    cout << "2) Access using at():\n";
    cout << "   v.at(1) = " << v.at(1) << "\n";
    cout << "   v.at(3) = " << v.at(3) << "\n\n";
    // v.at(10); // would throw out_of_range exception

    // 3️⃣ front()  (first element)
    cout << "3) Access first element using front(): " << v.front() << "\n\n";

    // 4️⃣ back()   (last element)
    cout << "4) Access last element using back(): " << v.back() << "\n\n";

    // 5️⃣ data()  (direct pointer to internal array)
    cout << "5) Access using data():\n";
    int* ptr = v.data(); // same as &v[0]
    cout << "   First element through pointer = " << *ptr << "\n";
    cout << "   Second element through pointer = " << *(ptr + 1) << "\n\n";

    return 0;
}

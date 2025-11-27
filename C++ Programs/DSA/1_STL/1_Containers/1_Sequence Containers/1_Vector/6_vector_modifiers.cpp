// Program 06: Modifiers in vector
// Demonstrates modifier functions like push_back(), pop_back(), insert(), erase(), emplace(), emplace_back(), clear(), and swap().

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
    // Start with some initial elements
    vector<int> v = {10, 20, 30};
    printVec(v, "\nInitial vector v");

    // 1️⃣ push_back() - add elements at the end
    cout << "1) push_back():\n";
    v.push_back(40);
    v.push_back(50);
    printVec(v, "   After push_back(40), push_back(50)");

    // 2️⃣ pop_back() - remove last element
    cout << "2) pop_back():\n";
    v.pop_back();  // removes 50
    printVec(v, "   After pop_back()");

    // 3️⃣ insert() - insert at specific positions
    cout << "3) insert():\n";
    v.insert(v.begin(), 5);              // at beginning
    printVec(v, "   After insert(5) at beginning");

    v.insert(v.begin() + 2, 25);         // at index 2
    printVec(v, "   After insert(25) at index 2");

    // 4️⃣ erase() - erase element at position
    cout << "4) erase():\n";
    v.erase(v.begin());                  // erase first element
    printVec(v, "   After erase first element");

    if (v.size() > 2)
    {
        v.erase(v.begin() + 1);          // erase element at index 1
        printVec(v, "   After erase element at index 1");
    }

    // 5️⃣ emplace() - construct element in-place at position
    cout << "5) emplace():\n";
    v.emplace(v.begin(), 100);           // insert 100 at beginning
    printVec(v, "   After emplace(100) at beginning");

    // 6️⃣ emplace_back() - construct element in-place at end
    cout << "6) emplace_back():\n";
    v.emplace_back(200);                 // add 200 at end
    printVec(v, "   After emplace_back(200)");

    // 7️⃣ clear() - remove all elements
    cout << "7) clear():\n";
    v.clear();
    printVec(v, "   After clear()");
    cout << "   v.empty(): " << (v.empty() ? "Yes" : "No") << "\n\n";

    // 8️⃣ swap() - swap contents of two vectors
    cout << "8) swap():\n";
    vector<int> a = {1, 2, 3};
    vector<int> b = {100, 200};

    printVec(a, "   Vector a before swap");
    printVec(b, "   Vector b before swap");

    a.swap(b);   // or swap(a, b);

    printVec(a, "   Vector a after swap");
    printVec(b, "   Vector b after swap");

    return 0;
}

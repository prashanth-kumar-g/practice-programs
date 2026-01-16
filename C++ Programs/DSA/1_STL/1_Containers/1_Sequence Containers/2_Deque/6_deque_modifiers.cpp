// Program 06: Modifiers in deque
// Demonstrates modifier functions like push_back(), push_front(), pop_back(), pop_front(),
// insert(), erase(), emplace(), emplace_back(), emplace_front(), clear(), and swap().

#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int> &d, const string &msg)
{
    cout << msg << " (size = " << d.size() << "): ";
    for (int x : d) cout << x << " ";
    cout << "\n\n";
}

int main()
{
    // Start with some initial elements
    deque<int> d = {10, 20, 30};
    printDeque(d, "\nInitial deque d");

    // 1️⃣ push_back() - add elements at the end
    cout << "1) push_back():\n";
    d.push_back(40);
    d.push_back(50);
    printDeque(d, "   After push_back(40), push_back(50)");

    // 2️⃣ push_front() - add elements at the front
    cout << "2) push_front():\n";
    d.push_front(5);
    d.push_front(1);
    printDeque(d, "   After push_front(5), push_front(1)");

    // 3️⃣ pop_back() - remove last element
    cout << "3) pop_back():\n";
    d.pop_back();  // removes last element
    printDeque(d, "   After pop_back()");

    // 4️⃣ pop_front() - remove first element
    cout << "4) pop_front():\n";
    d.pop_front(); // removes first element
    printDeque(d, "   After pop_front()");

    // 5️⃣ insert() - insert at specific positions
    cout << "5) insert():\n";
    d.insert(d.begin(), 100);              // at beginning
    printDeque(d, "   After insert(100) at beginning");

    if (d.size() > 2)
    {
        d.insert(d.begin() + 2, 999);      // at index 2
        printDeque(d, "   After insert(999) at index 2");
    }

    // 6️⃣ erase() - erase element at position
    cout << "6) erase():\n";
    d.erase(d.begin());                    // erase first element
    printDeque(d, "   After erase first element");

    if (d.size() > 1)
    {
        d.erase(d.begin() + 1);            // erase element at index 1
        printDeque(d, "   After erase element at index 1");
    }

    // 7️⃣ emplace() - construct element in-place at position
    cout << "7) emplace():\n";
    d.emplace(d.begin(), 500);             // insert 500 at beginning
    printDeque(d, "   After emplace(500) at beginning");

    // 8️⃣ emplace_back() - construct element at end
    cout << "8) emplace_back():\n";
    d.emplace_back(800);
    printDeque(d, "   After emplace_back(800)");

    // 9️⃣ emplace_front() - construct element at front
    cout << "9) emplace_front():\n";
    d.emplace_front(300);
    printDeque(d, "   After emplace_front(300)");

    // 🔟 clear() - remove all elements
    cout << "10) clear():\n";
    d.clear();
    printDeque(d, "   After clear()");
    cout << "   d.empty(): " << (d.empty() ? "Yes" : "No") << "\n\n";

    // 1️⃣1️⃣ swap() - swap contents of two deques
    cout << "11) swap():\n";
    deque<int> a = {1, 2, 3};
    deque<int> b = {100, 200};

    printDeque(a, "   Deque a before swap");
    printDeque(b, "   Deque b before swap");

    a.swap(b);   // or swap(a, b);

    printDeque(a, "   Deque a after swap");
    printDeque(b, "   Deque b after swap");

    return 0;
}

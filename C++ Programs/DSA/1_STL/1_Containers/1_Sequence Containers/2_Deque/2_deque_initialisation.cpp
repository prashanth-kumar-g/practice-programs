// Program 02: Deque Initialization Methods
// Demonstrates commonly used ways to create and initialize a deque.

#include <iostream>
#include <deque>
#include <list>

using namespace std;

void printDeque(deque<int> &d, const string &name)
{
    cout << name << " (size = " << d.size() << "): ";
    if (d.empty())
        cout << "<empty>";
    else
        for (int x : d)
            cout << x << " ";
    cout << "\n";
}

int main()
{
    // 1️⃣ Empty deque
    deque<int> d1;
    printDeque(d1, "d1 - Empty");

    // 2️⃣ Fixed size (default initialized to 0 for int)
    deque<int> d2(5);
    printDeque(d2, "d2 - Size constructor");

    // 3️⃣ Fixed size with given value
    deque<int> d3(5, 100);
    printDeque(d3, "d3 - Size + Value");

    // 4️⃣ Initializer list (most common)
    deque<int> d4 = {1, 2, 3, 4, 5};
    printDeque(d4, "d4 - Initializer list");

    // 5️⃣ Copy constructor
    deque<int> d5(d4);
    printDeque(d5, "d5 - Copy of d4");

    // 6️⃣ Range constructor (from another deque)
    deque<int> d6(d4.begin() + 1, d4.end() - 1); // copies {2,3,4}
    printDeque(d6, "d6 - Range from d4");

    // 7️⃣ assign() function
    deque<int> d7;
    d7.assign(4, 55); // four elements with value 55
    printDeque(d7, "d7 - Using assign()");

    // 8️⃣ From C-style array (common in old codebases)
    int arr[] = {10, 20, 30};
    deque<int> d8(arr, arr + 3);
    printDeque(d8, "d8 - From C array");

    // 9️⃣ Using push_front() and push_back() to build deque
    deque<int> d9;
    d9.push_back(20);
    d9.push_front(10);
    d9.push_back(30);
    printDeque(d9, "d9 - Using push_front() & push_back()");

    // 🔟 From another container (e.g., std::list)
    list<int> L = {50, 60, 70, 80};
    deque<int> d10(L.begin(), L.end());
    printDeque(d10, "d10 - From list container");

    return 0;
}

// Program 05: Capacity Functions in deque
// Demonstrates size(), empty(), resize(), and shrink_to_fit().

#include <iostream>
#include <deque>
using namespace std;

void printStatus(const deque<int>& d, const string& msg)
{
    cout << msg << "\n";
    cout << "   size()      = " << d.size() << "\n";
    cout << "   max_size   = " << d.max_size() << "\n";
    cout << "   empty()     = " << (d.empty() ? "Yes" : "No") << "\n\n";
}

int main()
{
    deque<int> d;
    printStatus(d, "\nInitial state:");

    // 1️⃣ push_back() increases size
    cout << "Adding elements using push_back():\n";
    for(int i = 1; i <= 5; i++)
        d.push_back(i * 10);
    printStatus(d, "After push_back 5 elements:");

    // 2️⃣ resize() changes size (may increase or decrease)
    cout << "Using resize(3):\n";
    d.resize(3);  // shrinking removes elements
    printStatus(d, "After resize(3):");

    // 3️⃣ shrink_to_fit() request memory reduction
    cout << "Using shrink_to_fit():\n";
    d.shrink_to_fit();
    printStatus(d, "After shrink_to_fit():");

    return 0;
}

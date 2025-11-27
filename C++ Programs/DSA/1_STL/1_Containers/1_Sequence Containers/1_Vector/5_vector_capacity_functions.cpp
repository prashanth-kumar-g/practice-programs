// Program 05: Capacity Functions in vector
// Demonstrates size(), capacity(), empty(), reserve(), resize(), and shrink_to_fit().

#include <iostream>
#include <vector>
using namespace std;

void printStatus(const vector<int>& v, const string& msg)
{
    cout << msg << "\n";
    cout << "   size      = " << v.size() << "\n";
    cout << "   capacity  = " << v.capacity() << "\n";
    cout << "   empty()   = " << (v.empty() ? "Yes" : "No") << "\n\n";
}

int main()
{
    vector<int> v;
    printStatus(v, "\nInitial state:");

    // 1️⃣ push_back() increases size and may increase capacity automatically
    cout << "Adding elements using push_back():\n";
    for(int i = 1; i <= 5; i++)
        v.push_back(i * 10);
    printStatus(v, "After push_back 5 elements:");

    // 2️⃣ reserve() increases capacity without changing size
    cout << "Using reserve(20):\n";
    v.reserve(20);
    printStatus(v, "After reserve(20):");

    // 3️⃣ resize() changes size (may increase or decrease)
    cout << "Using resize(3):\n";
    v.resize(3);  // shrinking removes elements
    printStatus(v, "After resize(3):");

    // 4️⃣ shrink_to_fit() requests capacity reduction
    cout << "Using shrink_to_fit():\n";
    v.shrink_to_fit();
    printStatus(v, "After shrink_to_fit():");

    return 0;
}

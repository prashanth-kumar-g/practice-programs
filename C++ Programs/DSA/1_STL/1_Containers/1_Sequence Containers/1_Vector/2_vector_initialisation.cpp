// Program 02: Vector Initialization Methods
// Demonstrates commonly used ways to create and initialize a vector.

#include <iostream>
#include <vector>
#include <list>

using namespace std;

void printVec(vector<int> &v, const string &name)
{
    cout << name << " (size = " << v.size() << "): ";
    if (v.empty())
        cout << "<empty>";
    else
        for (int x : v)
            cout << x << " ";
    cout << "\n";
}

int main()
{
    // 1️⃣ Empty vector
    vector<int> v1;
    printVec(v1, "v1 - Empty");

    // 2️⃣ Fixed size (default initialized to 0 for int)
    vector<int> v2(5);
    printVec(v2, "v2 - Size constructor");

    // 3️⃣ Fixed size with given value
    vector<int> v3(5, 100);
    printVec(v3, "v3 - Size + Value");

    // 4️⃣ Initializer list (most common)
    vector<int> v4 = {1, 2, 3, 4, 5};
    printVec(v4, "v4 - Initializer list");

    // 5️⃣ Copy constructor
    vector<int> v5(v4);
    printVec(v5, "v5 - Copy of v4");

    // 6️⃣ Range constructor (from another vector)
    vector<int> v6(v4.begin() + 1, v4.end() - 1); // copies {2,3,4}
    printVec(v6, "v6 - Range from v4");

    // 7️⃣ Assign() function
    vector<int> v7;
    v7.assign(4, 55); // four elements with value 55
    printVec(v7, "v7 - Using assign()");

    // 8️⃣ From C-style array (common in old codebases)
    int arr[] = {10, 20, 30};
    vector<int> v8(arr, arr + 3);
    printVec(v8, "v8 - From C array");

    // 9️⃣ Reserve + push_back (used when final size known)
    vector<int> v9;
    v9.reserve(3);  // (or together) vector<int> v9(3);
    v9.push_back(9);
    v9.push_back(8);
    v9.push_back(7);
    printVec(v9, "v9 - Reserve + push_back");

    // 🔟 From another container (e.g., std::list)
    list<int> L = {50, 60, 70, 80};
    vector<int> v10(L.begin(), L.end());
    printVec(v10, "v10 - From list container");

    return 0;
}

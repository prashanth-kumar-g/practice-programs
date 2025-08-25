// program to illustrate the capacity function in vector
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;

    // fill the vector with 10 five times
    v.assign(5, 10);

    cout << "The vector elements are: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    // inserts 15 to the last position
    v.push_back(15);
    int n = v.size();
    cout << "\nThe last element is: " << v[n - 1]; // or v[v.size()-1]

    // removes last element
    v.pop_back();

    // prints the vector
    cout << "\nThe vector elements are: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    // inserts 5 at the beginning
    v.insert(v.begin(), 5);
    cout << "\nThe first element is: " << v[2];

    // removes the first element
    v.erase(v.begin());
    cout << "\nThe first element is: " << v[0];

    // inserts 6 at the position 2
    vector<int>::iterator it;
    it=v.begin();
    it++;
    v.insert(it,6);
    cout << "\nThe 2nd element is: " << v[1];  

    // inserts 7 at the position 3
    vector<int>::iterator it1;
    it1=v.begin();
    v.insert(it1+2,7);  
    cout << "\nThe 3rd element is: " << v[2];  

    // prints the vector
    cout << "\nThe vector elements are: ";
    for (auto i = v.begin(); i !=v.end(); i++)
    {
        cout << *i << " ";
    } 

    // erases the vector
    v.clear();
    cout << "\nVector size after erase(): " << v.size();

    // two vector to perform swap
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    cout << "\n\nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    // Swaps v1 and v2
    v1.swap(v2);
    cout << "\nAfter Swap \nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }

    return 0;
}

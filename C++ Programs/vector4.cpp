// program for vectors and templates example
#include <iostream>
#include <vector>
using namespace std;
template<class T>
void display(vector<T> &v)
{
    for (auto i = v.begin(); i !=v.end(); i++)
    {
        cout << *i << " ";
    }
    cout<<endl;
}
int main()
{
    vector<char> v1; // zero length char vector
    v1.push_back('a');
    v1.push_back('b');
    v1.push_back('c');
    vector<int> v2(3); // 3-element length int vector
    cout<<"Enter the vector v2 elements : ";
    for (int i = 0; i < 3; i++)
    {
        cin >> v2[i];    // v2[i] is valid because of contigious memory allocation
    }
    vector<float> v3(3, 1.608); // 3-element length of float vector with 1.608 as values
    vector<float> v4(v3); // 3-element length of float vector from v3
    cout << "The vector v1 elements are : ";
    display(v1);
    cout << "The vector v2 elements are : ";
    display(v2);
    cout << "The vector v3 elements are : ";
    display(v3);
    cout << "The vector v4 elements are : ";
    display(v4);
}
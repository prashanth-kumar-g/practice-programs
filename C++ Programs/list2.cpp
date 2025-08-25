// program for list example (similar to vectors concept)
#include<iostream>
#include<list>
using namespace std;
template<class T>
void display(list<T> &l)
{
    for (auto i = l.begin(); i !=l.end(); i++)
    {
        cout << *i << " ";
    }
    cout<<endl;
}
int main()
{
    list<char> l1; // zero length char list
    l1.push_back('a');
    l1.push_back('b');
    l1.push_back('c');
    list<int> l2(3); // 3-element length int list
    cout<<"Enter the list l2 elements : ";
    for (auto i = l2.begin(); i!=l2.end(); i++)
    {
        cin >> *i;   // l2[i] is invalid because of non-contigious memory allocation 
    }
    list<float> l3(3, 1.608); // 3-element length of float list with 1.608 as values
    list<float> l4(l3); // 3-element length of float list from l3
    cout << "The list l1 elements are : ";
    display(l1);
    cout << "The list l2 elements are : ";
    display(l2);
    cout << "The list l3 elements are : ";
    display(l3);
    cout << "The list l4 elements are : ";
    display(l4); 
    return 0;
}
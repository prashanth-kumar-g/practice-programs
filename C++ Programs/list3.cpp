// program to illustarte the various operation performed on list
#include <iostream>
#include <list>
using namespace std;
void display(list<int> &l)
{
    list<int>::iterator i;
    for (i = l.begin(); i != l.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}
int main()
{
    list<int> l1, l2(5);
    for (int i = 1; i <= 5; i++)
    {
        l1.push_back(i * 10);
    }
    list<int>::iterator i;
    cout << "Enter list l2 elements : ";
    for (i = l2.begin(); i != l2.end(); i++)
    {
        cin >> *i;
    }

    cout << "\nThe list l1 elements are : ";
    display(l1);
    cout << "The list l2 elements are : ";
    display(l2);

    // pop_back operation
    cout << "\nl1.pop_back : ";
    l1.pop_back();
    display(l1);
    cout << "l2.pop_back : ";
    l2.pop_back();
    display(l2);

    // pop_front operation
    cout << "\nl1.pop_front : ";
    l1.pop_front();
    display(l1);
    cout << "l2.pop_front : ";
    l2.pop_front();
    display(l2);

    // reverse operation
    cout << "\nl1.reverse : ";
    l1.reverse();
    display(l1);
    cout << "l2.reverse : ";
    l2.reverse();
    display(l2);

    // sort operation
    cout << "\nl1.sort : ";
    l1.sort();
    display(l1);
    cout << "l2.sort : ";
    l2.sort();
    display(l2);

    // merge operation
    cout << "\nl1.merge(l2) : ";
    l1.merge(l2);
    display(l1);

    return 0;
}
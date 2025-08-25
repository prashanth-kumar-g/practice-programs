// map operations example
#include <iostream>
#include <map>
#include <string>
using namespace std;
void display(map<string, int> &m)
{
    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }
}
int main()
{
    map<string, int> m;
    string key;
    int value;
    cout << "Enter the map key and values" << endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> key >> value;
        m[key] = value;
    }
    cout << "Map elements are" << endl;
    display(m);
    m.insert({{"four", 4}});
    m.insert({{"five", 5}, {"six", 6}});
    cout << "Map elements after inserting" << endl;
    display(m);
    m.erase("six");
    cout << "Map elements after erasing" << endl;
    display(m);
    return 0;
}
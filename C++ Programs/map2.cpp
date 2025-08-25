// passing map as a function and capacity functions
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
    map<string, int> m1;
    string key;
    int value;
    cout << "Enter the map key and values" << endl;  // taking input from user
    for (int i = 0; i < 3; i++)
    {
        cin >> key >> value;
        m1[key] = value;
    }
    cout << "Map 1 elements are"<<endl;
    display(m1);
    map<string, int> m2(m1); // create map 2 with help of map 1
    cout << "Map 2 elements are"<<endl;
    display(m2);
    cout<<"size of map 1 : "<<m1.size();
    cout<<"\nsize of map 2 : "<<m2.size();
    cout<<"\nmax size of map 1 : "<<m1.max_size();
    cout<<"\nmax size of map 2 : "<<m2.max_size();
    cout<<"\nmap 1 is empty or not : "<<m1.empty();
    cout<<"\nmap 2 is empty or not : "<<m1.empty();
    return 0;
}
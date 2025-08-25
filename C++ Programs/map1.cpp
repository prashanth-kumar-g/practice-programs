// simple program for map
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string, int> m;
    m["Raj"] = 76;
    m["Shraddha"] = 91;
    m["Suresh"] = 84;
    map<string, int>::iterator i; // can also use auto instead of creating a iterator variable
    for (i = m.begin(); i != m.end(); i++)
    {
        cout << (*i).first << " " << (*i).second << endl; // or cout<< i-> first <<" "<< i->second <<endl;
    }
    map<string, int> m1 = {{"one", 1}, {"two", 2}}; // map initialisation
    cout << m1["one"] << endl;                      // access value using reference operator
    cout << m1.at("two");                           // access value using at() function
    return 0;
}
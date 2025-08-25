// program for string using string class
#include<iostream>
#include<string>
using namespace std;
void display1(string str)
{
    cout<<"\nThe String is : "<<str;
}
void display2(char *p)  // this is possible means, we can use the string class in c++ same way as character array in c
{
    cout<<"\nThe String is : ";
    while(*p!=0)
    {
        cout<<*p;
        p++;
    }
}
int main()
{
    string str;
    cout<<"Enter the string : ";   
    getline(cin,str);
    cout<<"The String is : "<<str;   // method 1
    cout<<"\nThe String is : ";      // method 2
    for(int i=0;i<str.length();i++) 
    { 
        cout<<str[i];   // this is possible means, we can use the string class in c++ same way as character array in c
    }
    display1(str);       // method 3
    display2(&str[0]);   // method 4
    return 0;
}
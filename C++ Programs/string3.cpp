// program for insert substring in a given string
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str,sub_str;
    int pos;
    cout<<"Enter a String : ";
    getline(cin,str);
    cout<<"Enter a Substring to be inserted : ";
    getline(cin,sub_str);
    cout<<"Enter the position : ";
    cin>>pos;
    auto j=str.begin();
    j=j+pos;
    for(int i=0;i<sub_str.length();i++)
    {
        str.insert(j,sub_str[i]);
        j++;
    }
    cout<<"String after inserting Substring : "<<str;
    return 0;
} // other programs like replacing, extracting substring and pattrern searching etc can be written same here as in turbo c++
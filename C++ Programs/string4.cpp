// program to check if the string is palindrome or not
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str1,str2;
    cout<<"Enter a String : ";
    getline(cin,str1);
    str2=str1;
    int n=str2.length();
    for(int i=0;i<n/2;i++)
    {
        swap(str2[i],str2[n-i-1]);  // swap() function is used her, many other functions in STL can be used here
    }
    if(str1==str2)
    {
        cout<<str1<<" is a palindrome";
    }
    else
    {
        cout<<str1<<" is not a palindrome";
    }
    return 0;
}
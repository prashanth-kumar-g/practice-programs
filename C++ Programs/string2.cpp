// program for string using string class and various operations
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str1,str2,str3;
    cout<<"Enter the string 1 : ";
    getline(cin,str1);
    cout<<"Enter the string 2 : ";
    getline(cin,str2);
    cout<<"String 1 is : "<<str1;
    cout<<"\nString 2 is : "<<str2;
    cout<<"\nLength of String 1 : "<<str1.length();
    str3=str1;
    cout<<"\nString 1 Copied to String 3 : "<<str3;
    str3=str1+str2;
    cout<<"\nConcatenation of String 1 and String 2 : "<<str3;    
    if(str1==str2)
    {
        cout<<"\nString 1 and String 2 are same";
    }
    else
    {
        cout<<"\nString 1 and String 2 are not same";
    }
    cout<<"\nUpperCase of String 1 : ";
    char ch;
    for(int i=0;i<str1.length();i++)
    {
        ch=toupper(str1[i]);
        cout<<ch;
    }
    cout<<"\nLowerCase of String 1 : ";
    for(int i=0;i<str1.length();i++)
    {
        ch=tolower(str1[i]);
        cout<<ch;
    }
    cout<<"\nReverse of String 1 : ";
    int n=str1.length();
    for(int i=0;i<n/2;i++)
    {
        swap(str1[i],str1[n-i-1]);
    }
    cout<<str1;
    return 0;
}
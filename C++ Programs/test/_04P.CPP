#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"\n Enter a number : ";
    cin>>n;

    int m = n;
    int rem, rev = 0;

    while(m != 0)
    {
        rem = m % 10;
        rev = rev * 10 + rem;
        m = m / 10;
    }

    if(n == rev)
    {
        cout<<"\n "<<n<<" is a palindrome number \n"<<endl;
    }
    else
    {
        cout<<"\n "<<n<<" is not a palindrome number \n"<<endl;
    }

    return 0;
}
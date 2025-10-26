#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"\n Enter the limit : ";
    cin>>n;

    cout<<"\n The prime numbers are :  ";

    for(int i = 2; i <= n; i++)
    {
        bool isPrime = true;

        for(int j = 2; j*j <= i; j++)
        {
            if(i % j == 0)
            {
                isPrime = false;
            }
        }

        if(isPrime)
        {
            cout<<i<<"  ";
        }
    }

    cout<<"\n"<<endl;

    return 0;
}
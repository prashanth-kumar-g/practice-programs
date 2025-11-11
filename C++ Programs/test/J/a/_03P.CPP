#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"\n Enter the number of terms : ";
    cin>>n;

    cout<<"\n The prime numbers are :  ";
    int count = 0;

    for(int i = 2; count < n; i++)
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
            count++;
        }
    }

    cout<<"\n"<<endl;

    return 0;
}
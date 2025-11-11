#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"\n Enter the number of terms : ";
    cin>>n;

    int f1 = 0, f2 = 1, fn;
    cout<<"\n The fibonacci series is :  ";

    for(int i = 1; i <= n; i++)
    {
        cout<<f1<<"  ";
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }

    cout<<"\n"<<endl;

    return 0;
}
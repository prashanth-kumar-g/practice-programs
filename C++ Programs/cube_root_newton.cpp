#include<iostream>
#include<iomanip>
using namespace std;

double cubeRootNetwonMethod(double n, double eps = 1e-10)
{
    if(n < 0) n = -n;

    if(n == 0 || n ==1) return n;

    double x = n / 3.0;     // initial guess

    while(1)
    {
        double root = 1 / 3.0 * (2 * x + n / (x * x));    // newton-raphson method

        double diff = (root > x) ? (root - x) : (x - root);

        if(diff < eps)
            return root;

        x = root;
    }
} 

int main()
{
    double number; 
    cout<<"\n Enter a number : ";
    cin>>number;

    double result = cubeRootNetwonMethod(number);
    long long intPart = result;

    if(number < 0)
        if(result - intPart > 1e-10)
            cout<<noshowpoint<<setprecision(11)<<" \n Cube Root of "<<number<<" = "<<fixed<<setprecision(10)<<-result<<"\n"<<endl;
        else
            cout<<noshowpoint<<setprecision(11)<<" \n Cube Root of "<<number<<" = "<<-intPart<<"\n"<<endl;
    else
        if(result - intPart > 1e-10)
            cout<<noshowpoint<<setprecision(11)<<" \n Cube Root of "<<number<<" = "<<fixed<<setprecision(10)<<result<<"\n"<<endl;
        else
            cout<<noshowpoint<<setprecision(11)<<" \n Cube Root of "<<number<<" = "<<intPart<<"\n"<<endl;

    return 0;
}
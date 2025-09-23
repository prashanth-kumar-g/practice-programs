#include<iostream>
#include<iomanip>
using namespace std;

const double E = 2.7182818285;
const double PI = 3.1415926536;

double expPower(double x, double eps = 1e-10)
{
    double term = 1.0, sum = 1.0;
    int f = 1;

    while(term > eps)               // e^x = 1 + x/1! + (x^2)/2! + (x^3)/3! + (x^4)/4! + ...
    {
        term = term * x / f;        // next term = previous term * y / f
        sum = sum + term;
        f++;
    }

    return sum;
}

double logBaseENewtonMethod(double n, double eps = 1e-10)
{
    if(n < 0) n = -n;           // just for handling, find partial value, fully value find in main (complex value)

    if(n == 1) return 0.0;      // actual result

    if(n == 0) return 0.0;      // just for handling and time complexity, return quickly, managed in main, not acual value

    int k = 0;         // ln(n) = ln(m.E^k) = ln(m) + k, where 1 <= m < E
    while(n >= E)      // scale down if n is large
    {
        n = n / E;     // e.g., { n = 11, k = 0 } -> { n = 4.4066.., k = 2 } -> { n = 1.4886.., k = 3 }
        k++;
    }
    while(n < 1)        // scale up if n is large
    {
        n = n * E;     // e.g., { n = 0.011, k = 0 } -> { n = 0.0299.., k = -1 } -> { n = 0.0812.., k = -2 } -> { n = 0.2209.., k = -3} -> { n = 0.6005, k = -4 } -> { n = 1.6325.., k = -5 }
        k--;
    }

    double x = n / E;     // initial guess ( 1 <= n < E, final answer = ln(n) + k )

    while(1)
    {
        double x_new = x + ((n / expPower(x)) - 1);   // newton-raphson method - X(k+1) = X(k) + (( n / e^(X(k)) ) - 1)

        double diff = (x_new > x) ? (x_new - x) : (x - x_new);

        if(diff < eps)
            return x_new + k;       // e.g., return ln(1.4886..) + k, where k = 3 for n = 11 or return ln(1.6325..) + k, where k = -5 for n = 0.011

        x = x_new;
    }
}

double logBaseNNewtonMethod(double b, double n)
{
    if(b == 1 || b == 0 || b == -1)
        return 0.0;     // just for handling and time complexity, return quickly, it will be handled in main, not acual value
    else if(b < -1)
        return logBaseENewtonMethod(n);     // partial calculation, full calculation in main (complex value)
    else
        return logBaseENewtonMethod(n) / logBaseENewtonMethod(b);      // log base b of n = ln(n) / ln(b)
}

int main()
{
    double base, number; 
    cout<<"\n Enter the log base : ";
    cin>>base;
    cout<<"\n Enter a number : ";
    cin>>number;

    double result = logBaseNNewtonMethod(base, number);
    long long intPart = result;

    if(number < 0)
        if(base == 1 || base == 0 || base == -1)
            cout<<"\n log base "<<base<<" of "<<number<<" = "<<"Not Defined"<<"\n"<<endl;
        else if(base < -1)
            cout<<noshowpoint<<setprecision(11)<<"\n log base "<<base<<" of "<<number<<" = "<<fixed<<setprecision(10)<<result<<" / ("<<logBaseENewtonMethod(base)<<" + "<<PI<<"i)\n"<<endl;
        else if(result - intPart > 1e-10)
            cout<<noshowpoint<<setprecision(11)<<"\n log base "<<base<<" of "<<number<<" = "<<fixed<<setprecision(10)<<result<<" + "<<PI<<"i\n"<<endl;
        else
            cout<<noshowpoint<<setprecision(11)<<"\n log base "<<base<<" of "<<number<<" = "<<intPart<<" + "<<PI<<"i\n"<<endl;
    else if(number == 0)
        if(base == 1 || base == 0 || base == -1)
            cout<<"\n log base "<<base<<" of "<<number<<" = "<<"Not Defined"<<"\n"<<endl;
        else
            cout<<"\n log base "<<base<<" of "<<number<<" = "<<"-∞"<<"\n"<<endl;
    else if(number == 1)
        if(base == 1 || base == 0 || base == -1)
            cout<<"\n log base "<<base<<" of "<<number<<" = "<<"Not Defined"<<"\n"<<endl;
        else
            cout<<"\n log base "<<base<<" of "<<number<<" = "<<0<<"\n"<<endl;
    else
        if(base == 1 || base == 0 || base == -1)
            cout<<"\n log base "<<base<<" of "<<number<<" = "<<"Not Defined"<<"\n"<<endl;
        else if(base < -1)
            cout<<noshowpoint<<setprecision(11)<<"\n log base "<<base<<" of "<<number<<" = "<<fixed<<setprecision(10)<<result<<" / ("<<logBaseENewtonMethod(base)<<" + "<<PI<<"i)\n"<<endl;
        else if(result - intPart > 1e-10)
            cout<<noshowpoint<<setprecision(11)<<"\n log base "<<base<<" of "<<number<<" = "<<fixed<<setprecision(10)<<result<<"\n"<<endl;
        else
            cout<<noshowpoint<<setprecision(11)<<"\n log base "<<base<<" of "<<number<<" = "<<intPart<<"\n"<<endl;

    return 0;
}
#include<iostream>
#include<iomanip>
using namespace std;

const double LN2 = 0.6931471806; 
const double PI = 3.1415926536;

double twoPower(double x, double eps = 1e-10)
{
    double term = 1.0, sum = 1.0, y = x * LN2;
    int f = 1;

    while(term > eps)               // e^x = 1 + x/1! + (x^2)/2! + (x^3)/3! + (x^4)/4! + ...
    {                               // 2^x = e^(x.LN2) = 1 + (x.LN2)/1! + (x.LN2)^2/2! + + (x.LN2)^3/3! + + (x.LN2)^4/4! + ... 
        term = term * y / f;        // next term = previous term * y / f
        sum = sum + term;
        f++;
    }

    return sum;
}

double logBase2NewtonMethod(double n, double eps = 1e-10)
{
    if(n < 0) n = -n;           // just for handling, find partial value, fully value find in main (complex value)

    if(n == 1) return 0.0;      // actual result

    if(n == 0) return 0.0;      // just for handling and time complexity, return quickly, managed in main, not acual value

    int k = 0;         // log₂(n) = log₂(m.2^k) = log₂(m) + k, where 1 <= m < 2
    while(n >= 2)      // scale down if n is large
    {
        n = n / 2;     // e.g., { n = 11, k = 0 } -> { n = 5.5, k = 1 } -> { n = 2.75, k = 2 } -> { n = 1.375, k = 3} 
        k++;
    }
    while(n < 1)        // scale up if n is large
    {
        n = n * 2;     // e.g., { n = 0.011, k = 0 } -> { n = 0.022, k = -1 } -> { n = 0.044, k = -2 } -> { n = 0.088, k = -3} -> { n = 0.176, k = -4 } -> { n = 0.352, k = -5 } -> { n = 0.704, k = -6 } -> { n = 1.408, k = -7 }
        k--;
    }

    double x = n / 2.0;     // initial guess ( 1 <= n < 2, final answer = log₂(n) + k )

    while(1)
    {
        double x_new = x + ((n / twoPower(x)) - 1) / LN2;   // newton-raphson method - X(k+1) = X(k) + ( (( n / 2^(X(k)) ) - 1) / LN2 )

        double diff = (x_new > x) ? (x_new - x) : (x - x_new);

        if(diff < eps)
            return x_new + k;       // e.g., return log₂(1.375) + k, where k = 3 for n = 11 (or) return log₂(1.408) + k, where k = -7 for n = 0.011

        x = x_new;
    }

} 

int main()
{
    double number; 
    cout<<"\n Enter a number : ";
    cin>>number;

    double result = logBase2NewtonMethod(number);
    long long intPart = result;

    if(number < 0)
        if(result - intPart > 1e-10)
            cout<<noshowpoint<<setprecision(11)<<"\n log₂ of "<<number<<" = "<<fixed<<setprecision(10)<<result<<" + "<<(PI / LN2)<<"i\n"<<endl;
        else
            cout<<noshowpoint<<setprecision(11)<<"\n log₂ of "<<number<<" = "<<intPart<<" + "<<(PI / LN2)<<"i\n"<<endl;
    else if(number == 0)
            cout<<"\n log₂ of "<<number<<" = "<<"-∞"<<"\n"<<endl;
    else
        if(result - intPart > 1e-10)
            cout<<noshowpoint<<setprecision(11)<<"\n log₂ of "<<number<<" = "<<fixed<<setprecision(10)<<result<<"\n"<<endl;
        else
            cout<<noshowpoint<<setprecision(11)<<"\n log₂ of "<<number<<" = "<<intPart<<"\n"<<endl;

    return 0;
}
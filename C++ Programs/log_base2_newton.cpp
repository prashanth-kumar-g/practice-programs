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

double logBase10NetwonMethod(double n, double eps = 1e-10)
{
    if(n < 0) n = -n;

    if(n == 1) return 0.0;      // actual result

    if(n == 0) return 0.0;      // just for continuity

    int k = 0;          // log2(n) = log2(m.10^k) = log2(m) + k, where 1 <= m < 10
    while(n >= 10)      // scale down if n is large
    {
        n = n / 10;     // e.g., { n = 3101, k = 0 } -> { n = 310.1, k = 1 } -> { n = 31.01, k = 2 } -> { n = 3.101, k = 3} 
        k++;
    }
    while(n < 1)        // scale up if n is large
    {
        n = n * 10;     // e.g., { n = 0.003101, k = 0 } -> { n = 0.03101, k = -1 } -> { n = 0.3101, k = -2 } -> { n = 3.101, k = -3}
        k--;
    }

    double x = n / 10.0;     // initial guess ( 1 <= n < 10, final answer = log(n) + k )

    while(1)
    {
        double x_new = x + ((n / twoPower(x)) - 1) / LN2;   // newton-raphson method - X(k+1) = X(k) + ( (( n / 10^(X(k)) ) - 1) / LN2 )

        double diff = (x_new > x) ? (x_new - x) : (x - x_new);

        if(diff < eps)
            return x_new + k;       // e.g., return log2(3.101) + k, where k = 3 for n = 3101 or k = -3 for n = 0.003101

        x = x_new;
    }

} 

int main()
{
    double number; 
    cout<<"\n Enter a number : ";
    cin>>number;

    double result = logBase10NetwonMethod(number);
    long long intPart = result;

    if(number < 0)
        if(result - intPart > 1e-10)
            cout<<noshowpoint<<setprecision(11)<<" \n log2 of "<<number<<" = "<<fixed<<setprecision(10)<<result<<" + "<<(PI / LN2)<<"i\n"<<endl;
        else
            cout<<noshowpoint<<setprecision(11)<<" \n log2 of "<<number<<" = "<<intPart<<" + "<<(PI / LN2)<<"i\n"<<endl;
    else if(number == 0)
            cout<<" \n log2 of "<<number<<" = "<<u8"-∞"<<"\n"<<endl;
    else
        if(result - intPart > 1e-10)
            cout<<noshowpoint<<setprecision(11)<<" \n log2 of "<<number<<" = "<<fixed<<setprecision(10)<<result<<"\n"<<endl;
        else
            cout<<noshowpoint<<setprecision(11)<<" \n log2 of "<<number<<" = "<<intPart<<"\n"<<endl;

    return 0;
}
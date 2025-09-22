#include<iostream>
#include<iomanip>
using namespace std;

const double ln10 = 2.3025850929; 

double tenPower(double x, double eps = 1e-10)
{
    double term = 1.0, sum = 1.0, y = x * ln10;
    int f = 1;

    while(term > eps)               // e^x = 1 + x/1! + (x^2)/2! + (x^3)/3! + (x^4)/4! + ...
    {                               // 10^x = e^(x.ln10) = 1 + (x.ln10)/1! + (x.ln10)^2/2! + + (x.ln10)^3/3! + + (x.ln10)^4/4! + ... 
        term = term * y / f;        // next term = previous term * y / f
        sum = sum + term;
        f++;
    }

    return sum;
}

double logBase10NetwonMethod(double n, double eps = 1e-10)
{
    if(n <= 0) return -1;

    if(n == 1) return 0;

    double x = n / 10.0;     // initial guess

    while(1)
    {
        double log = x + ((n / tenPower(x)) - 1) / ln10;   // newton-raphson method - X(k+1) = X(k) + ( (( n / 10^(X(k)) ) - 1) / ln10 )

        double diff = (log > x) ? (log - x) : (x - log);

        if(diff < eps)
            return log;

        x = log;
    }
} 

int main()
{
    double number; 
    cout<<"\n Enter a number : ";
    cin>>number;

    double result = logBase10NetwonMethod(number);
    long long intPart = result;

    if(result == -1)
            cout<<" Not Defined \n"<<endl;
    else
        if(result - intPart > 1e-10)
            cout<<noshowpoint<<setprecision(11)<<" \n Logarithm(base10) of "<<number<<" = "<<fixed<<setprecision(10)<<result<<"\n"<<endl;
        else
            cout<<noshowpoint<<setprecision(11)<<" \n Logarithm(base10) of "<<number<<" = "<<intPart<<"\n"<<endl;

    return 0;
}
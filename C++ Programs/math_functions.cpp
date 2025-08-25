// program to illustrate important mathematical functions in c++
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double x = 2.3;
	cout << "Sine value of x=2.3 : " << sin(x) << endl;
	cout << "Cosine value of x=2.3 : " << cos(x) << endl;
	cout << "Tangent value of x=2.3 : " << tan(x) << endl;

	double y = 0.25; 
	cout << "Square root value of y=0.25 : " << sqrt(y) << endl;
    cout << "Cube root value of y=0.25 : " << cbrt(y) << endl;
    cout << "Power value: x^y = (2.3^0.25) : " << pow(2.3,0.25) << endl;
	x = 3.0; y = 4.0;
	cout << "Hypotenuse having other two sides as x=3.0 and"<< " y=4.0 : " << hypot(x, y) << endl;

    int z = -10;
	cout << "Absolute value of z=-10 : " << abs(z) << endl;
    x = -4.57;
	cout << "Absolute value of x=-4.57 is : " << fabs(x) << endl;
	x = 4.56;
	cout << "Floor value of x=4.56 is : " << floor(x) << endl;
	cout << "Ceil value of x=4.56 : " << ceil(x) << endl;
    cout << "Round value of x=4.56 : " << round(x) << endl;
    cout << "Trunc value of x=4.56 : " << trunc(x) << endl;

	y = 100.0;
	cout << "Log value of y=100.0 is : " << log(y) << endl;
    cout << "Log2 value of y=100.0 is : " << log2(y) << endl;
    cout << "Log10 value of y=100.0 is : " << log10(y) << endl;

    x=57.5; y=63.6;
    cout<< "Max of x=57 and y=63 is : "<<max(x,y)<<endl;
    cout<< "Min of x=57 and y=63 is : "<<min(x,y)<<endl;
	return 0;
}
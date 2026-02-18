#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

bool isSymbol(const string &s)
{
    return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^");
}

bool isNumber(const string &s)
{
    for (char ch : s)
        if (!isdigit(ch))
            return false;
    return true;
}

int main()
{
    vector<string> arr = {"a","b","c","e","f","10","+","g","7","h","2","8"};

    long long result = 0;
    string currentNumber = "";
    char currentOp = '+';   // default operator

    for (int i = 0; i < arr.size(); i++)
    {
        if (isSymbol(arr[i]))
        {
            if (!currentNumber.empty())
            {
                long long num = stoll(currentNumber);

                // Apply previous operator
                if (currentOp == '+') result += num;
                else if (currentOp == '-') result -= num;
                else if (currentOp == '*') result *= num;
                else if (currentOp == '/') result /= num;
                else if (currentOp == '^') result = pow(result, num);

                currentNumber = "";
            }
            currentOp = arr[i][0]; // update operator
        }
        else if (isNumber(arr[i]))
        {
            // concatenate digits
            currentNumber += arr[i];
        }
        // ignore alphabets
    }

    // Apply last number
    if (!currentNumber.empty())
    {
        long long num = stoll(currentNumber);
        if (currentOp == '+') result += num;
        else if (currentOp == '-') result -= num;
        else if (currentOp == '*') result *= num;
        else if (currentOp == '/') result /= num;
        else if (currentOp == '^') result = pow(result, num);
    }

    cout << "Final Result: " << result << endl;

    return 0;
}
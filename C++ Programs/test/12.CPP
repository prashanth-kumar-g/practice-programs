// passing array into function using pointers
#include <iostream>

int arrsum(int *p, int n)
{
    int i, sum = 0;
    for (i = 1; i <= n; i++)
    {
        sum = sum + p[i]; // *(p+i) = p[i]
    } // *p = p[0]
    return (sum);
}
int main()
{
    int n, i, a[10]; // p+i = &p[i]
    clrscr();        // p = &p[0]
    cout << "\nEnter the size : ";
    cin >> n;
    cout << "Enter the elements : ";
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << "\nSum of elements = " << arrsum(a, n); // &a[i] = a+i
    return 0;                                       // &a[0] = a
}

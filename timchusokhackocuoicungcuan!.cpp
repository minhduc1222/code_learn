#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
        return n * factorial(n - 1);
}

int lastDigitDiffZero(int n)
{
    double a = factorial(n);
    while (a != 0 && a % 10 == 0)
    {
        a /= 10;
    }
    return a % 10;
}
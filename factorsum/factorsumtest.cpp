#include <iostream>
#include <math.h>
using namespace std;

int solve(int n) {
    int sum = 0;
    // Handle smallest prime factor 2
    while (n % 2 == 0) {
        sum += 2;
        n /= 2;
    }
    // Handle odd factors from 3 onwards
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            sum += i;
            n /= i;
        }
    }
    // If n is a prime number greater than 2
    if (n > 2) {
        sum += n;
    }
    return sum;
}  

bool isprime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i <= n/2; i++){
        if (n% i == 0){
            return false;
        }
    }
    return true;
}

int factorSum(int n)
{
    while (!isprime(n)){
        n = solve(n);
    }
    return n;
}

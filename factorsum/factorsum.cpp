#include <iostream>
using namespace std;

int solve(int n)
{
    int i = 2, sum = 0;
    while (n > 1) {
        while (n % i == 0) {
            n /= i;
            sum += i;
        }
        i++;
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

int main() {
    int number = 100;  // Example number to test
    cout << "Final Prime Sum of Factors for " << number << " is: " << factorSum(number) << endl;
    return 0;
}
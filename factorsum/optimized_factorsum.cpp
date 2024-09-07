#include <iostream>
#include <cmath>
using namespace std;

// Optimized function to find the sum of prime factors of a number
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

// Optimized function to check if a number is prime
bool isprime(int n) {
    if (n <= 1) return false;  // 0 and 1 are not prime numbers
    if (n <= 3) return true;   // 2 and 3 are prime numbers
    if (n % 2 == 0 || n % 3 == 0) return false;  // Exclude multiples of 2 and 3

    for (int i = 5; i <= sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Function to repeatedly find the sum of prime factors until the number itself is prime
int factorSum(int n) {
    while (!isprime(n)) {  // While n is not a prime
        n = solve(n);  // Replace n with the sum of its prime factors
    }
    return n;  // Return the prime number
}

int main() {
    int number = 100;  // Example number to test
    cout << "Final Prime Sum of Factors for " << number << " is: " << factorSum(number) << endl;
    return 0;
}

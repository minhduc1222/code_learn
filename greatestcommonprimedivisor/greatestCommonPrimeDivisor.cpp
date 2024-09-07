#include <iostream>
#include <cmath>  // Use <cmath> for sqrt in C++
using namespace std;

// Function to check if a number is prime
bool isprime(int n) {
    if (n <= 1) return false;  // 0, 1 are not prime
    for (int i = 2; i <= sqrt(n); i++) {  // Fixed the loop to use <= sqrt(n)
        if (n % i == 0) return false;
    }
    return true;
}

// Function to find the greatest common prime divisor
int greatestCommonPrimeDivisor(int a, int b) {
    int i = 2;  // Start with 2 as the smallest prime number
    int gcpd = -1;  // Initialize to -1 to handle cases where no common prime divisor is found

    while (i <= min(a, b)) {  // Corrected the loop condition
        if (isprime(i) && (a % i == 0) && (b % i == 0)) {  // Check for prime and common divisor
            gcpd = i;  // Update GCPD if a prime common divisor is found
        }
        i++;
    }

    return gcpd;  // Return the greatest common prime divisor
}

int main() {
    int a = 12, b = 13;  // Correct initialization of a and b
    cout << "Greatest common prime divisor is: " << greatestCommonPrimeDivisor(a, b) << endl;  // Call the function and print the result
    return 0;
}

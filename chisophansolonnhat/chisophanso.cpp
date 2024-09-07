#include <iostream>
#include <vector>  // Include vector header for std::vector
using namespace std;

int maxFraction(vector<int> numerators, vector<int> denominators)
{
    int max_index = 0;  // Start with the first fraction as the maximum
    for (int i = 1; i < numerators.size(); i++) {  // Start from the second element
        // Compare fractions: a/b > c/d if and only if a*d > c*b
        if (numerators[max_index] * denominators[i] < numerators[i] * denominators[max_index]) {
            max_index = i;  // Update max_index if a larger fraction is found
        }
    }
    return max_index;
}

int main() {
    vector<int> numerators = {5, 7, 7};  // Example numerators
    vector<int> denominators = {4, 8, 2};  // Example denominators

    int index = maxFraction(numerators, denominators);  // Find the index of the maximum fraction
    cout << "Index of the maximum fraction is: " << index << endl;  // Output the result
    return 0;
}

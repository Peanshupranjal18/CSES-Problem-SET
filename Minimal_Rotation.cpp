// The idea is to uses Booth’s algorithm, which is a well-known algorithm for this problem. The main idea of Booth’s algorithm is to construct a failure function (similar to the one used in the KMP pattern matching algorithm) for the given string concatenated with itself. This failure function is used to efficiently compare prefixes of the string to find the smallest rotation.

// Let’s break our idea in some steps:

// Concatenate the string to itself: This allows us to easily handle the wrap-around nature of rotations without having to use modular arithmetic.
// Initialize the failure function and the minimum rotation index: The failure function f is an array that stores the length of the longest proper suffix of the substring S[0..j] which is also a proper prefix of S. The minimum rotation index k keeps track of the starting index of the smallest rotation found so far.
// Iterate over the concatenated string: For each character S[j] in the string, we compare it with the character at the corresponding position in the current smallest rotation. If S[j] is smaller, we update the minimum rotation index k.
// Update the failure function: The failure function is updated based on whether S[j] is equal to S[k + f[j – k – 1] + 1] . If they are equal, f[j – k] is set to f[j – k – 1] + 1. Otherwise, f[j – k] is set to -1.
// Return the minimum rotation index: After iterating over the entire string, the minimum rotation index k gives the starting index of the lexicographically smallest rotation.

#include <bits/stdc++.h>
using namespace std;

// Function to find the lexicographically minimal rotation
// of a string
int findMinRotation(string s)
{
    // Concatenate string to itself to avoid modular
    // arithmetic
    s += s;

    // Initialize failure function
    vector<int> failureFunc(s.size(), -1);

    // Initialize least rotation of string found so far
    int minRotationIdx = 0;

    // Iterate over the concatenated string
    for (int currentIdx = 1; currentIdx < s.size();
         ++currentIdx)
    {
        char currentChar = s[currentIdx];
        int failureIdx = failureFunc[currentIdx - minRotationIdx - 1];

        // Find the failure function value
        while (
            failureIdx != -1 && currentChar != s[minRotationIdx + failureIdx + 1])
        {
            if (currentChar < s[minRotationIdx + failureIdx + 1])
            {
                minRotationIdx = currentIdx - failureIdx - 1;
            }
            failureIdx = failureFunc[failureIdx];
        }

        // Update the failure function and the minimum
        // rotation index
        if (currentChar != s[minRotationIdx + failureIdx + 1])
        {
            if (currentChar < s[minRotationIdx])
            {
                minRotationIdx = currentIdx;
            }
            failureFunc[currentIdx - minRotationIdx] = -1;
        }
        else
        {
            failureFunc[currentIdx - minRotationIdx] = failureIdx + 1;
        }
    }

    // Return the index of the lexicographically minimal
    // rotation
    return minRotationIdx;
}

int main()
{
    // input string
    string s;
    cin >> s;

    // Find the lexicographically minimal rotation
    int minRotationIdx = findMinRotation(s);

    // Print the lexicographically minimal rotation
    cout << s.substr(minRotationIdx) + s.substr(0, minRotationIdx)
         << endl;

    return 0;
}

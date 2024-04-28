// The idea is to use Manacher’s algorithm, which is a linear time complexity algorithm for finding the longest palindromic substring in a given string.

// Lets break down the intuition into some steps:

// We’ll use two arrays, oddLength[] and evenLength[], to store the lengths of the longest odd-length and even-length palindromic substrings centered at each index of the input string.
// Odd-Length Palindromes: First calculates the longest odd-length palindromic substring centered at each index. It uses a variable length to keep track of the current length of the palindrome. It starts from the center and expands in both directions (left and right) until it finds a mismatch or reaches the boundary of the string. The left and right variables are used to keep track of the boundaries of the current longest palindrome.
// Even-Length Palindromes: The process is repeated for even-length palindromes. The only difference is that the initial length is set to 0 and the expansion starts from one position to the left of the center.
// Finding the Longest Palindrome: After the lengths of all palindromic substrings are calculated, iterates over the oddLength and evenLength arrays to find the maximum length and the center of the longest palindromic substring.
// Finally, the longest palindromic substring is extracted from the input string using the substr function and returned.

#include <iostream>
#include <string>

using namespace std;

// Arrays to store the lengths of the longest palindromic
// substrings centered at each index
int oddLength[1000005], evenLength[1000005];

// Function to find the longest palindromic substring
string solve(string &s, int n)
{

    // Find the lengths of the longest odd-length
    // palindromic substrings centered at each index
    for (int i = 0, left = 0, right = -1; i < n; i++)
    {

        // Initialize the length as 1 if the current index
        // is beyond the right boundary
        int length = (i > right)
                         ? 1
                         : min(oddLength[left + right - i],
                               right - i + 1);

        // Expand around the center to find the longest
        // palindrome
        while (0 <= i - length && i + length < n && s[i - length] == s[i + length])
        {
            length++;
        }

        // Update the length of the longest odd-length
        // palindrome centered at index i
        oddLength[i] = length--;

        // Update the boundaries of the current palindrome
        if (i + length > right)
        {
            left = i - length;
            right = i + length;
        }
    }

    // Find the lengths of the longest even-length
    // palindromic substrings centered at each index
    for (int i = 0, left = 0, right = -1; i < n; i++)
    {

        // Initialize the length as 0 if the current index
        // is beyond the right boundary
        int length = (i > right)
                         ? 0
                         : min(evenLength[left + right - i + 1],
                               right - i + 1);

        // Expand around the center to find the longest
        // palindrome
        while (0 <= i - length - 1 && i + length < n && s[i - length - 1] == s[i + length])
        {
            length++;
        }

        // Update the length of the longest even-length
        // palindrome centered at index i
        evenLength[i] = length--;

        // Update the boundaries of the current palindrome
        if (i + length > right)
        {
            left = i - length - 1;
            right = i + length;
        }
    }

    // Find the longest palindromic substring
    int maxLength = 0, center = -1;
    for (int i = 0; i < n; i++)
    {

        // Update the maxLength and center if a longer
        // palindrome is found
        if (oddLength[i] * 2 - 1 > maxLength)
        {
            maxLength = oddLength[i] * 2 - 1;
            center = i;
        }
        if (evenLength[i] * 2 > maxLength)
        {
            maxLength = evenLength[i] * 2;
            center = i;
        }
    }

    // Return the longest palindromic substring
    if (maxLength % 2 == 1)
        return s.substr(center - maxLength / 2, maxLength);
    return s.substr(center - maxLength / 2, maxLength);
}

// Main function
int main()
{

    // Input string
    string s;
    cin >> s;
    int n = s.size();

    // Call the solve function and print the result
    cout << solve(s, n);

    return 0;
}

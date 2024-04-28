// The solution is based on two main concepts: Suffix Arrays and Longest Common Prefix (LCP) Arrays.

// Suffix Arrays: A suffix array is a sorted array of all suffixes of a given string. The suffixes are sorted in lexicographical order. The purpose of creating a suffix array is to sort all suffixes so that we can search for patterns (in this case, repeating substrings) in the sorted list of suffixes.

// Longest Common Prefix (LCP) Array: The LCP array is an array that stores the longest common prefix between two consecutive suffixes in the sorted suffix array. The purpose of creating an LCP array is to find the longest common prefix between all pairs of consecutive suffixes. This helps in finding the longest repeating substring.

// The core logic of the solution is as follows:

// Step 1: Build the suffix array of the string. This is done using the Manber-Myers algorithm, which is an efficient algorithm to build a suffix array in O(n log n) time. The algorithm starts by sorting all 1-length suffixes, then 2-length, 4-length, and so on until all suffixes are sorted.
// Step 2: Once the suffix array is built, the next step is to build the LCP array. This is done by comparing characters of suffixes one by one. If the characters match, increment the count of the longest common prefix.
// Step 3: After the LCP array is built, the maximum value in the LCP array is the length of the longest repeating substring. The substring itself can be obtained from the suffix array.
// Step 4: If the maximum LCP is 0, it means there are no repeating substrings, so the program outputs -1. Otherwise, it prints the longest repeating substring.

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// Maximum size of the string
const int maxSize = 1e5 + 5;

// Arrays for suffix array, position, temporary, and longest
// common prefix
int suffixArray[maxSize], position[maxSize],
    temporary[maxSize], LCP[maxSize];

// Variables for gap between characters and size of the
// string
int gap, n;

// The input string
string s;

// Function to compare two suffixes
bool compareSuffixes(int x, int y)
{
    // Compare function for sorting suffix array
    if (position[x] != position[y])
        return position[x] < position[y];
    x += gap;
    y += gap;
    return (x < n && y < n) ? position[x] < position[y]
                            : x > y;
}

// Function to build the suffix array
void buildSuffixArray()
{
    // Build the suffix array using the Manber-Myers
    // algorithm

    // Initialize suffix array and position array
    for (int i = 0; i < n; i++)
        suffixArray[i] = i, position[i] = s[i];

    // Iterate over gaps (powers of 2) for sorting
    for (gap = 1;; gap <<= 1)
    {
        // Sort suffix array using the current gap
        sort(suffixArray, suffixArray + n, compareSuffixes);

        // Update temporary array based on the sorted suffix
        // array
        for (int i = 0; i < n - 1; i++)
            temporary[i + 1] = temporary[i] + compareSuffixes(suffixArray[i],
                                                              suffixArray[i + 1]);

        // Update position array with temporary values
        for (int i = 0; i < n; i++)
            position[suffixArray[i]] = temporary[i];

        // Check if all suffixes are at their correct
        // position
        if (temporary[n - 1] == n - 1)
            break;
    }
}

// Function to build the longest common prefix array
void buildLCP()
{
    // Build the Longest Common Prefix (LCP) array

    // Iterate over the original string to compute LCP
    // values
    for (int i = 0, k = 0; i < n; i++)
        if (position[i] != n - 1)
        {
            // Get the next suffix in the sorted order
            int j = suffixArray[position[i] + 1];

            // Compare characters and update LCP
            while (s[i + k] == s[j + k])
                k++;

            // Set LCP value and decrement if non-zero
            LCP[position[i]] = k;
            if (k)
                k--;
        }
}

// Main function
signed main()
{

    // Read the input string
    cin >> s;
    n = s.size();

    // Build the suffix array and longest common prefix
    // array
    buildSuffixArray();
    buildLCP();

    // Find the index of the maximum element in the LCP
    // array
    int maxIndex = max_element(LCP, LCP + n) - LCP;

    // If the maximum LCP value is 0, no common substring
    // exists
    if (LCP[maxIndex] == 0)
        return cout << -1, 0;

    // Output the longest common substring
    cout << s.substr(suffixArray[maxIndex], LCP[maxIndex]);
}

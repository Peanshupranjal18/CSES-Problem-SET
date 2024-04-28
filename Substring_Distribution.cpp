#include <bits/stdc++.h>
using namespace std;

// Define constants and global variables
const int MAX_LENGTH = 1e5 + 5; // Maximum length of the input string
int suffixArray[MAX_LENGTH], position[MAX_LENGTH],
    temp[MAX_LENGTH], longestCommonPrefix[MAX_LENGTH];
int gap, stringLength; // Variables for building suffix
                       // array and LCP array
string str;            // Input string

// Comparator function for sorting suffix array
bool compare(int x, int y)
{
    // Compare the positions of suffixes
    if (position[x] != position[y])
        return position[x] < position[y];
    x += gap;
    y += gap;
    // If both suffixes are within the string length,
    // compare their positions
    return (x < stringLength && y < stringLength)
               ? position[x] < position[y]
               : x > y;
}

// Function to build the suffix array
void buildSuffixArray()
{
    // Initialize suffix array and position array
    for (int i = 0; i < stringLength; i++)
        suffixArray[i] = i, position[i] = str[i];

    // Build the suffix array using doubling technique
    for (gap = 1;; gap <<= 1)
    {
        // Sort the suffix array based on the current gap
        sort(suffixArray, suffixArray + stringLength,
             compare);
        // Update temporary array for position calculation
        for (int i = 0; i < stringLength - 1; i++)
            temp[i + 1] = temp[i] + compare(suffixArray[i],
                                            suffixArray[i + 1]);
        // Update position array
        for (int i = 0; i < stringLength; i++)
            position[suffixArray[i]] = temp[i];
        // Check if all suffixes are in lexicographically
        // sorted order
        if (temp[stringLength - 1] == stringLength - 1)
            break;
    }
}

// Function to build the LCP array
void buildLCPArray()
{
    for (int i = 0, k = 0; i < stringLength; i++)
    {
        if (position[i] != stringLength - 1)
        {
            int j = suffixArray[position[i] + 1];
            // Compute the length of common prefix between
            // suffixes
            while (str[i + k] == str[j + k])
                k++;
            longestCommonPrefix[position[i]] = k;
            if (k)
                k--; // Decrement k if it is non-zero
        }
    }
}

int prefixCount[MAX_LENGTH]; // Array to store cumulative
                             // count of distinct substrings

// Driver code
int main()
{
    // Input string (change this to your desired input)
    cin >> str;

    // Compute suffix array and LCP array
    stringLength = str.size();
    buildSuffixArray();
    buildLCPArray();

    // Calculate the number of distinct substrings
    int previous = 0;
    for (int i = 0; i < stringLength; i++)
    {
        prefixCount[previous + 1]++;
        prefixCount[stringLength - suffixArray[i] + 1]--;
        previous = longestCommonPrefix[i];
    }

    // Compute the cumulative count of distinct substrings
    for (int i = 1; i <= stringLength; i++)
    {
        cout << prefixCount[i] << ' ';
        prefixCount[i + 1] += prefixCount[i];
    }

    return 0;
}

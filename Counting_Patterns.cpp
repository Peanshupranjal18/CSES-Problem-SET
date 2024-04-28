// The idea is to uses Suffix Array data structure. A Suffix Array is a sorted array of all suffixes of a given string.

// Let’s look at the intuition in step-by-steps:

// Suffix Array Construction: The first part of the solution is to building a suffix array for the given string. A suffix array is a sorted array of all suffixes of a given string. The buildSuffixArray() function constructs this array. It starts by initializing the suffix array and position array. The position array holds the rank (i.e., lexicographic order) of each suffix. Then, it iteratively sorts the suffixes based on their current and next gap’s characters until all ranks are unique.

// Pattern Checking: The checkPattern() function checks if a pattern is present at a given position in the suffix array. It compares the characters of the pattern with the characters of the suffix starting at the given position. If the pattern is lexicographically smaller, it returns -1; if larger, it returns 1; if equal and the pattern length is less than or equal to the remaining length of the suffix, it returns 0.

// Pattern Searching: Our solve() function performs a binary search for the leftmost and rightmost occurrence of the pattern in the suffix array using the checkPattern() function. The difference between the rightmost and leftmost position plus one will gives the number of occurrences of the pattern in the string.

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int maxN = 1e5 + 5;
int suffixArray[maxN], position[maxN], temp[maxN];
int gap, n;
string s;

// Function to compare two suffixes
bool compareSuffixes(int x, int y)
{
    // Compare the positions of two suffixes
    if (position[x] != position[y])
        return position[x] < position[y];

    // Move to the next positions with a gap and
    // compare again
    x += gap;
    y += gap;
    return (x < n && y < n) ? position[x] < position[y]
                            : x > y;
}

// Function to build the suffix array
void buildSuffixArray()
{
    // Initialize the suffix array and positions based on
    // the characters of the string
    for (int i = 0; i < n; i++)
        suffixArray[i] = i, position[i] = s[i];

    // Build the suffix array using repeated sorting and
    // updating positions
    for (gap = 1;; gap <<= 1)
    {
        // Sort the suffix array based on the comparison
        // function
        sort(suffixArray, suffixArray + n, compareSuffixes);

        // Update the temporary array with cumulative
        // comparisons
        for (int i = 0; i < n - 1; i++)
            temp[i + 1] = temp[i] + compareSuffixes(suffixArray[i],
                                                    suffixArray[i + 1]);

        // Update the positions based on the sorted order
        for (int i = 0; i < n; i++)
            position[suffixArray[i]] = temp[i];

        // Check if all suffixes are in order; if so, exit
        // the loop
        if (temp[n - 1] == n - 1)
            break;
    }
}

// Function to check if a pattern is present at a given
// position in the suffix array
int checkPattern(int mid, string &pattern)
{
    int flag = -1, patternSize = pattern.size(),
        suffixStart = suffixArray[mid];

    // Check if the suffix can contain the entire pattern
    if (n - suffixStart >= patternSize)
        flag = 0;

    // Compare characters of the pattern and suffix
    for (int i = 0; i < min(n - suffixStart, patternSize);
         i++)
    {
        if (s[suffixStart + i] < pattern[i])
            return -1;
        if (s[suffixStart + i] > pattern[i])
            return 1;
    }
    return flag;
}

// Function to find and print the count of occurrences of a
// pattern in the string
void solve(string &pattern)
{
    int left = 0, right = n - 1;
    int answer = -1, l = left, r = right;

    // Binary search for the leftmost occurrence of the
    // pattern
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int check = checkPattern(mid, pattern);
        if (check == 0)
        {
            answer = mid;
            r = mid - 1;
        }
        else if (check == 1)
            r = mid - 1;
        else
            l = mid + 1;
    }

    // If the pattern is not found, print 0 and return
    if (answer == -1)
    {
        cout << 0 << endl;
        return;
    }

    // Update the left boundary for the next binary search
    left = answer, l = left, r = right;

    // Binary search for the rightmost occurrence of the
    // pattern
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int check = checkPattern(mid, pattern);
        if (check == 0)
        {
            answer = mid;
            l = mid + 1;
        }
        else if (check == -1)
            l = mid + 1;
        else
            r = mid - 1;
    }

    // Update the right boundary
    right = answer;

    // Print the count of occurrences
    cout << right - left + 1 << endl;
}

// Main function
signed main()
{
    // Set the input string and its size
    cin >> s;
    n = s.size();

    // Build the suffix array
    buildSuffixArray();
    int x;
    cin >> x;

    // Define patterns to search for
    vector<string> patterns(x);

    for (int i = 0; i < x; i++)
        cin >> patterns[i];

    // For each pattern, call the solve function to find and
    // print the count of occurrences
    for (auto pattern : patterns)
    {
        solve(pattern);
    }
}

// First calculates the z(i) or Z-function using a two-pointer approach, which keeps track of the segment within which we are currently working. After calculating the z(i) function, prints the values.

// Next, calculates the pi(i) function by iterating over the string and checking if the current character matches the character at the index equal to the pi(i) function of the previous position. If it does, it increments the pi(i) function for the current position. If it doesn’t, it finds the next smaller possible matching prefix and suffix by using the pi(i) function of the previous index until it finds a match or no more prefixes are left. After calculating the pi(i) function, it prints the values.

#include <cstring>
#include <iostream>
using namespace std;

const int maxStringLength = 1e6 + 5;

char s[maxStringLength];
int n, zFun[maxStringLength], prefixFun[maxStringLength];

int main()
{
    // Read the input string
    string s;
    cin >> s;

    int n = s.size();

    // Calculate the Z-function for each position in the
    // string
    for (int position = 1, left = 0, right = 0;
         position < n; position++)
    {
        // If within the rightmost boundary, use precomputed
        // values
        if (position <= right)
            zFun[position] = min(right - position + 1,
                                 zFun[position - left]);

        // Extend the Z-function by comparing characters
        while (position + zFun[position] < n && s[zFun[position]] == s[position + zFun[position]])
            zFun[position]++;

        // Update the boundaries for the current palindrome
        if (position + zFun[position] - 1 > right)
            left = position,
            right = position + zFun[position] - 1;
    }

    // Print the Z-function values
    for (int i = 0; i < n; i++)
        cout << zFun[i] << (" \n")[i == n - 1];

    // Calculate the prefix function for each position in
    // the string
    for (int position = 1; position < n; position++)
    {
        int j = prefixFun[position - 1];

        // Update the prefix function using previous values
        while (j > 0 && s[position] != s[j])
            j = prefixFun[j - 1];

        // Increment the prefix function if characters match
        if (s[position] == s[j])
            j++;

        // Update the prefix function for the current
        // position
        prefixFun[position] = j;
    }

    // Print the prefix function values
    for (int i = 0; i < n; i++)
        cout << prefixFun[i] << (" \n")[i == n - 1];

    return 0;
}

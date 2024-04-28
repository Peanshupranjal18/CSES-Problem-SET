// The idea is to hash table to store the forward and backward representations of the string. Each character in the string is mapped with a unique prime number (hash), and the representation of a substring is the product of the hashes of its characters. This allows us to compute the representation of any substring in constant time, given the representations of its prefix and suffix.

// Lets breakdown step-by-step solution:

// We will do Preprocessing: We first compute the powers of a fixed hash for each position in the string, and initialize two hash tables to store the forward and backward representations of the string.

// We’ll Updating a Character: When the operation is to change a character, we update the forward and backward hash tables at the corresponding position. This is done by multiplying the old hash at the position by the new hash, and updating the hash tables.

// Checking a Substring: When the operation is to check if a substring is a palindrome, we query the forward and backward hash tables for the substring, and adjust the hashes by the appropriate powers to align the substring with the start of the string. If the adjusted forward and backward hashes are equal, then the substring is a palindrome.

// Performing the Operations: We perform each operation in the order given. For each operation, we either update a character or check a substring as described above.

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll HASH = 257, MOD = 1e9 + 7;

int n, m;
ll hashPower[200005] = {1};
ll fwdHashTable[400005];
ll bckHashTable[400005];

void updatefwd(int i, ll v)
{
    for (fwdHashTable[i += n] = v; i > 1; i >>= 1)
        fwdHashTable[i >> 1] = (fwdHashTable[i] + fwdHashTable[i ^ 1]) % MOD;
}

ll queryfwd(int l, int r)
{
    ll res = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = (res + fwdHashTable[l++]) % MOD;
        if (r & 1)
            res = (res + fwdHashTable[--r]) % MOD;
    }
    return res;
}

void updatebck(int i, ll v)
{
    for (bckHashTable[i += n] = v; i > 1; i >>= 1)
        bckHashTable[i >> 1] = (bckHashTable[i] + bckHashTable[i ^ 1]) % MOD;
}

ll querybck(int l, int r)
{
    ll res = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = (res + bckHashTable[l++]) % MOD;
        if (r & 1)
            res = (res + bckHashTable[--r]) % MOD;
    }
    return res;
}

int main()
{
    // Read the input
    cin >> n >> m;
    string s;
    cin >> s;

    // Prepare the power array
    for (int i = 1; i < n; i++)
    {
        hashPower[i] = (hashPower[i - 1] * HASH) % MOD;
    }

    // Initialize hash tables
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        updatefwd(i, hashPower[i] * (ll)c % MOD);
        updatebck(i, hashPower[n - i - 1] * (ll)c % MOD);
    }

    // Process operations
    for (int i = 0; i < m; i++)
    {
        int opType;
        cin >> opType;
        if (opType == 1)
        {
            int position;
            char newChar;
            cin >> position >> newChar;
            position--; // Adjust index to 0-based

            // Update hash tables with new character
            updatefwd(position, hashPower[position] * (ll)newChar % MOD);
            updatebck(position, hashPower[n - position - 1] * (ll)newChar % MOD);
        }
        else if (opType == 2)
        {
            int left, right;
            cin >> left >> right;
            left--, right--; // Adjust indices to 0-based

            // Calculate forward and backward hashes
            ll fwd = queryfwd(left, right);
            fwd = (fwd * hashPower[n - 1 - right]) % MOD;
            ll bck = querybck(left, right);
            bck = (bck * hashPower[left]) % MOD;

            // Check if the hashes are equal
            if (fwd == bck)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}

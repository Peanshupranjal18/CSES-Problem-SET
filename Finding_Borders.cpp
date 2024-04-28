#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// Constants
const ll MOD = 1e9 + 7;
const ll p1 = 31;
const ll p2 = 37;
const int maxN = 1e6 + 5;

// Variables
ll pow1[maxN], pow2[maxN], ph1, ph2, sh1, sh2;
// Function to find borders
void solve(string &S, int N)
{
    // Initialize the powers of p1 and p2
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < N; i++)
    {
        pow1[i] = (pow1[i - 1] * p1) % MOD;
        pow2[i] = (pow2[i - 1] * p2) % MOD;
    }

    // Calculate the prefix and suffix hashes
    for (int i = 0; i < N - 1; i++)
    {
        int l = (S[i] - 'a' + 1);
        int r = (S[N - i - 1] - 'a' + 1);

        ph1 = (ph1 + l * pow1[i]) % MOD;
        ph2 = (ph2 + l * pow2[i]) % MOD;
        sh1 = (sh1 * p1 + r) % MOD;
        sh2 = (sh2 * p2 + r) % MOD;

        // If the prefix and suffix hashes are equal, print
        // the length of the border
        if (ph1 == sh1 && ph2 == sh2)
            printf("%d ", i + 1);
    }
}
// Drivers code
int main()
{
    // Read the input string
    string S;
    cin >> S;
    int N = S.size();
    solve(S, N);
    return 0;
}

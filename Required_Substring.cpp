// We build string character by character, and we track progress of building required string as our substring.

// Example:

// Required substring: ABC

// Current string: XHG AB

// Here our progress equals 2, because last two characters match with first two characters of required substring.

// Now we only need a way to recalculate progress as we push more characters into our string, and for that we will use KMP. If current pushed character equals t[progress] we increase progress by one. If it reaches t.size(), we now have t as substring and rest can be filled however, but, if we pushed character that doesn't equal to current progress character, we must decrease progress value. Naively, you'd think it resets to 0, but look at this:

// Required substring: ABAC

// Current string: ABA and we insert B (ABAB, progress before inserting is 3 because ABA is matched)

// Current string will be ABAB and its progress will be 2, as suffix "AB" matches prefix of 2 characters of required substring.

// So it doesn't necessary resets to 0, we will use KMP to calculate what it resets to, and we continue forward to build rest of the string.

// If we filled all n positions without reaching progress of t.size(), we doesn't add to answer.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
const int mxN = 1001;
const int mxM = 101;
const int mxK = 26;
const int mod = 1e9 + 7;

int kmp[mxN];

void calc(string &s)
{
    kmp[0] = 0;
    for (int i = 1; i < (int)s.size(); i++)
    {
        int trymatch = kmp[i - 1];
        while (true)
        {
            if (s[trymatch] == s[i])
            {
                kmp[i] = trymatch + 1;
                break;
            }
            else if (trymatch)
            {
                trymatch = kmp[trymatch - 1];
            }
            else
            {
                kmp[i] = 0;
                break;
            }
        }
    }
}

ll dp[mxN][mxM];
bool done[mxN][mxM];

ll solve(int i, int n, int j, string &s)
{
    if (done[i][j])
        return dp[i][j];
    done[i][j] = true;
    if (i == n)
        return dp[i][j] = (j == (int)s.size() ? 1 : 0);
    if (j == (int)s.size())
    {
        return dp[i][j] = (mxK * solve(i + 1, n, j, s)) % mod;
    }
    ll ans = 0;
    int t;
    for (int k = 0; k < mxK; k++)
    {
        t = j;
        while (true)
        {
            if (k == s[t] - 'A')
            {
                t++;
                break;
            }
            else if (t)
            {
                t = kmp[t - 1];
            }
            else
                break;
        }
        ans += solve(i + 1, n, t, s);
        ans %= mod;
    }
    return dp[i][j] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    calc(s);
    cout << solve(0, n, 0, s);
}
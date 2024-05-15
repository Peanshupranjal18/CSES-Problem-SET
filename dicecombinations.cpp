#include <bits/stdc++.h>
using namespace std;
#define intt long long
#define MOD 1000000007

intt solution(intt n, vector<intt> &dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    intt ways = 0;

    for (intt i = 1; i <= 6; i++)
    {
        ways = (ways + solution(n - i, dp)) % MOD;
    }

    return dp[n] = ways;
}

void solve()
{
    intt n;
    cin >> n;
    vector<intt> dp(n + 1, 0);
    dp[0] = 1;

    // recursive stack kaha tak jaayega
    for (intt i = 1; i <= n; i++)
    {
        for (intt j = 1; j <= 6 and i - j >= 0; j++)
        {
            // uss recursive state mein ways mein kya change hoga
            (dp[i] += dp[i - j]) %= MOD;
        }
    }
    cout << dp[n] << "\n";
}

signed main()
{
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define intt long long

void solve()
{
    intt n;
    cin >> n;

    vector<intt> dp(n + 1, LLONG_MAX);
    dp[0] = 0;

    for (intt i = 1; i <= n; i++)
    {
        string s = to_string(i);
        for (char c : s)
        {
            int digit = c - '0';
            if (digit != 0 && i - digit >= 0)
            {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }

    cout << dp[n] << "\n";
    return;
}

signed main()
{
    solve();
    return 0;
}
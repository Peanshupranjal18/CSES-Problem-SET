#include <bits/stdc++.h>
using namespace std;
#define intt long long
const int MOD = 1e9 + 7;

void solve()
{
    intt n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));

    for (intt i = 0; i < n; i++)
    {
        for (intt j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<vector<intt>> dp(n, vector<intt>(n, 0));

    if (v[0][0] == '*')
    {
        cout << 0;
        return;
    }

    dp[0][0] = 1;

    for (intt i = 0; i < n; i++)
    {
        for (intt j = 0; j < n; j++)
        {
            if (v[i][j] == '*')
            {
                dp[i][j] = 0;
            }
            else
            {
                if (i > 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j > 0)
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1];
    return;
}

signed main()
{
    solve();
    return 0;
}
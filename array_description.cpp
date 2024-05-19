#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    // Initialize the dp array for the first element
    if (v[0] == 0)
    {
        for (int j = 1; j <= m; j++)
            dp[0][j] = 1;
    }
    else
    {
        dp[0][v[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (v[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 1)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                if (j + 1 <= m)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
            }
        }
        else
        {
            dp[i][v[i]] = dp[i - 1][v[i]];
            if (v[i] - 1 >= 1)
                dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i] - 1]) % mod;
            if (v[i] + 1 <= m)
                dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i] + 1]) % mod;
        }
    }

    int ans = 0;
    for (int j = 1; j <= m; j++)
    {
        ans = (ans + dp[n - 1][j]) % mod;
    }

    cout << ans << "\n";
}

signed main()
{
    solve();
    return 0;
}
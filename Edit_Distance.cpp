#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Base cases
    for (int i = 0; i <= n; i++)
    {
        dp[i][m] = n - i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[n][j] = m - j;
    }

    // Fill dp array from bottom-right to top-left
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
            }
        }
    }

    cout << dp[0][0];
}

signed main()
{
    solve();
    return 0;
}

#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1000000007

using namespace std;

intt solve(intt n, intt m, vector<string> &v)
{
    vector<vector<intt>> dp(n + 1, vector<intt>(m + 1, 0));
    dp[0][1] = 1; // Start from (1, 1) and initialize the first cell to 1

    for (intt i = 1; i <= n; i++)
    {
        for (intt j = 1; j <= m; j++)
        {
            if (v[i - 1][j - 1] != '*')
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    return dp[n][m];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    intt a;
    cin >> a;
    vector<string> v(a);
    for (int i = 0; i < a; i++)
    {
        cin >> v[i];
    }
    intt n = a;
    intt m = v[0].length();
    intt ans = solve(n, m, v);
    cout << ans << "\n";
    return 0;
}

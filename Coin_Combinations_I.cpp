#include <bits/stdc++.h>
using namespace std;
#define intt long long

const intt mod = 1e9 + 7;

void solve()
{
    intt n, x;
    cin >> n >> x;
    vector<intt> coins(n);

    for (intt i = 0; i < n; i++)
        cin >> coins[i];

    vector<intt> dp(x + 1, 0);

    dp[0] = 1;

    for (intt i = 1; i <= x; i++)
    {
        for (intt j = 0; j < n; j++)
        {
            if (coins[j] > i)
                continue;
            dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
        }
    }

    cout << dp[x] << "\n";
}

signed main()
{
    solve();
    return 0;
}
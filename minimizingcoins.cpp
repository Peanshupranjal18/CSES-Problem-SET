#include <bits/stdc++.h>
using namespace std;
#define intt long long

void solve()
{
    intt n, x;
    cin >> n >> x;
    vector<intt> v(n);

    for (intt i = 0; i < n; i++)
        cin >> v[i];

    vector<intt> dp(x + 1, LLONG_MAX);

    dp[0] = 0;

    for (intt i = 1; i <= x; i++)
    {
        for (intt j = 0; j < n; j++)
        {
            if (v[j] <= i)
            {
                dp[i] = min(dp[i], 1 + dp[i - v[j]]);
            }
        }
    }
    intt ans = (dp[x] == LLONG_MAX) ? -1 : dp[x];
    cout << ans << "\n";
}

signed main()
{
    solve();
    return 0;
}
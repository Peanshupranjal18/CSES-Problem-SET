#include <bits/stdc++.h>
using namespace std;
#define intt long long

const intt mod = 1e9 + 7;

void solve()
{
    intt n, x;
    cin >> n >> x;
    vector<intt> v(n);

    for (intt i = 0; i < n; i++)
        cin >> v[i];

    vector<intt> dp(x + 1);

    dp[0] = 1;

    for (intt i = 0; i < n; i++)
    {
        for (intt j = v[i]; j <= x; j++)
        {
            dp[j] = (dp[j] + dp[j - v[i]]) % mod;
        }
    }

    cout << dp[x] << "\n";
    return;
}

signed main()
{
    solve();
    return 0;
}
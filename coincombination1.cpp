#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD (intt)(1e9 + 7)
using namespace std;

intt solve(vector<intt> &v, intt n, intt x)
{
    vector<intt> dp(x + 1, 0);
    dp[0] = 1;

    for (intt i = 1; i <= x; i++)
    {
        for (intt j = 0; j < n; j++)
        {
            if (i - v[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i - v[j]]) % MOD;
            }
        }
    }

    return dp[x];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    intt n, x;
    cin >> n >> x;
    vector<intt> v(n);
    for (intt i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    intt ans = solve(v, n, x);
    cout << ans << "\n";
    return 0;
}

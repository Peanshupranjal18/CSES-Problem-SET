#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1000000007
using namespace std;

int main()
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

    vector<intt> dp(x + 1, INT_MAX);
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

    intt ans = dp[x] == INT_MAX ? -1 : dp[x];
    if (ans == INT_MAX)
        ans = -1;
    cout << ans << "\n";

    return 0;
}

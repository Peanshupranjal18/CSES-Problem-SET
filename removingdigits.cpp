#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1000000007

using namespace std;

intt solve(intt n)
{
    vector<intt> dp(n + 1, 1e9); // Initialize dp array with a large value
    dp[0] = 0;

    for (intt i = 1; i <= n; i++)
    {
        intt num = i;
        while (num > 0)
        {
            intt digit = num % 10;
            num /= 10;
            dp[i] = min(dp[i], 1 + dp[i - digit]);
        }
    }

    return dp[n];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    intt n;
    cin >> n;
    intt ans = solve(n);
    cout << ans << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int cnt[100];
int dp[100][5005], jcinv[5005], inv[5005], jc[5005];
int C[5005][5005];

signed main()
{
    jc[0] = jc[1] = jcinv[0] = jcinv[1] = inv[1] = 1;
    for (int i = 2; i <= 5000; i++)
    {
        jc[i] = jc[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        jcinv[i] = jcinv[i - 1] * inv[i] % mod;
    }
    string s;
    cin >> s;
    int n = s.size();
    for (auto t : s)
        ++cnt[t - 'a'];
    dp[0][max(0ll, cnt[0] - 1)] = 1;
    for (int i = 0; i <= 5000; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    int sum = cnt[0] + 1;
    for (int i = 1; i <= 25; i++)
    {
        if (!cnt[i])
        {
            for (int j = 0; j <= 5000; j++)
                dp[i][j] = dp[i - 1][j];
            continue;
        }
        for (int j = 1; j <= cnt[i]; j++)
        {
            int tot = sum - j + 1;
            int nx[5005] = {};
            for (int k = 0; k <= tot; k++)
            {
                nx[k] += dp[i - 1][k] * (tot - k);
                nx[k - 1] += dp[i - 1][k] * (k);
            }
            for (int k = 0; k <= tot; k++)
            {
                nx[k] %= mod;
                dp[i - 1][k] = nx[k];
                dp[i][k + cnt[i] - j] = (dp[i][k + cnt[i] - j] + nx[k] * C[cnt[i] - 1][j - 1] % mod * jcinv[j]) % mod;
            }
        }
        sum += cnt[i];
    }
    cout << (dp[25][0] % mod + mod) % mod;
    return 0;
}
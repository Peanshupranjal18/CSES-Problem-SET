#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2555555
#define pii pair<ll, ll>

const ll mod = 1e9 + 7;

ll n, m;
ll fac[N], inv[N], dp[N];
pii vec[N];

ll fastpow(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

void init(int n)
{
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    inv[n] = fastpow(fac[n], mod - 2);
    for (ll i = n - 1; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
}

ll C(ll n, ll m)
{
    return ((fac[n] * inv[m]) % mod * inv[n - m]) % mod;
}

signed main()
{
    cin >> n >> m;
    init(n * 2);

    for (ll i = 0; i < m; i++)
        cin >> vec[i].first >> vec[i].second;

    sort(vec, vec + m);
    vec[m] = {n, n};

    for (ll i = 0; i <= m; i++)
    {
        int yi = vec[i].first, xi = vec[i].second;
        dp[i] = C(xi + yi - 2, xi - 1);
        for (int j = 0; j < i; j++)
        {
            int yj = vec[j].first, xj = vec[j].second;
            dp[i] = (dp[i] - (dp[j] * C(xi - xj + yi - yj, xi - xj) % mod) + mod) % mod;
        }
    }
    cout << dp[m] << "\n";
    return 0;
}
// Let’s first create an Adjacency matrix. We can see for the case of k=1
// , the answer is the constructed Adjacency Matrix, for any 2 pair of nodes.
// Next let the matrix Mk
//  denote the answer matrix for k
// .
// Then Mk+1[i][j]=∑nl=1Mk[i][l].AdjMat[l][j]
// .
// Thus the solution of the problem is AdjMatk
// .
// For more info refer- https://cp-algorithms.com/graph/fixed_length_paths.html

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

const int MOD = 1000000007;
long long int inverse(long long int i)
{
    if (i == 1)
        return 1;
    return (MOD - ((MOD / i) * inverse(MOD % i)) % MOD + MOD) % MOD;
}
ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % MOD;
    ll temp = POW(a, b / 2);
    if (b % 2 == 0)
        return (temp * temp) % MOD;
    else
        return (((temp * temp) % MOD) * a) % MOD;
}

ll n;

vector<vll> mul(vector<vll> x, vector<vll> y)
{
    vector<vll> r(n, vll(n));
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < n; l++)
            {
                r[j][k] = (r[j][k] + (x[j][l] * y[l][k]) % MOD) % MOD;
            }
        }
    }
    return r;
}

vector<vll> modpow(vector<vll> x, ll pw)
{
    if (pw == 0)
    {
        vector<vll> r(n, vll(n));
        for (int i = 0; i < n; i++)
            r[i][i] = 1;
        return r;
    }
    vector<vll> u = modpow(x, pw / 2);
    u = mul(u, u);
    if (pw % 2 == 1)
        u = mul(u, x);
    return u;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll m, k, a, b;
    cin >> n >> m >> k;
    vector<vll> v(n, vll(n, 0));
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        v[a][b]++;
    }
    cout << modpow(v, k)[0][n - 1];
}
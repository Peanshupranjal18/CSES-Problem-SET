// This is a standard problem of finding derangements in a sequence.
// The recursive formula is D(n)=(D(n−1)+D(n−2))(n−1).
// For info regarding derangement, see https://en.wikipedia.org/wiki/Derangement.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll d[n + 1];
    d[1] = 0;
    d[2] = 1;
    for (ll i = 3; i <= n; i++)
    {
        d[i] = (((d[i - 1] + d[i - 2]) % MOD) * (i - 1)) % MOD;
    }
    cout << d[n];
}
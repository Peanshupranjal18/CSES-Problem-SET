// Let dp[n] denote the number of bracket sequences with n
// pairs of bracket. At first index, there is always a opening bracket and somewhere is between there is a closing bracket. So we look at how many sequences of i
// pairs of brackets are there between them and how many sequences of n−i−1
// pairs of brackets are after them. So we get the recursive formula – dp[n]=∑n−1i=0dp[i]dp[n−i−1]
// .
// And dp[0]=0
// . In fact this is nothing but the Catalan number Cn=1n+1(2nn)
// .
// You can refer to this — https://cp-algorithms.com/combinatorics/bracket_sequences.html

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1000000007;
long long int inverse(long long int i)
{
    if (i == 1)
        return 1;
    return (MOD - ((MOD / i) * inverse(MOD % i)) % MOD + MOD) % MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    if (n % 2 == 1)
    {
        cout << 0;
        return 0;
    }
    n /= 2;
    ll fact[2 * n + 1];
    fact[0] = 1;
    for (ll i = 1; i <= 2 * n; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ll ans = (fact[2 * n] * inverse(fact[n])) % MOD;
    ans *= (inverse(fact[n]) * inverse(n + 1)) % MOD;
    ans %= MOD;
    cout << ans;
}
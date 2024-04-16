// Let k
//  denote the excess opening brackets which we need to close and n
//  denote the remaining pairs. This can be easily found out given the length and the prefix portion of the string.
// Let us denote the answer by C(k)n
// . The generalized formula is -
// C(k)n=∑a+b+⋯+λ=nCaCb…Cλ
// , C0=1
// .
// where there are k+1
//  terms, Ca,Cb,…,Cλ
// .
// This is basically a convolution on Catalan. Similar to deriving the expression for Catalan number, we get C(k)n=k+1n+k+1(2n+kk)
// .
// You can refer to this — https://codeforces.com/blog/entry/87585

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
    string s;
    cin >> s;
    ll k = 0, o = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            k++;
            o++;
        }
        else
            k--;
        if (k < 0)
        {
            cout << 0;
            return 0;
        }
    }
    n -= o;
    if (k < 0 || n < 0 || 2 * n + k < n)
    {
        cout << 0;
        return 0;
    }
    ll fact[2 * n + k + 1];
    fact[0] = 1;
    for (int i = 1; i <= 2 * n + k; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ll ans = (fact[2 * n + k] * inverse(fact[n])) % MOD;
    ans *= inverse(fact[n + k]);
    ans %= MOD;
    ans *= ((k + 1) * inverse(n + k + 1)) % MOD;
    ans %= MOD;
    cout << ans;
}
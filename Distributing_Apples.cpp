// It is equivalent to finding the number of solution to x1+x2+⋯+xn=m
// , where x1,x2,⋯,xn
//  are non negative integers.
// You can see that here- https://www.geeksforgeeks.org/number-of-integral-solutions-of-the-equation-x1-x2-xn-k/.

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll fact[2000001];
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= 2000000; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ll n, m;
    cin >> n >> m;
    ll ans = (fact[m + n - 1] * inverse(fact[n - 1])) % MOD;
    ans *= inverse(fact[m]);
    ans %= MOD;
    cout << ans;
}
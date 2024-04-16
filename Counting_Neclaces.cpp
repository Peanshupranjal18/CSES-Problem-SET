// This is computed by using Burnside’s Lemma. It states that the total number of distinct objects is ∑Nk=1c(k)N
// , where c(k)
//  is number of combination that remain unchanged when k
// -th rotation is applied. If we rotate the necklace by i
// , mgcd(i,n)
//  necklaces will remain the same.
// So the answer would be ∑ni=1mgcd(i,n)n
// .
// You can refer to this — https://www.geeksforgeeks.org/orbit-counting-theorem-or-burnsides-lemma/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int md = 1e9 + 7;

int exp(int x, int y, int md)
{
    int ans = 1;
    x = x % md;
    while (y > 0)
    {
        if (y & 1)
            ans = ans * x % md;
        y = y >> 1;
        x = x * x % md;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    // burnside's lemma
    // no. of objects = avg. no of symmetrical pictures over all symmetries.
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = (ans + exp(m, __gcd(i, n), md)) % md;
    }
    ans = ans * exp(n, md - 2, md) % md;
    cout << ans;
}
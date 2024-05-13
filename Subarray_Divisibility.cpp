#include <bits/stdc++.h>
using namespace std;
#define intt long long

void solve()
{
    intt n;
    cin >> n;
    vector<intt> v(n);

    for (intt i = 0; i < n; i++)
        cin >> v[i];

    unordered_map<intt, intt> mp;

    mp[0] = 1;
    intt rem = 0, cnt = 0;

    for (intt i = 0; i < n; i++)
    {
        // Since arr[i] can be negative, we add N to the
        // remainder to avoid negative remainders
        rem = ((rem + v[i]) % n + n) % n;
        cnt += mp[rem];
        mp[rem] += 1;
    }

    cout << cnt << "\n";
    return;
}

signed main()
{
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        auto it = mp.upper_bound(b);
        if (it == mp.begin())
        {
            cout << -1 << "\n";
        }
        else
        {
            it--;
            cout << it->first << "\n";
            it->second -= 1;
            if (it->second == 0)
            {
                mp.erase(it);
            }
        }
    }
    return;
}

signed main()
{
    solve();
    return 0;
}
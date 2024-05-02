#include <bits/stdc++.h>
using namespace std;
#define intt long long

void solve()
{
    intt n;
    cin >> n;
    vector<pair<intt, intt>> v(n);
    for (intt i = 0; i < n; i++)
    {
        intt x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    intt ans = 1;
    intt r1 = v[0].second;
    for (intt i = 0; i < n; i++)
    {
        intt l1 = v[i].first;
        intt r2 = v[i].second;
        if (l1 >= r1)
        {
            ans++;
            r1 = r2;
        }
    }
    cout << ans << "\n";
}

signed main()
{
    solve();
    return 0;
}
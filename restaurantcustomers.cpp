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
        intt a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }

    sort(v.begin(), v.end());
    intt curr = 0;
    intt maxi = 0;

    for (int i = 0; i < v.size(); i++)
    {
        curr += v[i].second;
        maxi = max(curr, maxi);
    }

    cout << maxi << "\n";
    return;
}

signed main()
{
    solve();
    return 0;
}
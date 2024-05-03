#include <bits/stdc++.h>
using namespace std;
#define intt long long

void solve()
{
    intt n, m;
    cin >> n >> m;

    vector<intt> v(n + 1);

    for (intt i = 1; i <= n; i++)
        cin >> v[i];

    vector<intt> pos(n + 1);

    for (intt i = 1; i <= n; i++)
        pos[v[i]] = i;

    intt count = 1;

    // exceeding the limit of the code over here which caused the code to
    // overflow

    for (intt i = 1; i < n; i++)
        count += (pos[i] > pos[i + 1]);

    set<pair<intt, intt>> updates;

    for (intt i = 0; i < m; i++)
    {
        intt a, b;
        cin >> a >> b;

        if (v[a] - 1 >= 1)
            updates.insert({v[a] - 1, v[a]});
        if (v[a] + 1 <= n)
            updates.insert({v[a], v[a] + 1});
        if (v[b] - 1 >= 1)
            updates.insert({v[b] - 1, v[b]});
        if (v[b] + 1 <= n)
            updates.insert({v[b], v[b] + 1});

        for (auto it : updates)
            count -= pos[it.first] > pos[it.second];

        swap(v[a], v[b]);

        pos[v[a]] = a;
        pos[v[b]] = b;

        for (auto it : updates)
            count += pos[it.first] > pos[it.second];

        cout << count << "\n";
        updates.clear();
    }
    return;
}

signed main()
{
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define intt long long

void solve()
{
    intt n;
    cin >> n;

    vector<tuple<intt, intt, intt>> v;

    for (intt i = 0; i < n; i++)
    {
        intt a, b;
        cin >> a >> b;
        v.emplace_back(a, -1, i);
        v.emplace_back(b, 1, i);
    }

    sort(v.begin(), v.end());
    intt dp[n + 1];

    vector<intt> rooms;
    intt occ = 0, max_rooms = 0, in_or_out, ind;
    for (auto ele : v)
    {
        in_or_out = get<1>(ele);
        ind = get<2>(ele);
        if (in_or_out == 1)
        {
            // going out so add that room number to rooms
            rooms.push_back(dp[ind]);
        }
        else if (occ == rooms.size())
        {
            // no more vacant rooms , so increase number of rooms
            dp[ind] = ++max_rooms;
        }
        else
        {
            // give a room and increase occupancy count
            dp[ind] = rooms[occ++];
        }
    }
    cout << max_rooms << "\n";
    for (intt i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    return;
}

signed main()
{
    solve();
    return 0;
}
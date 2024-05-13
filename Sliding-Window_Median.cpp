#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
#define intt long long

intt n, k, t;

void solve()
{
    cin >> n >> k;

    vector<intt> v(n);

    ordered_set oset;

    for (intt i = 0; i < n; i++)
    {
        intt u;
        cin >> u;
        v[i] = u;

        oset.insert({u, t++});
        if (i >= k)
        {
            oset.erase(oset.lower_bound({v[i - k], 0}));
        }
        if (i >= k - 1)
        {
            cout << (*oset.find_by_order((k - 1) / 2)).first << " ";
        }
    }
}

signed main()
{
    solve();
    return 0;
}
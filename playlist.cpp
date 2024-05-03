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

    map<intt, intt> mp;

    intt i = 0;
    intt j = 0;
    intt curr = 0;
    intt maxi = 0;

    while (j < n)
    {
        if (mp.find(v[j]) == mp.end() or mp[v[j]] == 0)
        {
            mp[v[j]]++;
            curr++;
            maxi = max(maxi, curr);
            j++;
        }
        else
        {
            curr--;
            mp[v[i]]--;
            i++;
        }
    }
    cout << maxi << "\n";
}

signed main()
{
    solve();
    return 0;
}
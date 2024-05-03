#include <bits/stdc++.h>
using namespace std;
#define intt long long

void solve()
{
    intt n;
    cin >> n;
    intt v[n];
    for (intt i = 0; i < n; i++)
        cin >> v[i];
    intt ans = 1LL;
    sort(v, v + n);
    for (intt i = 0; i < n; i++)
    {
        if (v[i] > ans)
        {
            cout << ans << "\n";
            return;
        }
        ans += v[i];
    }
    cout << ans << "\n";
    return;
}

signed main()
{
    solve();
    return 0;
}
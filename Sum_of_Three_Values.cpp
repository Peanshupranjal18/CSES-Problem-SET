#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int curr = v[i][0] + v[j][0] + v[k][0];
            if (curr == m)
            {
                cout << v[i][1] + 1 << " " << v[j][1] + 1 << " " << v[k][1] + 1 << "\n";
                return;
            }
            else if (curr > m)
            {
                k--;
            }
            else if (curr < m)
            {
                j++;
            }
        }
    }

    cout << "IMPOSSIBLE"
         << "\n";
}

signed main()
{
    solve();
    return 0;
}
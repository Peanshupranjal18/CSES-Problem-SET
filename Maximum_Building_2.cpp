#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int aa[n + 1][m + 1], ans[n + 1][m + 1];
    memset(aa, 0, sizeof(aa));
    memset(ans, 0, sizeof(ans));
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            aa[i][j + 1] = ((s[j] == '.') ? 0 : 1);
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            aa[i][j] += aa[i - 1][j];
    }
    for (int u = 1; u <= n; u++)
    {
        for (int i = u; i <= n; i++)
        {
            int cnt = 0;
            for (int j = 1; j <= m; j++)
            {
                if (aa[i][j] == aa[i - u][j])
                {
                    cnt++;
                    ans[u][cnt]++;
                }
                else
                    cnt = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m - 1; j > 0; j--)
        {
            ans[i][j] += ans[i][j + 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

int32_t main()
{
    solve();
    return 0;
}
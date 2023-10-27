// all route shortest path flloyd warshall algorithm it will
// also handle large cases
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> edges;
    for (long long i = 0; i < m; i++)
    {
        long long a, b, w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }
    long long adj[n + 1][n + 1];
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= n; j++)
        {
            adj[i][j] = 1e18;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    for (auto e : edges)
    {
        long long a = e[0], b = e[1], c = e[2];
        adj[a][b] = min(c, adj[a][b]);
        adj[b][a] = min(c, adj[b][a]); // This line should be corrected
    }
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= n; j++)
        {
            for (long long k = 1; k <= n; k++)
            {
                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
            }
        }
    }
    while (q--)
    {
        long long a, b;
        cin >> a >> b;
        if (adj[a][b] == 1e18)
            cout << -1 << '\n';
        else
            cout << adj[a][b] << '\n';
    }
    return 0;
}

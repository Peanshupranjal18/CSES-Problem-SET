// dp on graph

#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1e9 + 7
using namespace std;

bool vis[200001];
intt dp[200001];
intt next_node[200001], n;
vector<vector<intt>> adj(200001);

void dfs(intt node)
{
    vis[node] = true;

    for (auto i : adj[node])
    {
        if (vis[i] == false)
            dfs(i);
        if ((dp[i] != -1) and (dp[i] + 1 > dp[node]))
        {
            dp[node] = dp[i] + 1;
            next_node[node] = i;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    intt m, a, b;
    cin >> n >> m;

    for (intt i = 1; i <= n; i++)
        dp[i] = -1;
    dp[n] = 1;

    for (intt i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1);

    if (dp[1] == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << dp[1] << "\n";
        int node = 1;
        while (node)
        {
            cout << node << " ";
            node = next_node[node];
        }
    }
    return 0;
}
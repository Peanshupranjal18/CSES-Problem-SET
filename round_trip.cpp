#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis;

void solve()
{
	cin >> n >> m;
	adj.resize(n + 1);
	vis.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == -1)
		{
			dfs(i);
		}
	}
}

signed main()
{
	solve();
	return 0;
}
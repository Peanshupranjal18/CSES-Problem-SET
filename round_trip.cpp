#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis;
vector<int> parent;
int sv, ev;

void dfs(int u, int p)
{
	vis[u] = true;
	parent[u] = p;
	for (auto it : adj[u])
	{
		if (it == p)
			continue;
		if (vis[it])
		{
			sv = it;
			ev = u;
			return true;
		}
		if (!vis[it])
			if (dfs(it, u))
				return true;
	}
	return false;
}

bool visit_all()
{
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
			if (dfs(i, -1))
				return true;
	}
	return false;
}

void solve()
{
	cin >> n >> m;
	adj.resize(n + 1);
	vis.resize(n + 1);
	parent.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	if (!visit_all())
	{
		cout << "IMPOSSIBLE"
			 << "\n";
		return;
	}

	int tv = ev;
	vector<int> ans;
}

signed main()
{
	solve();
	return 0;
}
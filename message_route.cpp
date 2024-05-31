#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis;
vector<int> parent;

bool bfs(int node)
{
	queue<int> q;
	vis[node] = 1;
	q.push(node);

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (auto it : adj[curr])
		{
			if (vis[it] == -1)
			{
				q.push(it);
				vis[it] = 1;
				parent[it] = curr;

				if (it == n)
				{
					return true;
				}
			}
		}
	}

	return false;
}

void solve()
{
	cin >> n >> m;
	// source - 1 destination - n

	adj.resize(n + 1);
	vis.resize(n + 1, -1);
	parent.resize(n + 1, -1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bool ans = bfs(1);
	vector<int> path;
	if (ans)
	{
		int curr = n;
		while (curr != -1)
		{
			path.push_back(curr);
			curr = parent[curr];
		}
		reverse(path.begin(), path.end());
		cout << path.size() << "\n";
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		cout << "IMPOSSIBLE"
			 << "\n";
	}
}

signed main()
{
	solve();
	return 0;
}
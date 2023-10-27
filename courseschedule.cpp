#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1e9 + 7
using namespace std;

bool topo_sort(vector<vector<intt>> &adj, stack<intt> &st, vector<intt> &vis, intt node)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (!topo_sort(adj, st, vis, it))
                return false;
        }
        else if (vis[it] == 1)
        {
            // Cycle detected, topological sort not possible
            return false;
        }
    }
    vis[node] = 2;
    st.push(node);
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    intt n, m;
    cin >> n >> m;
    vector<vector<intt>> adj(n);
    for (intt i = 0; i < m; i++)
    {
        intt a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }
    stack<intt> st;
    vector<intt> vis(n, 0);
    bool possible = true;

    for (intt i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (!topo_sort(adj, st, vis, i))
            {
                possible = false;
                break;
            }
        }
    }

    if (possible)
    {
        while (!st.empty())
        {
            cout << st.top() + 1 << " ";
            st.pop();
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class DisJointSet
{
    vector<long long int> parent, size;

public:
    DisJointSet(long long int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (long long int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    long long int findpar(long long int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findpar(parent[x]);
    }

    void unionBySize(long long int u, long long int v)
    {
        long long int ulp_u = findpar(u);
        long long int ulp_v = findpar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long int n, m;
    cin >> n >> m;

    vector<pair<long long int, pair<long long int, long long int>>> edges;

    for (long long int i = 0; i < m; i++)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    sort(edges.begin(), edges.end());

    DisJointSet ds(n);

    long long int minCost = 0;

    for (auto edge : edges)
    {
        long long int cost = edge.first;
        long long int u = edge.second.first;
        long long int v = edge.second.second;

        if (ds.findpar(u) != ds.findpar(v))
        {
            minCost += cost;
            ds.unionBySize(u, v);
        }
    }

    // Check if all cities are in the same component
    long long int numComponents = 0;
    for (long long int i = 1; i <= n; i++)
    {
        if (ds.findpar(i) == i)
        {
            numComponents++;
        }
    }

    if (numComponents > 1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << minCost;
    }

    return 0;
}

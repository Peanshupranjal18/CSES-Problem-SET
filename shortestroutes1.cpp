#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 3;

vector<vector<pair<long long, long long>>> adj(N, vector<pair<long long, long long>>());
vector<long long> dist(N, LLONG_MAX);

void dijkstra()
{
    dist[1] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        long long d = pq.top().first;
        long long u = pq.top().second;
        pq.pop();
        if (dist[u] < d)
            continue;
        for (auto e : adj[u])
        {
            long long v = e.second;
            long long c = e.first;
            if (dist[v] <= c + d)
                continue;
            else
            {
                dist[v] = c + d;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    long long n, m;
    cin >> n >> m;

    for (long long i = 1; i <= m; i++)
    {
        long long a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
    }
    dijkstra();
    for (long long i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}

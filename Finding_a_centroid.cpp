#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int n;               // number of nodes
vector<int> g[maxn]; // graph
int s[maxn];         // size of subtree

void dfs_size(int cur, int par)
{
    s[cur] = 1;
    for (int chi : g[cur])
    {
        if (chi != par)
        {
            dfs_size(chi, cur);
            s[cur] += s[chi];
        }
    }
}

int get_centroid(int cur, int par)
{
    for (int chi : g[cur])
    {
        if (chi != par)
        {
            if (s[chi] * 2 > n)
            {
                return get_centroid(chi, cur);
            }
        }
    }
    return cur;
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs_size(1, -1);
    int centroid = get_centroid(1, -1);
    cout << centroid << '\n';
}
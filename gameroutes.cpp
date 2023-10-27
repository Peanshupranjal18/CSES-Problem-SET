#include <bits/stdc++.h>
#define intt long long int
#define MOD 1000000007 // Corrected MOD value

using namespace std;

vector<vector<intt>> adj(200001);

vector<intt> topo_sort(intt freq[], intt n)
{
    queue<intt> q;

    for (intt i = 1; i <= n; i++)
    {
        if (freq[i] == 0)
        {
            q.push(i);
        }
    }

    vector<intt> ans;

    while (!q.empty())
    {
        intt u = q.front();
        q.pop();

        ans.push_back(u);

        for (auto it : adj[u])
        {
            freq[it]--;
            if (freq[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return ans;
}

intt solve(intt source, intt dest, vector<intt> &topo, intt n)
{
    intt dp[n + 1] = {0}; // Corrected array size
    dp[dest] = 1;
    for (intt i = topo.size() - 1; i >= 0; i--)
    {
        for (intt j = 0; j < adj[topo[i]].size(); j++)
        {
            dp[topo[i]] = (dp[topo[i]] + dp[adj[topo[i]][j]]) % MOD; // Update dp value
        }
    }
    return dp[source];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    intt n, m, a, b;
    cin >> n >> m;
    intt freq[n + 1] = {0}; // Initialize freq array
    for (intt i = 1; i <= m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        freq[b]++;
    }
    vector<intt> topo = topo_sort(freq, n);
    intt ans = solve(1, n, topo, n);
    cout << ans << "\n"; // Print the answer
    return 0;
}

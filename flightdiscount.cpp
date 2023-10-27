// method 1 modification in dijkstra algorithm

/*Alternatively, we can run Dijkstra's and modify our distance array slightly to
track whether the discount has been used or not.

$\texttt{dist}[i][\texttt{false}]$ will represent the shortest distance from the start node
to node $i$, without using the discount. $\texttt{dist}[i][\texttt{true}]$ will represent
the shortest distance after using the discount.*/

// #include <iostream>
// #include <queue>
// #include <vector>

// using std::cout;
// using std::endl;
// using std::vector;

// int main()
// {
//     int city_num;
//     int flight_num;
//     std::cin >> city_num >> flight_num;
//     vector<vector<std::pair<int, int>>> neighbors(city_num);
//     for (int f = 0; f < flight_num; f++)
//     {
//         int from;
//         int to;
//         int cost;
//         std::cin >> from >> to >> cost;
//         neighbors[--from].push_back({--to, cost});
//     }

//     vector<vector<long long>> min_cost(city_num, {INT64_MAX, INT64_MAX});
//     min_cost[0] = {0, 0};

//     struct Pos
//     {
//         int pos;        // the current position
//         bool used;      // whether we've used up our discount yet
//         long long cost; // the cost associated with this state
//     };
//     auto cmp = [&](const Pos &a, const Pos &b)
//     { return a.cost > b.cost; };
//     std::priority_queue<Pos, vector<Pos>, decltype(cmp)> frontier(cmp);
//     frontier.push({0, false, 0});

//     while (!frontier.empty())
//     {
//         Pos curr = frontier.top();
//         frontier.pop();
//         long long curr_cost = min_cost[curr.pos][curr.used];
//         if (curr_cost != curr.cost)
//         {
//             continue;
//         }
//         if (curr.pos == city_num - 1)
//         {
//             break;
//         }
//         for (auto [n, nc] : neighbors[curr.pos])
//         {
//             // if we haven't used the discount yet, try using it now
//             if (!curr.used)
//             {
//                 long long new_cost = curr_cost + nc / 2;
//                 if (new_cost < min_cost[n][true])
//                 {
//                     min_cost[n][true] = new_cost;
//                     frontier.push(Pos{n, true, new_cost});
//                 }
//             }
//             // but we can always just try the normal cost route
//             if (curr_cost + nc < min_cost[n][curr.used])
//             {
//                 min_cost[n][curr.used] = curr_cost + nc;
//                 frontier.push(Pos{n, curr.used, curr_cost + nc});
//             }
//         }
//     }
//     cout << min_cost[city_num - 1][1];
// }

// // method 2

// /*Say we use the discount coupon on the edge between cities A and B.

// There are two cases: we can go from $1\rightarrow A\rightarrow B\rightarrow N$,
// or $1\rightarrow B\rightarrow A\rightarrow N$. We need to know the distance
// between $1$ and $A$, and $N$ and $B$.

// We can use Dijkstra's to compute the distance from $1$ and $N$ to every vertex.
// Then our answer is
// $\min\limits_{A\rightarrow B} \texttt{dist1}[A]+c(A,B)+\texttt{distN}[B]$, where
// $c(A,B)$ is the cost to travel from city $A$ to city $B$ after applying the
// coupon to that flight, $\texttt{dist1}[A]$ is the cost to travel from city $1$
// to city $A$ and $\texttt{distN}[B]$ is the cost to travel from city $B$ to city
// $N$.*/

// #include <iostream>
// #include <queue>
// #include <vector>

// using std::cout;
// using std::endl;
// using std::pair;
// using std::vector;

// /**
//  * given a start point, and an adjacency list with costs,
//  * this function gives an array with the minimum distances
//  * from all the other nodes to the start node
//  * (the value is INT64_MAX if unreachable)
//  */
// vector<long long> min_costs(int from,
//                             const vector<vector<pair<int, int>>> &neighbors)
// {
//     vector<long long> min_costs(neighbors.size(), INT64_MAX);
//     min_costs[from] = 0;
//     std::priority_queue<pair<long long, int>> frontier;
//     frontier.push({0, from});
//     while (!frontier.empty())
//     {
//         pair<long long, int> curr_state = frontier.top();
//         frontier.pop();
//         int curr = curr_state.second;
//         if (-curr_state.first != min_costs[curr])
//         {
//             continue;
//         }

//         for (auto [n, nc] : neighbors[curr])
//         {
//             long long new_cost = min_costs[curr] + nc;
//             if (new_cost < min_costs[n])
//             {
//                 min_costs[n] = new_cost;
//                 frontier.push({-new_cost, n});
//             }
//         }
//     }
//     return min_costs;
// }

// int main()
// {
//     int city_num;
//     int flight_num;
//     std::cin >> city_num >> flight_num;
//     vector<vector<pair<int, int>>> neighbors(city_num);
//     vector<vector<pair<int, int>>> reverse_neighbors(city_num);
//     for (int f = 0; f < flight_num; f++)
//     {
//         int from;
//         int to;
//         int cost;
//         std::cin >> from >> to >> cost;
//         neighbors[--from].push_back({--to, cost});
//         reverse_neighbors[to].push_back({from, cost});
//     }

//     vector<long long> start_costs = min_costs(0, neighbors);
//     vector<long long> end_costs = min_costs(city_num - 1, reverse_neighbors);
//     long long total_min = INT64_MAX;
//     for (int c = 0; c < city_num; c++)
//     {
//         for (auto [n, nc] : neighbors[c])
//         {
//             if (start_costs[c] == INT64_MAX || end_costs[n] == INT64_MAX)
//             {
//                 continue;
//             }
//             total_min =
//                 std::min(total_min, start_costs[c] + (nc / 2) + end_costs[n]);
//         }
//     }
//     cout << total_min << endl;
// }

#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define int long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define inf 1e17

int vis[100005];
int dis1[100005], dis2[100005];
void dij(int s, int dis[], vector<pair<int, int>> adj[])
{
    priority_queue<pair<int, int>> q;
    rep(i, 100005) dis[i + 1] = inf;
    dis[s] = 0;
    q.push({0, s});
    memset(vis, 0, sizeof vis);
    while (!q.empty())
    {
        int x = q.top().ss;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto [y, z] : adj[x])
        {
            if (dis[x] + z < dis[y])
            {
                dis[y] = dis[x] + z;
                q.push({-dis[y], y});
            }
        }
    }
}

int32_t main()
{
    fast int t = 1;
    // cin>>t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> adj1[n + 1], adj2[n + 1];
        vector<tuple<int, int, int>> e;
        rep(i, m)
        {
            int x, y, z;
            cin >> x >> y >> z;
            e.pb({x, y, z});
            adj1[x].pb({y, z});
            adj2[y].pb({x, z});
        }
        dij(1, dis1, adj1);
        dij(n, dis2, adj2);
        int ans = inf;
        for (auto [x, y, z] : e)
        {
            ans = min(ans, dis1[x] + dis2[y] + z / 2);
        }
        cout << ans << endl;
    }
    return 0;
}
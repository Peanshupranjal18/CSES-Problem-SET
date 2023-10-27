// brute force

// #include <bits/stdc++.h>
// #define intt long long int
// #define ll long long
// #define ld long double
// #define MOD 1000000007
// #define f(i, n) for (intt i = 0; i < n; i++)
// #define ff(i, a, b) for (intt i = a; i < b; i++)
// #define pb push_back
// #define ii pair<intt, intt>
// #define vi vector<intt>
// #define vvi vector<vector<intt>>
// #define vpi vector<pair<intt, intt>>
// #define fi first
// #define sec second
// #define all(x) x.begin(), x.end()
// #define allr(x) x.rbegin(), x.rend()
// #define minv *min_element
// #define maxv *max_element
// #define rt return
// #define um unordered_map
// #define acc accumulate
// #define sz(x) x.size()
// #define ub upper_bound
// #define lb lower_bound
// using namespace std;

// // Right Left Up Down
// intt dx[] = {0, 0, 1, -1};
// intt dy[] = {1, -1, 0, 0};
// intt n, m;
// vi adj[200001];

// bool possible(int x, int y)
// {
//     return (x < n && x >= 0 && y < m && y >= 0);
// }

// bool isPrime(intt n)
// {
//     if (n <= 1)
//         return false;
//     if (n == 2 || n == 3)
//         return true;
//     if (n % 2 == 0 || n % 3 == 0)
//         return false;
//     for (intt i = 5; i <= sqrt(n); i = i + 6)
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     return true;
// }

// ii bfs(intt src)
// {
//     queue<ii> q;
//     q.push({src, 0});

//     vi vis(200001, 0);

//     ii u;

//     while (!q.empty())
//     {
//         u = q.front();
//         vis[u.fi] = 1;
//         q.pop();

//         for (auto it : adj[u.fi])
//         {
//             if (!vis[it])
//                 q.push({it, u.sec + 1});
//         }
//     }

//     return u;
// }

// void solve()
// {
//     cin >> n;
//     ff(i, 1, n)
//     {
//         intt a, b;
//         cin >> a >> b;
//         adj[a].pb(b);
//         adj[b].pb(a);
//     }
//     vi ans;
//     ff(i, 1, n + 1)
//     {
//         ii x = bfs(i);
//         ans.pb(x.sec);
//     }
//     f(i, sz(ans)) cout << ans[i] << " ";
// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     // intt tc;
//     // cin >> tc;
//     // while (tc--)
//     solve();
//     return 0;
// }

// max_distance[u] = max(distance_from_diametric_end1[u], distance_from_diametric_end2[u])

// correct solution

#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1000000007
#define f(i, n) for (intt i = 0; i < n; i++)
#define ff(i, a, b) for (intt i = a; i < b; i++)
#define pb push_back
#define ii pair<intt, intt>
#define vi vector<intt>
#define vvi vector<vector<intt>>
#define vpi vector<pair<intt, intt>>
#define fi first
#define sec second
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define minv *min_element
#define maxv *max_element
#define rt return
#define um unordered_map
#define acc accumulate
#define sz(x) x.size()
#define ub upper_bound
#define lb lower_bound
using namespace std;

// Right Left Up Down
intt dx[] = {0, 0, 1, -1};
intt dy[] = {1, -1, 0, 0};
intt n, m, a, b;
vi adj[200001];
vi ans(200001, -1);

bool possible(int x, int y)
{
    return (x < n && x >= 0 && y < m && y >= 0);
}

bool isPrime(intt n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (intt i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

intt bfs(intt src)
{
    intt top;
    queue<intt> q;
    vi d(n + 1, -1);

    d[src] = 0;

    ans[src] = max(ans[src], d[src]);

    q.push(src);

    while (!q.empty())
    {
        top = q.front();
        q.pop();

        for (auto v : adj[top])
        {
            if (d[v] == -1)
            {
                q.push(v);
                d[v] = d[top] + 1;
                ans[v] = max(ans[v], d[v]);
            }
        }
    }

    return top;
}

void solve()
{
    cin >> n;
    ff(i, 1, n)
    {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    intt dia1 = bfs(1);
    intt dia2 = bfs(dia1);
    bfs(dia2);

    ff(i, 1, n + 1)
    {
        cout << ans[i] << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // intt tc;
    // cin >> tc;
    // while (tc--)
    solve();
    return 0;
}
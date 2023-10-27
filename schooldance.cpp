// #include <bits/stdc++.h>
// #define intt long long int
// #define ll long long
// #define ld long double
// #define MOD 1000000007
// #define f(i,n) for(intt i=0;i<n;i++)
// #define ff(i,a,b) for(intt i=a;i<b;i++)
// #define pb push_back
// #define vi vector<intt>
// #define vii vector<vector<intt>>
// #define vpi vector<pair<intt,intt>>
// #define fi first
// #define sec second
// #define all(x) x.begin(),x.end()
// #define allr(x) x.rbegin(),x.rend()
// #define rt return
// #define um unordered_map
// #define acc accumulate
// using namespace std;

// bool isPrime(intt n)
// {
// if (n <= 1)
// return false;
// if (n == 2 || n == 3)
// return true;
// if (n % 2 == 0 || n % 3 == 0)
// return false;
// for (intt i = 5; i <= sqrt(n); i = i + 6)
// if (n % i == 0 || n % (i + 2) == 0)
// return false;
// return true;
// }

// void swap(vector<intt>& arr, intt i, intt j)
// {
// intt temp = arr[i];
// arr[i] = arr[j];
// arr[j] = temp;
// }

// intt minSwaps(vector<intt> arr, intt N)
// {
// intt ans = 0;
// vector<intt> temp = arr;
// map<intt, intt> h;
// sort(temp.begin(), temp.end());
// for (intt i = 0; i < N; i++)
// {
// h[arr[i]] = i;
// }
// for (intt i = 0; i < N; i++)
// {
// if (arr[i] != temp[i])
// {
// ans++;
// intt init = arr[i];
// swap(arr, i, h[temp[i]]);
// h[init] = h[temp[i]];
// h[temp[i]] = i;
// }
// }
// return ans;
// }

// this is a problem of finding the maximum matching recommended reading material: https://cses.fi/book/book.pdf#page=197

// void solve(){
//     intt n,m,k;
//     cin>>n>>m>>k;

// }

// int32_t main()
// {
// ios_base::sync_with_stdio(false);
// cin.tie(0);
// cout.tie(0);
// //intt tc;cin>>tc;while(tc--)
// solve();
// return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
bool dfs(ll node, ll dest, vector<vector<ll>> &adj, vector<ll> &path, ll threshhold, vector<ll> &vis, ll n)
{
    vis[node] = 1;
    if (node == dest)
    {
        path.push_back(node);
        return true;
    }
    for (ll i = 0; i <= n; i++)
    {
        if (adj[node][i] == -1)
            continue;
        if (vis[i])
            continue;
        if (adj[node][i] < threshhold)
        {
            continue;
        }
        if (dfs(i, dest, adj, path, threshhold, vis, n))
        {
            path.push_back(node);
            return true;
        }
    }
    return false;
}
void dfs2(ll node, vector<vector<ll>> &og, vector<ll> &left, vector<ll> &visited, ll n)
{
    visited[node] = 1;
    left.push_back(node);
    for (ll i = 0; i <= n; i++)
    {
        if (visited[i])
            continue;
        // if (og[node][i] == -1)
        //     continue;
        // if (og[node][i] == 0)
        //     continue;
        if (og[node][i] <= 0)
            continue;
        dfs2(i, og, left, visited, n);
    }
}
int main()
{
    fastio;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> adj(n + m + 2, vector<ll>(n + m + 2, -1));
    vector<vector<ll>> og(n + m + 2, vector<ll>(n + m + 2, -1));
    ll sum = 0;
    for (ll i = 0; i < k; i++)
    {
        ll x, y;
        ll w = 1;
        cin >> x >> y;
        y += n;
        // y += 500;
        og[x][y] = w;
        // og[y][x] = w;
        // og[y][x] = w;
        if (adj[x][y] == -1)
        {
            adj[x][y] = 0;
            // adj[y][x] = 0;
        }
        adj[x][y] = w;
        adj[y][x] = 0;
        sum += w;
    }
    for (ll i = 1; i <= n; i++)
    {
        adj[0][i] = 1;
        og[0][i] = 1;
    }
    for (ll i = n + 1; i <= n + m; i++)
    {
        adj[i][n + m + 1] = 1;
        og[i][n + m + 1] = 1;
    }
    ll ans = 0;
    while (sum > 0)
    {
        vector<ll> path;
        vector<ll> vis(n + m + 2, 0);
        bool f = dfs(0, n + m + 1, adj, path, sum, vis, n + m + 1);
        if (f == true)
        {
            reverse(path.begin(), path.end());
            ll z = path.size();
            ll minedgewt = LLONG_MAX;
            for (ll i = 0; i < z - 1; i++)
            {
                minedgewt = min(minedgewt, adj[path[i]][path[i + 1]]);
            }
            ans += minedgewt;
            for (ll i = 0; i < z - 1; i++)
            {
                adj[path[i]][path[i + 1]] -= minedgewt;
                adj[path[i + 1]][path[i]] += minedgewt;
            }
        }
        else
            sum /= 2;
    }
    // for (ll i = 0; i <= n + m + 1; i++)
    // {
    //     for (ll j = 0; j <= n + m + 1; j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << ans << "\n";
    vector<ll> left;
    // vector<ll> visited(n + m + 2, 0);
    // dfs2(0, adj, left, visited, n + m + 1);
    for (ll i = 1; i <= n; i++)
    {
        left.push_back(i);
    }
    unordered_set<ll> st;
    for (auto &i : left)
    {
        st.insert(i);
    }
    for (auto &i : left)
    {
        for (ll j = n + 1; j <= n + m; j++)
        {
            if (((og[i][j] == 1) && (adj[i][j] == 0)))
            {
                cout << i << " " << j - n << "\n";
            }
        }
    }
}
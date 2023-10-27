// #include <bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define fr(a, b) for (int i = a; i < b; i++)
// #define rep(i, a, b) for (int i = a; i < b; i++)
// #define mod 1000000007
// #define inf (1LL << 60)
// #define all(x) (x).begin(), (x).end()
// #define prDouble(x) cout << fixed << setprecision(10) << x
// #define triplet pair<ll, pair<ll, ll>>
// #define fast_io                       \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL)
// using namespace std;

// vector<int> tree[200001];
// int dp[200001][2];

// void solve(int src, int par)
// {
//     vector<int> prefix, suffix;
//     dp[src][0] = dp[src][1] = 0;

//     bool leaf = 1;
//     for (int child : tree[src])
//     {
//         if (child != par)
//         {
//             leaf = 0;
//             solve(child, src);
//         }
//     }

//     if (leaf)
//         return;
//     for (int child : tree[src])
//     {
//         if (child != par)
//         {
//             prefix.push_back(max(dp[child][0], dp[child][1]));
//             suffix.push_back(max(dp[child][0], dp[child][1]));
//         }
//     }

//     fr(1, (int)prefix.size())
//         prefix[i] += prefix[i - 1];
//     for (int i = (int)suffix.size() - 2; i >= 0; i--)
//         suffix[i] += suffix[i + 1];

//     dp[src][0] = suffix[0];
//     int c_no = 0;
//     for (int child : tree[src])
//     {
//         if (child == par)
//             continue;

//         int leftChildren = (c_no == 0) ? 0 : prefix[c_no - 1];
//         int rightChildren = (c_no == (int)suffix.size() - 1) ? 0 : suffix[c_no + 1];

//         dp[src][1] = max(dp[src][1], 1 + leftChildren + rightChildren + dp[child][0]);
//         c_no++;
//     }
// }

// int main()
// {
//     fast_io;
//     ll t, n, m, x, i, j, k, q;
//     // cin >> t;
//     t = 1;
//     while (t--)
//     {
//         cin >> n;
//         vector<int> ans(n + 1);
//         fr(2, n + 1)
//         {
//             int u, v;
//             cin >> u >> v;
//             tree[u].push_back(v);
//             tree[v].push_back(u);
//         }
//         solve(1, 0);
//         cout << max(dp[1][0], dp[1][1]);
//     }
//     return 0;
// }

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
// intt dp[200001][2];

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

// intt tree_matching(intt vertex, bool isIncluded, vvi &v, intt par)
// {
//     if (dp[vertex][isIncluded] != 1)
//         return dp[vertex][isIncluded];

//     if (isIncluded)
//     {
//         intt ans = 0;
//         for (intt neig : v[vertex])
//         {
//             if (neig != par)
//             {
//                 ans += tree_matching(neig, 1, v, vertex);
//             }
//         }
//         intt myres = 0;
//         for (intt neig : v[vertex])
//         {
//             if (neig != par)
//             {
//                 myres = max(myres, ans - dp[neig][1] + 1 + tree_matching(neig, 0, v, vertex));
//             }
//         }
//         dp[vertex][isIncluded] = myres;
//         return myres;
//     }
//     else
//     {
//         intt ans = 0;
//         for (intt neig : v[vertex])
//         {
//             if (neig != par)
//             {
//                 intt a = tree_matching(neig, 1, v, vertex);
//                 ans += max(a, tree_matching(neig, 0, v, vertex));
//             }
//         }
//         dp[vertex][isIncluded] = ans;
//         return ans;
//     }
// }

// void solve()
// {
//     cin >> n;
//     intt temp = n - 1;
//     memset(dp, -1, sizeof(dp));
//     vvi v(n + 1);
//     while (temp > 0)
//     {
//         intt a, b;
//         cin >> a >> b;
//         v[a].pb(b);
//         v[b].pb(a);
//         temp--;
//     }
//     intt ans = max(tree_matching(0, 0, v, -1), tree_matching(1, 1, v, -1));
//     cout << ans;
// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     // intt tc;cin>>tc;while(tc--)
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
void setIO(string name = "")
{ // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0); // see Fast Input & Output
    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin); // see Input & Output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vi adj[200005];
int dp[200005][2];

void dfs(int v, int p)
{
    for (int to : adj[v])
    {
        if (to != p)
        {
            dfs(to, v);
            dp[v][0] += max(dp[to][0], dp[to][1]);
        }
    }
    for (int to : adj[v])
    {
        if (to != p)
        {
            dp[v][1] = max(dp[v][1], dp[to][0] + 1 + dp[v][0] -
                                         max(dp[to][0], dp[to][1]));
        }
    }
}

int main()
{
    setIO();
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << '\n';
}
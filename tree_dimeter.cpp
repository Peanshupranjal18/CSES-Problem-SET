// run two bfs to obtain the answer
// running the bfs will definetely take us to the diametrically end

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
intt n, m;
vi v[200001];

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

ii bfs(intt src)
{
    queue<ii> q;
    q.push({src, 0});

    vi vis(200001, 0);

    ii u;

    while (!q.empty())
    {
        u = q.front();
        vis[u.fi] = 1;
        q.pop();

        for (auto it : v[u.fi])
        {
            if (!vis[it])
                q.push({it, u.sec + 1});
        }
    }

    return u;
}

void solve()
{
    cin >> n;
    ff(i, 1, n)
    {
        intt a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    ii end1 = bfs(1);
    ii end2 = bfs(end1.fi);
    cout << end2.sec;
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
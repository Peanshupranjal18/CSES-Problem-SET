#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1000000007
#define f(i, n) for (intt i = 0; i < n; i++)
#define ff(i, a, b) for (intt i = a; i < b; i++)
#define pb push_back
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

const int MAXN = 200001;
intt n, m;
vector<int> adj[MAXN];
vector<int> vis(MAXN, 0);

// Up Left Down Right
intt dx[] = {-1, 0, +1, 0};
intt dy[] = {0, -1, 0, +1};

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

void dfs(int x)
{
	vis[x] = 1;
	for (auto it : adj[x])
	{
		if (!vis[it])
			dfs(it);
	}
}

void solve()
{
	cin >> n >> m;
	f(i, m)
	{
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vi l;
	ff(i, 1, n + 1)
	{
		if (vis[i] == 0)
		{
			l.pb(i);
			dfs(i);
		}
	}
	if (sz(l) == 1)
	{
		cout << 0;
		rt;
	}
	cout << sz(l) - 1 << "\n";
	f(i, sz(l) - 1) cout << l[i] << " " << l[i + 1] << "\n";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// intt tc;cin>>tc;while(tc--)
	solve();
	return 0;
}

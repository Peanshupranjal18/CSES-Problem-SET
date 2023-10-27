// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// #define int long long int

// int n, m;
// vector<vector<int>> g;
// vector<int> par;
// vector<bool> vis;

// void bfs()
// {
// 	vis[1] = true;
// 	queue<int> q;
// 	q.push(1);
// 	while(!q.empty())
// 	{
// 		int u = q.front();
// 		q.pop();
// 		for(auto v: g[u])
// 		{
// 			if(!vis[v])
// 			{
// 				vis[v] = true;
// 				par[v] = u;
// 				q.push(v);
// 			}
// 		}
// 	}
// }

// int32_t main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cin >> n >> m;
// 	g.resize(n+1);
// 	vis.resize(n+1);
// 	par.resize(n+1);
// 	for(int i = 0; i<=n; ++i)
// 	{
// 		par[i] = -1;
// 	}
// 	for(int i = 0; i < m; ++i)
// 	{
// 		int u, v;
// 		cin >> u >> v;
// 		g[u].push_back(v);
// 		g[v].push_back(u);
// 	}
// 	bfs();

// 	if(par[n] == -1)
// 	{
// 		cout <<  "IMPOSSIBLE";
// 		return 0;
// 	}

// 	int candidate = n;
// 	stack<int> stk;
// 	while(candidate != -1)
// 	{
// 		stk.push(candidate);
// 		candidate = par[candidate];
// 	}

// 	cout << stk.size() << endl;

// 	while(!stk.empty())
// 	{
// 		cout << stk.top() << " ";
// 		stk.pop();
// 	}

//  }

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

void solve()
{
	cin >> n >> m;
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
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

bool isPrime(intt n)
{
	if (n <= 1)
		return false;
	if (n == 2 || n == 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;
	for (intt i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}

void dfs(vvi &vis, vector<vector<char>> &v, intt i, intt j)
{
	vis[i][j] = 1;
	intt dx[] = {-1, 0, 1, 0};
	intt dy[] = {0, -1, 0, 1};

	for (intt k = 0; k < 4; k++)
	{
		intt newx = i + dx[k];
		intt newy = j + dy[k];
		if (newx >= 0 && newx < v.size() && newy >= 0 && newy < v[0].size() && vis[newx][newy] == -1 && v[newx][newy] == '.')
			dfs(vis, v, newx, newy);
	}
}

void solve()
{
	intt n, m;
	cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m));
	vvi vis(n, vi(m, -1));
	intt ans = 0;
	f(i, n)
	{
		f(j, m) cin >> v[i][j];
	}
	f(i, n)
	{
		f(j, m)
		{
			if (v[i][j] == '.' && vis[i][j] == -1)
			{
				dfs(vis, v, i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;
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

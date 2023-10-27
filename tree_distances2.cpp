// #include<bits/stdc++.h>
// #define REP(i,n) for (int i = 1; i <= n; i++)
// #define mod 1000000007
// #define pb push_back
// #define ff first
// #define ss second
// #define ii pair<int,int>
// #define vi vector<int>
// #define vii vector<ii>
// #define lli long long int
// #define INF 1000000000
// #define endl '\n'
// const double PI = 3.141592653589793238460;
// typedef std::complex<double> Complex;
// typedef std::valarray<Complex> CArray;
// using namespace std;

// vi ar[200001];
// lli res[200001];
// int subSize[200001];
// lli subDist[200001];
// int n;

// void dfs1(int node , int par)
// {
// 	subSize[node] = 1;

// 	for(int child : ar[node])
// 	if(child != par)
// 	{
// 		dfs1(child , node);
// 		subSize[node] += subSize[child];

// 		subDist[node] += subSize[child] + subDist[child];
// 	}
// }

// void dfs(int node , int par)
// {
// 	res[node] = res[par] - subSize[node] - subDist[node] + n - subSize[node] + subDist[node];

// 	for(int child : ar[node])
// 	if(child != par)
// 	dfs(child , node);
// }

// int main()
// {
// 	int a , b;
// 	cin>>n;
// 	REP(i , n-1) cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);

// 	dfs1(1 , -1);
// 	res[1] = subDist[1];

// 	for(int child : ar[1])
// 	dfs(child , 1);

// 	REP(i , n) cout<<res[i]<<" ";
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
vector<int> graph[200001];
ll dp[200001], ans[200001];

void dfs1(int node = 1, int parent = 0, ll depth = 0)
{
    ans[1] += depth;
    dp[node] = 1;
    for (int i : graph[node])
        if (i != parent)
        {
            dfs1(i, node, depth + 1);
            dp[node] += dp[i];
        }
}

void dfs2(int node = 1, int parent = 0)
{
    for (int i : graph[node])
        if (i != parent)
        {
            ans[i] = ans[node] + n - 2 * dp[i];
            dfs2(i, node);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs1();
    dfs2();
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}
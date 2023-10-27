#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1000000007
#define f(i, n) for (intt i = 0; i < n; i++)
#define ff(i, a, b) for (intt i = a; i < b; i++)
#define pb push_back
#define vi vector<intt>
#define vii vector<vector<intt>>
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
using namespace std;

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
    intt n, m, k;
    cin >> n >> m >> k;
    vi v(n);
    f(i, n) cin >> v[i];
    vi v1(m);
    f(i, m) cin >> v1[i];
    sort(all(v));
    sort(all(v1));
    intt l = 0;
    intt r = 0;
    intt ans = 0;
    while (r < m and l < n)
    {
        intt x = v[l] - v1[r];
        if (-k <= x and x <= k)
        {
            ans++;
            l++;
            r++;
        }
        else if (-k > x)
        {
            l++;
        }
        else
        {
            r++;
        }
    }
    cout << ans;
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
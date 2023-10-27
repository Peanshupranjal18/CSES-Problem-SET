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
    intt a, b;
    cin >> a >> b;
    intt res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    cout << res << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    intt tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
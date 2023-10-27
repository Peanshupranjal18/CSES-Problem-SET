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
#define ub upper_bound
#define lb lower_bound
#define p pair<intt, intt>
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

bool help(const p a, const p b)
{
    return a.sec < b.sec;
}

void solve()
{
    intt n;
    cin >> n;
    vpi v(n);
    f(i, n)
    {
        intt x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }
    sort(all(v), help);
    intt ans = 1;
    intt r1 = v[0].sec;
    ff(i, 1, n)
    {
        intt l1 = v[i].fi;
        intt r2 = v[i].sec;
        if (l1 >= r1)
        {
            ans++;
            r1 = r2;
        }
    }
    cout << ans;
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
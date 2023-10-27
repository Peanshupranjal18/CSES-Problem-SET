// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<pair<int, int>> times;
//     for (int i = 0; i < n; i++)
//     {
//         int start, end;
//         cin >> start >> end;
//         times.push_back({start, 1});
//         times.push_back({end + 1, -1});
//     }

//     sort(times.begin(), times.end());

//     int curr = 0;
//     int at = 0;
//     // Stores how much the # of people in the restaurant changes each time step
//     vector<int> ppl_change(2 * n);
//     // Compress the starting & ending events into a single array
//     for (int i = 0; i < 2 * n; i++)
//     {
//         if (i == 0)
//         {
//             times[i].first = 0;
//         }
//         else if (times[i].first > curr)
//         {
//             at++;
//             curr = times[i].first;
//         }
//         ppl_change[at + 1] += times[i].second;
//     }

//     // Build our prefix sum array
//     vector<int> ppl_amt(2 * n + 1);
//     for (int i = 1; i < 2 * n + 1; i++)
//     {
//         ppl_amt[i] = ppl_change[i - 1] + ppl_amt[i - 1];
//     }

//     // Our answer is just the maximum of the prefix sum array
//     int max_ppl = 0;
//     for (int i = 0; i < 2 * n + 1; i++)
//     {
//         max_ppl = max(max_ppl, ppl_amt[i]);
//     }

//     cout << max_ppl << endl;
// }

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
#define mt multiset
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
    cin >> n;
    vpi v(n);
    f(i, n)
    {
        intt a, b;
        cin >> a >> b;
        v.pb({a, 1});
        v.pb({b, -1});
    }
    sort(all(v));
    intt curr = 0;
    intt maxi = 0;

    f(i, sz(v))
    {
        curr += v[i].sec;
        maxi = max(maxi, curr);
    }
    cout << maxi;
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
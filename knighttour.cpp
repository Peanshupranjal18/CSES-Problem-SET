// warnsdorff rule
// knight's tour problem can also be solved by backtracking algorithm

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
#define rt return
#define um unordered_map
#define acc accumulate
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

void swap(vector<intt> &arr, intt i, intt j)
{
    intt temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

intt minSwaps(vector<intt> arr, intt N)
{
    intt ans = 0;
    vector<intt> temp = arr;
    map<intt, intt> h;
    sort(temp.begin(), temp.end());
    for (intt i = 0; i < N; i++)
    {
        h[arr[i]] = i;
    }
    for (intt i = 0; i < N; i++)
    {
        if (arr[i] != temp[i])
        {
            ans++;
            intt init = arr[i];
            swap(arr, i, h[temp[i]]);
            h[init] = h[temp[i]];
            h[temp[i]] = i;
        }
    }
    return ans;
}

void solve()
{
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
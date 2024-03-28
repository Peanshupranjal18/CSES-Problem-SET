#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
using namespace std;
template <typename T>
using bstring = basic_string<T>;
template <typename T>
using matrix = vector<vector<T>>;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INFL = (1LL << 62) - 1;
const int INF = (1 << 30) - 1;
const double EPS = 1e-7;
const int MOD = 1e9 + 7;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
const int MAXN = 11, MAXM = 1001;

ll dp[MAXM][MAXN][1 << MAXN];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    dp[0][n][0] = 1; // initially it's like the "0th" column is filled but nothing is sticking into the 1st column

    for (int i = 1; i <= m; i++)
    {

        for (int mask = 0; mask < (1 << n); mask++)
            dp[i][0][mask] = dp[i - 1][n][mask]; // unformed part of ith column is the formed part of the (i-1)th column

        for (int j = 1; j <= n; j++)
        {
            for (int mask = 0; mask < (1 << n); mask++)
            {

                bool use = (1 << j - 1) & mask;

                if (use)
                {
                    dp[i][j][mask] += dp[i][j - 1][mask - (1 << j - 1)]; // placing a horizontal tile on an empty place
                }
                else
                {
                    dp[i][j][mask] += dp[i][j - 1][mask + (1 << j - 1)]; // not placing anything on a filled place
                    if (j > 1 && !((1 << j - 2) & mask))
                        dp[i][j][mask] += dp[i][j - 2][mask]; // placing a vertical tile on 2 empty spaces
                }

                dp[i][j][mask] %= MOD;
            }
        }
    }

    cout << dp[m][n][0] << '\n'; // the answer is filling the first m columns with nothing sticking out

    return 0;
}
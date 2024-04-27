// We do something like brute force here. Consider a robot on a single cell only, assuming all others don’t have robot present.
// Here dp[k][i][j]
//  represents the expected probability of a robot to be present in cell (i,j)
//  after k
//  steps.
// The state transition would be dp[k+1][i+dr[f]][j+dc[f]]+=dp[k][i][j]totaldirections
// , where dr[4]
//  and dc[4]
//  iterates over the 4
//  possible directions.
// The expected answer for each individual cell (i,j)
//  would be the product of (1−dp[n][i][j])
// .
// Adding all the expected values for a single cell gives us our final answer.
// Time complexity is O(84n)
// .

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll dr[4] = {1, -1, 0, 0};
ll dc[4] = {0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ld dp[n + 1][8][8] = {};
    ld ans[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            ans[i][j] = 1;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                for (int i1 = 0; i1 < 8; i1++)
                {
                    for (int j1 = 0; j1 < 8; j1++)
                    {
                        dp[k][i1][j1] = 0;
                    }
                }
            }
            dp[0][i][j] = 1;
            for (int k = 0; k < n; k++)
            {
                for (int i1 = 0; i1 < 8; i1++)
                {
                    for (int j1 = 0; j1 < 8; j1++)
                    {
                        ld dir = 0;
                        for (int f = 0; f < 4; f++)
                        {
                            ll u = i1 + dr[f], v = j1 + dc[f];
                            if (u >= 0 && u < 8 && v >= 0 && v < 8)
                            {
                                dir++;
                            }
                        }
                        for (int f = 0; f < 4; f++)
                        {
                            ll u = i1 + dr[f], v = j1 + dc[f];
                            if (u >= 0 && u < 8 && v >= 0 && v < 8)
                            {
                                dp[k + 1][u][v] += dp[k][i1][j1] / dir;
                            }
                        }
                    }
                }
            }
            for (int i1 = 0; i1 < 8; i1++)
            {
                for (int j1 = 0; j1 < 8; j1++)
                {
                    ans[i1][j1] *= (1 - dp[n][i1][j1]);
                }
            }
        }
    }
    ld expc = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            expc += ans[i][j];
        }
    }
    cout << fixed << setprecision(6) << expc;
}
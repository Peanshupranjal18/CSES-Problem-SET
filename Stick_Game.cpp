// Let dp[i]
//  denote the result of game if there are total i
//  sticks. Here dp[i]
//  is true is first player wins, otherwise false.
// We know dp[0]
//  is false. The transition would be that if dp[i−p[j]]
//  is false where j=1,⋯,k
// , then dp[i]
//  would be true.
// Time complexity is O(nk)
// .

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    ll p[k];
    for (int i = 0; i < k; i++)
    {
        cin >> p[i];
    }
    ll dp[n + 1] = {};
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i - p[j] >= 0 && dp[i - p[j]] == 0)
            {
                dp[i] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 1)
            cout << "W";
        else
            cout << "L";
    }
}
#include <bits/stdc++.h>
using namespace std;
#define intt long long

void solve()
{
    intt n, sum;
    cin >> n >> sum;

    vector<intt> v(n);

    for (intt i = 0; i < n; i++)
        cin >> v[i];

    intt i = 0, j = 0, curr_sum = 0, cnt = 0;

    unordered_map<intt, intt> mp;

    mp[0] = 1;

    for (intt i = 0; i < n; i++)
    {
        curr_sum += v[i];

        /*
         * If there is a subarray with a prefix sum of prefix_sum - X,
         * we can exclude it from our current subarray to get the desired sum.
         * Thus, we can add the number of those subarrays to our answer.
         */

        cnt += mp[curr_sum - sum];
        mp[curr_sum]++;
    }

    cout << cnt << "\n";
    return;
}

signed main()
{
    solve();
    return 0;
}
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

    intt i = 0, j = 0, curr_sum = 0;
    intt cnt = 0;

    while (j < n)
    {
        curr_sum += v[j];
        if (curr_sum < sum)
        {
            j++;
            continue;
        }
        else
        {
            if (curr_sum == sum)
            {
                cnt++;
            }
            while (curr_sum >= sum)
            {
                curr_sum -= v[i];
                i++;
                if (curr_sum == sum)
                    cnt++;
            }
            j++;
        }
    }

    cout << cnt << "\n";
    return;
}

signed main()
{
    solve();
    return 0;
}

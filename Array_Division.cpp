#include <bits/stdc++.h>
using namespace std;

typedef long long int intt;

bool isValid(vector<intt> &v, intt n, intt k, intt sum)
{
    intt partitions = 1;
    intt runningSum = 0;

    for (intt i = 0; i < n; i++)
    {
        runningSum += v[i];
        if (runningSum > sum)
        {
            runningSum = v[i];
            partitions++;
        }
    }

    return partitions <= k;
}

void solve()
{
    intt n, k;
    cin >> n >> k;
    vector<intt> v(n);

    for (intt i = 0; i < n; i++)
        cin >> v[i];

    intt low = *max_element(v.begin(), v.end());
    intt high = accumulate(v.begin(), v.end(), 0LL);
    intt ans = 0;

    while (low <= high)
    {
        intt mid = low + (high - low) / 2;
        if (isValid(v, n, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
    return;
}

int main()
{
    solve();
    return 0;
}
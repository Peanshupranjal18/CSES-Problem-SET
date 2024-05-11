#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    long long n, x;
    cin >> n >> x;

    if (n < 4)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<pair<long long, long long>> v(n);
    for (long long i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[i] = {a, i};
    }

    sort(v.begin(), v.end());

    for (long long i = 0; i < n - 3; i++)
    {
        for (long long j = i + 1; j < n - 2; j++)
        {
            long long k = j + 1;
            long long l = n - 1;
            while (k < l)
            {
                long long sum = v[i].first + v[j].first + v[k].first + v[l].first;
                if (sum == x)
                {
                    cout << v[i].second + 1 << " " << v[j].second + 1 << " " << v[k].second + 1 << " " << v[l].second + 1 << endl;
                    return;
                }
                else if (sum > x)
                {
                    l--;
                }
                else
                {
                    k++;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    solve();
    return 0;
}
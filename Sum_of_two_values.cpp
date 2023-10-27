// #include <bits/stdc++.h>
// #define lli long long int
// #define li long int
// #define ld long double
// using namespace std;

// void solve()
// {
//     int n, target;
//     cin >> n >> target;
//     vector<pair<int, int>> v;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         v.push_back(make_pair(x, i + 1));
//     }
//     sort(v.begin(), v.end());
//     int i = 0;
//     int j = n - 1;
//     while (i < j)
//     {
//         if (v[i].first + v[j].first > target)
//         {
//             j--;
//         }
//         else if (v[i].first + v[j].first < target)
//         {
//             i++;
//         }
//         else if (v[i].first + v[j].first == target)
//         {
//             cout << v[i].second << " " << v[j].second << "\n";
//             return;
//         }
//     }
//     cout << "IMPOSSIBLE";
//     return;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    // use a map to avoid using a very large array
    map<int, int> val_to_ind;
    for (int i = 0; i < n; i++)
    {
        // target minus a number is the other number
        if (val_to_ind.count(x - values[i]))
        {
            cout << i + 1 << " " << val_to_ind[x - values[i]] << endl;
            return 0;
        }
        val_to_ind[values[i]] = i + 1;
    }

    cout << "IMPOSSIBLE" << endl;
}
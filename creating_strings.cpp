#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define MOD 1000000007
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    getline(cin, s);
    sort(s.begin(), s.end());

    vector<string> ans;
    //generating permutations
    do
    {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << ans.size() << "\n";
    for (auto x : ans)
    {
        cout << x << "\n";
    }
    return 0;
}
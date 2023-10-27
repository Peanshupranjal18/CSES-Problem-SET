// Difference array range update query in O(1)

#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1e9 + 7
using namespace std;

void initialise(vector<intt> &v, vector<intt> &diffArr)
{
    intt n = v.size();
    diffArr[0] = v[0];

    diffArr[0] = v[0];
    diffArr[n] = 0;

    for (intt i = 1; i < n; i++)
    {
        diffArr[i] = v[i] - v[i - 1];
    }
}

void update(intt l, intt r, vector<intt> &diffArr, intt x)
{
    diffArr[l] += x;
    diffArr[r + 1] -= x;
}

void print(vector<intt> &v, vector<intt> &diffArr, intt pos)
{
    for (intt i = 0; i < v.size(); i++)
    {
        if (i == 0)
        {
            v[i] = diffArr[i];
        }
        else
        {
            v[i] = diffArr[i] + v[i - 1];
        }
    }
    cout << v[pos] << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    intt n, q;
    cin >> n >> q;
    vector<intt> v(n);
    for (intt i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<intt> diffArr(n + 1);
    initialise(v, diffArr);
    for (intt i = 0; i < q; i++)
    {
        intt a;
        cin >> a;
        if (a == 1)
        {
            intt l, r, u;
            cin >> l >> r >> u;
            update(l - 1, r - 1, diffArr, u);
        }
        if (a == 2)
        {
            intt pos;
            cin >> pos;
            print(v, diffArr, pos - 1);
        }
    }
    return 0;
}
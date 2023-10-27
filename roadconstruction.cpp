#include <bits/stdc++.h>
using namespace std;
#define intt long long int

struct DSU
{
    vector<int> e;
    void init(intt n) { e = vector<int>(n, -1); }
    intt get(intt x) { return (e[x] < 0 ? x : e[x] = get(e[x])); }
    bool sameSet(intt x, intt y) { return get(x) == get(y); }
    intt size(intt x) { return -e[get(x)]; }
    bool unite(intt x, intt y)
    {
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (e[x] > e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

int32_t main()
{
    intt n, m;
    cin >> n >> m;
    DSU dsu;
    dsu.init(n);
    intt cc = n, large = 1;

    while (m--)
    {
        intt x, y;
        cin >> x >> y;
        x--;
        y--;
        if (dsu.unite(x, y))
        {
            large = max(large, dsu.size(x));
            cc--;
        }
        cout << cc << ' ' << large << '\n';
    }
}
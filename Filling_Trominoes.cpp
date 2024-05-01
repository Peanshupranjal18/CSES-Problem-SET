#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1, mod = 1e9 + 7;
int n, m, c;
string ans[101];

bool slave()
{
    if (n == 3)
    {
        if (m % 2)
            return 0;
        for (int i = 1; i <= m; i += 2)
        {
            if ((i / 2) & 1)
                ans[c] += "CC";
            else
                ans[c] += "AA";
        }
        c++;
        char x[4];
        x[0] = 'A', x[1] = 'B';
        x[2] = 'C', x[3] = 'D';
        for (int i = 0; i < m; i++)
        {
            ans[c] += x[(i % 4)];
        }
        c++;
        for (int i = 1; i <= m; i += 2)
        {
            if ((i / 2) & 1)
                ans[c] += "DD";
            else
                ans[c] += "BB";
        }
        return 1;
    }
    string y[4];
    y[0] = "VVX", y[1] = "VXX";
    y[2] = "YYZ", y[3] = "YZZ";
    for (int i = 1; i <= ((n & 1) ? n - 5 : n); i++, c++)
    {
        for (int j = 1; j <= m; j += 3)
            ans[c] += y[(i - 1) % 4];
    }
    if (n & 1)
    {
        if (m == 3)
            return 0;
        string x[2][5];
        x[0][0] = "AACCEE";
        x[0][1] = "ABCDEF";
        x[0][2] = "BBDDFF";
        x[0][3] = "IIJKKL";
        x[0][4] = "IJJKLL";
        x[1][0] = "AACCDEEFF";
        x[1][1] = "ABCDDHEFJ";
        x[1][2] = "BBGGHHIJJ";
        x[1][3] = "KKLGMNIIO";
        x[1][4] = "KLLMMNNOO";

        for (int i = 0; i < 5; i++, c++)
        {
            for (int j = 1; j <= m / 6 - (m % 6 > 0); j++)
            {
                ans[c] += x[0][i];
            }
            if (m % 6)
            {
                ans[c] += x[1][i];
            }
        }
    }
    return 1;
}

void solve()
{
    cin >> n >> m;
    if ((m % 3 and n % 3) or min(m, n) == 1)
    {
        cout << "NO"
             << "\n";
        return;
    }
    c = 0;
    bool ok = 0;
    if (n % 3 == 0)
    {
        ok = 1;
        swap(n, m);
    }
    if (slave())
    {
        cout << "YES\n";
        if (ok)
        {
            for (int j = 0; j < m; j++)
            {
                for (int i = n - 1; i >= 0; i--)
                    cout << ans[i][j];
                cout << "\n";
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
                cout << ans[i] << "\n";
        }
        for (int i = 0; i < n; i++)
            ans[i] = "";
    }
    else
    {
        for (int i = 0; i < n; i++)
            ans[i] = "";
        cout << "NO"
             << "\n";
    }
}

signed main()
{
    int tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
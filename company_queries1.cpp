// To solve this problem, we can use a standard binary lifting implementation where
// jmp(int x, int d) corresponds to the $d$-th ancestor of $x$.

// In our jmp(int x, int d) if our final value of $x$ is $0$, then such a node
// does not exist and we can simply return $-1$. This is because the lowest number
// a node can be is $1$ (the root of the tree).

// In our implementation, we test if we jump in powers of two by using the $\&$
// operator. If the $i$th bit on the right is toggled, then we jump. For example, a
// jump of $13$ would correspond to the binary number $1101$. We would jump 3 times
// on bits $0, 2, 3$ (in that order) counting from the right.

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORE(i, a, b) for (int i = (a); i <= (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define trav(a, x) for (auto &a : x)

int N, Q;

const int MX = 2e5 + 5; // maximum N
const int MS = 18;      // 18 is calculated by $\log_2 2e5$

int up[MS][MX];

int jmp(int x, int d)
{
    F0R(i, MS)
    if ((d >> i) & 1) x = up[i][x];
    return x ?: -1; // modfication to return -1 if not found
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;

    FOR(i, 2, N + 1)
    {
        int a;
        cin >> a;
        up[0][i] = a;
    }

    FOR(i, 1, MS)
    FOR(j, 1, N + 1)
    up[i][j] = up[i - 1][up[i - 1][j]]; // construct our parent array

    // uncomment below if you want to see the parent array

    // F0R(i, MS) {
    //     FOR(j, 1, N+1) {
    //         cerr << setfill(' ') << setw(2) << up[i][j] << " ";
    //     }
    //     cerr << "\n";
    // }

    F0R(i, Q)
    {
        int a, b;
        cin >> a >> b;
        cout << jmp(a, b) << "\n";
    }
}
// Suppose, the string contains the characters c1,c2,…,ck
// . The first idea is to make k
//  prefix sums, where each of them responds for each character.

// Pi,ch=Pi−1,ch+[si=ch]
// Now the substring [l,r]
//  is special iff Pr,ch−Pl−1,ch
//  is equal to x
//  where ch
//  is one of c1,…,ck
// .

// Notice that if the string is special, than all the elements from Pr
//  are not less than x
// . So let's substract x
//  from Pr
// . The problem is, that we have no x
// , but we can substract the minimal value from Pr
// , bacause it is the largest x
//  we can choose.

// The task is reduced to finding the number of such 1≤l≤r≤n
// , that Pr=Pl−1
// , what can be done in O(n⋅k)
//  time.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    map<char, int> h;
    int k = 0;
    for (auto &c : s)
    {
        if (!h.count(c))
            h[c] = k++;
    }
    map<vector<int>, int> cnt;
    vector<int> P(k);
    cnt[P] = 1;
    long long ans = 0;
    for (auto &c : s)
    {
        P[h[c]]++;
        int mx = *max_element(P.begin(), P.end());
        for (auto &a : P)
            a -= mx;
        ans += cnt[P]++;
    }
    cout << ans << "\n";
}
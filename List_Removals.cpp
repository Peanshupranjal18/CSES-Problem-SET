// // #include <bits/stdc++.h>
// // #include <ext/rope>
// // using namespace std;
// // using namespace __gnu_cxx;

// // int n;
// // rope<int> x;

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     cin >> n;
// //     for (int i = 0; i < n; i++)
// //     {
// //         int t;
// //         cin >> t;
// //         x.push_back(t);
// //     }

// //     for (int i = 0; i < n; i++)
// //     {
// //         int p;
// //         cin >> p;
// //         --p;
// //         cout << x[p] << " ";
// //         x.erase(x.mutable_begin() + p);
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

// template <class T>
// using Tree =
//     tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// int main()
// {
//     int n;
//     cin >> n;
//     Tree<int> ist;
//     vector<int> p(n);
//     for (int i = 0; i < n; i++)
//     {
//         ist.insert(i);
//         cin >> p[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         int ind;
//         cin >> ind;
//         ind--;
//         int pos = *ist.find_by_order(ind);
//         ist.erase(pos);
//         cout << p[pos] << (i == n - 1 ? '\n' : ' ');
//     }
// }

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 2e5 + 5;

struct BIT
{
    int value = 0;
    void update(int val) { value += val; }
    int query() { return value; }
};

struct BIT_2D
{
    BIT bit[MAX_SIZE];

    void update(int pos, int val)
    {
        assert(pos > 0);
        for (; pos < MAX_SIZE; pos += pos & -pos)
            bit[pos].update(val);
    }

    int sum(int r)
    {
        int result = 0;
        for (; r; r -= r & -r)
            result += bit[r].query();
        return result;
    }

    int query(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};

int get_kth(const BIT_2D &bit, int target)
{
    assert(target > 0);
    int index = 0;
    for (int i = 1 << 17; i; i /= 2)
        if (index + i < MAX_SIZE && bit.bit[index + i].value < target)
            target -= bit.bit[index += i].value;
    assert(index < MAX_SIZE);
    return index + 1;
}

BIT_2D binaryIndexedTree;
int numberOfElements;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> numberOfElements;
    vector<int> elements(numberOfElements);
    for (int i = 0; i < numberOfElements; ++i)
    {
        cin >> elements[i];
        binaryIndexedTree.update(i + 1, 1);
    }

    for (int i = 0; i < numberOfElements; ++i)
    {
        int position;
        cin >> position;
        int index = get_kth(binaryIndexedTree, position);
        cout << elements[index - 1] << " ";
        binaryIndexedTree.update(index, -1);
    }

    return 0;
}

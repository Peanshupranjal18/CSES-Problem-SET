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

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> information; // stores the actual array with our data
// vector<int> results;

// struct Node
// {
//     int left, right, count;
//     Node *left_child, *right_child;

//     Node(int l, int r) : left(l), right(r), count(r - l + 1), left_child(nullptr), right_child(nullptr)
//     {
//         if (left != right)
//         {
//             int mid = (left + right) / 2;
//             left_child = new Node(left, mid);
//             right_child = new Node(mid + 1, right);
//         }
//     }

//     void remove(int index)
//     {
//         count--;
//         if (left == right)
//         {
//             results.push_back(information[left]);
//         }
//         else if (left_child->count > index)
//         {
//             left_child->remove(index);
//         }
//         else
//         {
//             right_child->remove(index - left_child->count);
//         }
//     }
// };

// int main()
// {
//     int n;
//     cin >> n;
//     information.resize(n);
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> information[i];
//     }

//     Node root(0, n - 1);
//     for (int i = 0; i < n; ++i)
//     {
//         int index;
//         cin >> index;
//         root.remove(index - 1); // converting 1-indexed to 0-indexed
//     }

//     for (int i = 0; i < n; ++i)
//     {
//         cout << results[i] << " \n"[i == n - 1];
//     }

//     return 0;
// }
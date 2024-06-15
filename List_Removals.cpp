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
#include <algorithm>
using namespace std;

// Function to update the Binary Indexed Tree (BIT)
void updateBIT(vector<int> &bit, int index, int value, int maxSize)
{
    while (index <= maxSize)
    {
        bit[index] += value;
        index += index & -index; // Move to the next index
    }
}

// Function to get the sum from the start to the given index
int sumBIT(const vector<int> &bit, int index)
{
    int sum = 0;
    while (index > 0)
    {
        sum += bit[index];
        index -= index & -index; // Move to the previous index
    }
    return sum;
}

// Function to find the k-th element in the BIT
int getKthElement(const vector<int> &bit, int target, int maxSize)
{
    int index = 0;
    int bitMask = maxSize;
    while (bitMask != 0 && index < maxSize)
    {
        int tIndex = index + bitMask;
        if (target > bit[tIndex])
        {
            index = tIndex;
            target -= bit[tIndex];
        }
        bitMask >>= 1;
    }
    return index + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfElements;
    cin >> numberOfElements;
    vector<int> elements(numberOfElements);
    vector<int> bit(numberOfElements + 1, 0); // BIT initialized to 0

    // Read elements and update the BIT
    for (int i = 0; i < numberOfElements; ++i)
    {
        cin >> elements[i];
        updateBIT(bit, i + 1, 1, numberOfElements);
    }

    // Process the positions to remove elements
    for (int i = 0; i < numberOfElements; ++i)
    {
        int position;
        cin >> position;
        int index = getKthElement(bit, position, numberOfElements);
        cout << elements[index - 1] << " ";
        updateBIT(bit, index, -1, numberOfElements); // Remove the element from BIT
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
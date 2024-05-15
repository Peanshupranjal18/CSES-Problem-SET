#include <bits/stdc++.h>
using namespace std;
#define intt long long

vector<intt> fenwick;
vector<intt> v;

// Function to update the Fenwick Tree
void update(intt index, intt val, intt n)
{
    while (index <= n)
    {
        fenwick[index] += val;
        index += index & (-index);
    }
}

// Function to query the Fenwick Tree for cumulative sum up to index
intt query(intt index)
{
    intt sum = 0;
    while (index > 0)
    {
        sum += fenwick[index];
        index -= index & (-index);
    }
    return sum;
}

// Function to process queries
void processQueries(intt n, intt q)
{
    for (intt i = 0; i < n; i++)
    {
        update(i + 1, v[i], n);
        update(i + 2, -v[i], n);
    }
    for (intt i = 0; i < q; i++)
    {
        intt type;
        cin >> type;
        if (type == 1)
        {
            intt a, b, u;
            cin >> a >> b >> u;
            update(a, u, n);
            update(b + 1, -u, n);
        }
        else if (type == 2)
        {
            intt k;
            cin >> k;
            cout << query(k) << endl;
        }
    }
}

int main()
{
    intt n, q;
    cin >> n >> q;
    v.resize(n);
    fenwick.resize(n + 1, 0);
    for (intt i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    processQueries(n, q);
    return 0;
}
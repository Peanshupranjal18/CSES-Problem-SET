#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 2e5 + 5;

int n, q;
int pizza_prices[MAXN];
vector<int> segment_tree_down(MAXN * 4, INF);
vector<int> segment_tree_up(MAXN * 4, INF);

void update_segment_tree(vector<int> &segment_tree, int pos, int value, int node, int node_left, int node_right)
{
    if (node_left == node_right)
    {
        segment_tree[node] = value;
        return;
    }
    int mid = (node_left + node_right) / 2;
    if (pos <= mid)
    {
        update_segment_tree(segment_tree, pos, value, 2 * node, node_left, mid);
    }
    else
    {
        update_segment_tree(segment_tree, pos, value, 2 * node + 1, mid + 1, node_right);
    }
    segment_tree[node] = min(segment_tree[2 * node], segment_tree[2 * node + 1]);
}

int query_segment_tree(const vector<int> &segment_tree, int query_left, int query_right, int node, int node_left, int node_right)
{
    if (query_right < node_left || node_right < query_left)
    {
        return INF;
    }
    if (query_left <= node_left && node_right <= query_right)
    {
        return segment_tree[node];
    }
    int mid = (node_left + node_right) / 2;
    return min(query_segment_tree(segment_tree, query_left, query_right, 2 * node, node_left, mid),
               query_segment_tree(segment_tree, query_left, query_right, 2 * node + 1, mid + 1, node_right));
}

void update_pizza_price(int index, int new_price)
{
    pizza_prices[index] = new_price;
    update_segment_tree(segment_tree_down, index, new_price - index, 1, 1, n);
    update_segment_tree(segment_tree_up, index, new_price + index, 1, 1, n);
}

int get_minimum_price(int building_index)
{
    int price_down = query_segment_tree(segment_tree_down, 1, building_index, 1, 1, n) + building_index;
    int price_up = query_segment_tree(segment_tree_up, building_index, n, 1, 1, n) - building_index;
    return min(price_down, price_up);
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> pizza_prices[i];
    }

    for (int i = 1; i <= n; i++)
    {
        update_pizza_price(i, pizza_prices[i]);
    }

    while (q--)
    {
        int query_type;
        cin >> query_type;
        if (query_type == 1)
        {
            int building_index, new_price;
            cin >> building_index >> new_price;
            update_pizza_price(building_index, new_price);
        }
        else
        {
            int building_index;
            cin >> building_index;
            cout << get_minimum_price(building_index) << '\n';
        }
    }

    return 0;
}
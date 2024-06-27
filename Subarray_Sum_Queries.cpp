#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 200001;

ll n, initial_values[MAXN];
ll global_max[4 * MAXN], left_max[4 * MAXN], right_max[4 * MAXN], total_sum[4 * MAXN];

void build_segment_tree(ll left = 1, ll right = n, ll node = 1)
{
    if (left == right)
    {
        ll value = initial_values[left];
        global_max[node] = max(0ll, value);
        left_max[node] = max(0ll, value);
        right_max[node] = max(0ll, value);
        total_sum[node] = value;
    }
    else
    {
        ll mid = (left + right) / 2;
        build_segment_tree(left, mid, node * 2);
        build_segment_tree(mid + 1, right, node * 2 + 1);

        total_sum[node] = total_sum[node * 2] + total_sum[node * 2 + 1];
        left_max[node] = max(left_max[node * 2], total_sum[node * 2] + left_max[node * 2 + 1]);
        right_max[node] = max(right_max[node * 2 + 1], total_sum[node * 2 + 1] + right_max[node * 2]);
        global_max[node] = max({global_max[node * 2], global_max[node * 2 + 1], right_max[node * 2] + left_max[node * 2 + 1]});
    }
}

void update_segment_tree(ll position, ll new_value, ll left = 1, ll right = n, ll node = 1)
{
    if (left == right)
    {
        global_max[node] = max(0ll, new_value);
        left_max[node] = max(0ll, new_value);
        right_max[node] = max(0ll, new_value);
        total_sum[node] = new_value;
    }
    else
    {
        ll mid = (left + right) / 2;
        if (position > mid)
        {
            update_segment_tree(position, new_value, mid + 1, right, node * 2 + 1);
        }
        else
        {
            update_segment_tree(position, new_value, left, mid, node * 2);
        }

        total_sum[node] = total_sum[node * 2] + total_sum[node * 2 + 1];
        left_max[node] = max(left_max[node * 2], total_sum[node * 2] + left_max[node * 2 + 1]);
        right_max[node] = max(right_max[node * 2 + 1], total_sum[node * 2 + 1] + right_max[node * 2]);
        global_max[node] = max({global_max[node * 2], global_max[node * 2 + 1], right_max[node * 2] + left_max[node * 2 + 1]});
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll queries;
    cin >> n >> queries;

    for (int i = 1; i <= n; ++i)
    {
        cin >> initial_values[i];
    }

    build_segment_tree();

    while (queries--)
    {
        ll position, new_value;
        cin >> position >> new_value;
        update_segment_tree(position, new_value);
        cout << global_max[1] << '\n';
    }

    return 0;
}
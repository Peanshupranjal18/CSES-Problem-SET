// refer usaco for all the approaches of the problem

// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// int main() {
// 	int n;
// 	cin >> n;
// 	vector<ll> heights(n);
// 	for (ll &i : heights) { cin >> i; }

// 	stack<int> mono_stack;
// 	vector<ll> area(n, 0);

// 	// left to right
// 	for (int i = 0; i < n; i++) {
// 		while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
// 			mono_stack.pop();
// 		}
// 		int width = i - (mono_stack.empty() ? -1 : mono_stack.top());
// 		area[i] += width * heights[i];
// 		mono_stack.push(i);
// 	}
// 	while (!mono_stack.empty()) { mono_stack.pop(); }

// 	// right to left
// 	for (int i = n - 1; i >= 0; i--) {
// 		while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
// 			mono_stack.pop();
// 		}
// 		int width = (mono_stack.empty() ? n : mono_stack.top()) - i;
// 		area[i] += (width - 1) * heights[i];
// 		mono_stack.push(i);
// 	}

// 	cout << *max_element(area.begin(), area.end()) << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// int main() {
// 	int n;
// 	cin >> n;
// 	vector<ll> heights(n);
// 	for (ll &i : heights) { cin >> i; }

// 	ll ans = 0;
// 	stack<pair<ll, ll>> mono_stack;
// 	for (int i = 0; i < n; i++) {
// 		int start = i;
// 		while (!mono_stack.empty() && heights[i] < mono_stack.top().second) {
// 			pair<ll, ll> cur = mono_stack.top();
// 			mono_stack.pop();
// 			start = cur.first;
// 			ans = max(ans, (i - cur.first) * cur.second);
// 		}
// 		mono_stack.push({start, heights[i]});
// 	}

// 	// finish up the remaining rectangles
// 	while (!mono_stack.empty()) {
// 		pair<ll, ll> cur = mono_stack.top();
// 		mono_stack.pop();
// 		ans = max(ans, (n - cur.first) * cur.second);
// 	}

// 	cout << ans << endl;
// }

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> heights(n);
    for (ll &i : heights)
    {
        cin >> i;
    }
    heights.push_back(-1);

    stack<ll> mono_stack;
    mono_stack.push(-1);

    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        while (mono_stack.top() != -1 &&
               heights[mono_stack.top()] >= heights[i])
        {
            int x = mono_stack.top();
            mono_stack.pop();
            // min height is heights[x]
            ll new_area = (i - 1 - mono_stack.top()) * heights[x];
            if (ans < new_area)
            {
                ans = new_area;
            }
        }
        mono_stack.push(i);
    }

    cout << ans << endl;
}
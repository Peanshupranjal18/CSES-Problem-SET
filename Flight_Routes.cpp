#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MX = 2e5 + 5;
int n, m, k;                                                                     // Variables to store the number of cities, flights, and the number of shortest routes required
priority_queue<ll> bes[MX];                                                      // Array of priority queues to store the k shortest distances to each city
vector<pair<int, int>> adj[MX];                                                  // Adjacency list to store the graph (flights)
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; // Min-heap priority queue for Dijkstra's algorithm

int main()
{
    ios_base::sync_with_stdio(0); // Speed up input/output
    cin.tie(0);

    cin >> n >> m >> k; // Read the number of cities, flights, and the required number of shortest routes
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;       // Read each flight
        adj[a].push_back({b, c}); // Add the flight to the adjacency list
    }
    bes[1].push(0); // The distance to the starting city (Syrjälä) is 0
    // distance and node number
    pq.push({0, 1}); // Add the starting city to the priority queue

    while (!pq.empty())
    {
        auto a = pq.top(); // Get the city with the smallest distance
        pq.pop();
        if (a.first > bes[a.second].top()) // If the distance is not one of the k shortest, skip it
            continue;
        for (auto &i : adj[a.second]) // Explore all adjacent cities
        {
            ll tmp = a.first + i.second; // Calculate the distance to the adjacent city
            if (bes[i.first].size() < k) // If there are less than k distances stored for the city
            {
                bes[i.first].push(tmp);  // Add the new distance
                pq.push({tmp, i.first}); // Add the city to the priority queue for further exploration
            }
            else if (tmp < bes[i.first].top()) // If there are already k distances, check if the new distance is smaller than the largest stored distance
            {
                bes[i.first].pop();      // Remove the largest distance
                bes[i.first].push(tmp);  // Add the new smaller distance
                pq.push({tmp, i.first}); // Add the city to the priority queue for further exploration
            }
        }
    }
    vector<ll> ans; // Vector to store the k shortest distances to the destination city
    while (!bes[n].empty())
    {
        ans.push_back(bes[n].top()); // Collect the distances from the priority queue
        bes[n].pop();
    }
    reverse(ans.begin(), ans.end()); // Reverse the vector to get the distances in ascending order
    for (auto a : ans)
        cout << a << " "; // Print the distances
}
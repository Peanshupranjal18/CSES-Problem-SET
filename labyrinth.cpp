#include <bits/stdc++.h>
using namespace std;
#define intt long long

int n, m;
vector<vector<char>> v;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;
pair<int, int> start, end_pos;

bool bfs(pair<int, int> start)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    string mov = "ULDR";

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && v[newX][newY] != '#' && !visited[newX][newY])
            {
                q.push({newX, newY});
                visited[newX][newY] = true;
                parent[newX][newY] = {x, y};

                if (v[newX][newY] == 'B')
                {
                    end_pos = {newX, newY};
                    return true;
                }
            }
        }
    }

    return false;
}

void solve()
{
    cin >> n >> m;
    v.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    parent.resize(n, vector<pair<int, int>>(m, {-1, -1}));

    bool foundStart = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'A')
            {
                start = {i, j};
                foundStart = true;
            }
        }
    }

    if (!foundStart)
    {
        cout << "NO"
             << "\n";
        return;
    }

    bool ans = bfs(start);
    if (ans)
    {
        cout << "YES"
             << "\n";

        vector<char> path;
        pair<int, int> curr = end_pos;

        while (curr != start)
        {
            pair<int, int> prev = parent[curr.first][curr.second];
            if (curr.first == prev.first + 1)
                path.push_back('D');
            else if (curr.first == prev.first - 1)
                path.push_back('U');
            else if (curr.second == prev.second + 1)
                path.push_back('R');
            else if (curr.second == prev.second - 1)
                path.push_back('L');
            curr = prev;
        }

        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (char c : path)
        {
            cout << c;
        }
        cout << "\n";
    }
    else
    {
        cout << "NO"
             << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

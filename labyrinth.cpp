// #include <bits/stdc++.h>
// using namespace std;
// #define endl ("\n")
// #define pi (3.141592653589)
// #define mod 1000000007
// #define int long long
// #define pb push_back
// #define mp make_pair
// #define ff first
// #define ss second
// #define rep(i,n) for(int i=0;i<n;i++)
// #define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// bool valid(int row, int cols, int n, int m){
//     return (row >= 0 && row < n && cols >= 0 && cols < m);
// }

// int32_t main(){
//     fast
// //   freopen("input.txt","r",stdin);
// //	freopen("output.txt","w",stdout);
//     int t=1;
// //    cin>>t;
//     while(t--){
//     	int n, m;cin>>n>>m;
//     int row[4] = {1, -1, 0, 0};
// 	int col[4] = {0, 0, 1, -1};

//     vector<vector<char>>v(n, vector<char>(m));

//     int vis[n][m];rep(i, n)rep(j, m)vis[i][j]=0;

//     pair<int, int>start;

//     rep(i, n){
//     	rep(j, m){
//     		cin>>v[i][j];
//     		if(v[i][j]=='A')start=mp(i, j);
// 		}
// 	}

//     list<pair<int, int>> q;

//     vis[start.ff][start.ss]=1;
//     q.pb(start);

//     map<pair<int, int>, pair<pair<int, int>,char>>parent;

//     while (!q.empty())
//     {
//         auto s=q.front();
//         int a=s.ff, b=s.ss;
//         q.pop_front();

//         for(auto i :row){
//             for(auto j :col){
//                 if(valid(a+i, b+j, n, m) and (abs(i) != abs(j)) and !vis[a+i][b+j] and (v[a+i][b+j] == '.' or v[a+i][b+j] == 'B') ){
//                     char c;
//                     if(i==1 and j==0)
//                         c= 'D';
//                     if(i==-1 and j==0)
//                         c='U';
//                     if(j==1 and i==0)
//                         c='R';
//                     if(j==-1 and i==0)
//                         c='L';

//                     parent[mp(a+i, b+j)]=mp(mp(a, b),c);

//                     if(v[a+i][b+j] == 'B'){
//                         auto end = make_pair(a+i, b+j);
//                         string res = "";
//                         while(true){
//                             res += parent[end].ss;
//                             end = parent[end].ff;
//                             if(end.ff == start.ff and end.ss == start.ss){
//                                 break;
//                             }
//                         }
//                         reverse(res.begin(), res.end());
//                         cout<<"YES"<<endl;
//                         cout<<res.length()<<endl;
//                         cout<<res;
//                         return 0;
//                     }

//                     vis[a+i][b+j]=1;
//                     q.pb(mp(a+i, b+j));
//                 }
//             }
//         }
//     }
//     cout<<"NO";
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <cmath>

// using namespace std;

// typedef long long int intt;
// typedef vector<intt> vi;
// typedef vector<vector<intt>> vvi;

// // Up, Left, Down, Right
// intt dx[] = {-1, 0, +1, 0};
// intt dy[] = {0, -1, 0, +1};

// bool isPrime(intt n)
// {
//     if (n <= 1)
//         return false;
//     if (n == 2 || n == 3)
//         return true;
//     if (n % 2 == 0 || n % 3 == 0)
//         return false;
//     for (intt i = 5; i * i <= n; i = i + 6)
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     return true;
// }

// void solve()
// {
//     intt n, m;
//     cin >> n >> m;
//     vector<vector<char>> v(n, vector<char>(m));
//     vvi vis(n, vi(m, 0));
//     pair<intt, intt> start, end;
//     for (intt i = 0; i < n; i++)
//     {
//         for (intt j = 0; j < m; j++)
//         {
//             cin >> v[i][j];
//             if (v[i][j] == 'A')
//                 start = {i, j};
//             if (v[i][j] == 'B')
//                 end = {i, j};
//         }
//     }
//     priority_queue<pair<intt, intt>, vector<pair<intt, intt>>, greater<pair<intt, intt>>> q;
//     q.push(start);
//     vis[start.first][start.second] = 1;
//     vector<char> l;

//     while (!q.empty())
//     {
//         intt x = q.top().first;
//         intt y = q.top().second;
//         q.pop();

//         for (intt i = 0; i < 4; i++)
//         {
//             intt newx = x + dx[i];
//             intt newy = y + dy[i];
//             char ch;
//             if (i == 0)
//                 ch = 'U';
//             if (i == 1)
//                 ch = 'L';
//             if (i == 2)
//                 ch = 'D';
//             if (i == 3)
//                 ch = 'R';
//             if (newx >= 0 and newx < n and newy >= 0 and newy < m and vis[newx][newy] == 0)
//             {
//                 if (v[newx][newy] == '#')
//                 {
//                     continue; // Skip this direction if it's an obstacle.
//                 }
//                 if (v[newx][newy] == 'B')
//                 {
//                     vis[newx][newy] = 1;
//                     l.push_back(ch);
//                     break;
//                 }
//                 else if (v[newx][newy] == '.')
//                 {
//                     vis[newx][newy] = 1;
//                     q.push({newx, newy});
//                     l.push_back(ch);
//                 }
//             }
//         }
//     }
//     if (vis[end.first][end.second] == 0)
//     {
//         cout << "NO" << endl;
//         return;
//     }
//     cout << "YES" << endl;
//     cout << l.size() << endl;
//     for (char ch : l)
//     {
//         cout << ch;
//     }
//     cout << endl;
// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     // intt tc;
//     // cin >> tc;
//     // while (tc--)
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair

int n, m;
char A[1000][1000];
bool vis[1000][1000];

// previousStep stores the previous direction that we moved in to arrive that
// this cell
int previousStep[1000][1000];

// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string stepDir = "URDL";

int main()
{
    cin >> n >> m;

    queue<ii> q;
    ii begin, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 'A')
            {
                begin = mp(i, j);
            }
            else if (A[i][j] == 'B')
            {
                end = mp(i, j);
            }
        }
    }

    q.push(begin);
    vis[begin.f][begin.s] = true;

    while (!q.empty())
    {
        ii u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            ii v = mp(u.f + dx[i], u.s + dy[i]);
            if (v.f < 0 || v.f >= n || v.s < 0 || v.s >= m)
                continue;
            if (A[v.f][v.s] == '#')
                continue;
            if (vis[v.f][v.s])
                continue;
            vis[v.f][v.s] = true;
            // storing the previous step respectivelyq
            previousStep[v.f][v.s] = i;
            q.push(v);
        }
    }

    if (vis[end.f][end.s])
    {
        cout << "YES" << endl;
        vector<int> steps;
        while (end != begin)
        {
            int p = previousStep[end.f][end.s];
            steps.push_back(p);
            // undo the previous step to get back to the previous square
            // Notice how we subtract dx/dy, whereas we added dx/dy before
            end = mp(end.f - dx[p], end.s - dy[p]);
        }
        reverse(steps.begin(), steps.end());

        cout << steps.size() << endl;
        for (char c : steps)
        {
            cout << stepDir[c];
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
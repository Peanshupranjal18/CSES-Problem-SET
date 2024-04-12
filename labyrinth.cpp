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

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("Ofast,unroll-loops")

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p)
{
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "): ", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define intt long long int
#define ll long long
#define ld long double
#define MOD 1000000007
#define f(i, n) for (intt i = 0; i < n; i++)
#define ff(i, a, b) for (intt i = a; i < b; i++)
#define pb push_back
#define ii pair<intt, intt>
#define vi vector<intt>
#define vvi vector<vector<intt>>
#define vpi vector<pair<intt, intt>>
#define fi first
#define sec second
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define minv *min_element
#define maxv *max_element
#define rt return
#define um unordered_map
#define acc accumulate
#define sz(x) x.size()
#define ub upper_bound
#define lb lower_bound
#define mt multiset
#define rs resize
#define mah priority_queue<intt>
#define mih priority_queue<intt, vector<intt>, greater<intt>>
#define mahp priority_queue<pair<intt, intt>>
#define mihp priority_queue<pair<intt, intt>, vector<pair<intt, intt>>, greater<pair<intt, intt>>>
#define PI 3.1415926535897932384626433832795l
#define clr(x) x.clear()

// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define SHUF(v) shuffle(all(v), RNG);

// Use mt19937_64 for 64 bit random numbers.

// BITWISE OPERATIONS
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a, b) ((a) &= ~(1ULL << (b)))
#define BIT_FLIP(a, b) ((a) ^= (1ULL << (b)))

// '!!' to make sure this returns 0 or 1
#define BIT_CHECK(a, b) (!!((a) & (1ULL << (b))))

// BITMASK OPERATIONS
#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))

// MATH FUNCTIONS
template <typename T>
T gcd(T a, T b) { return (b ? __gcd(a, b) : a); }
template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }
int add(int a, int b, int c = MOD)
{
    int res = a + b;
    return (res >= c ? res - c : res);
}
int mod_neg(int a, int b, int c = MOD)
{
    int res;
    if (abs(a - b) < c)
        res = a - b;
    else
        res = (a - b) % c;
    return (res < 0 ? res + c : res);
}
int mul(int a, int b, int c = MOD)
{
    ll res = (ll)a * b;
    return (res >= c ? res % c : res);
}
int muln(int a, int b, int c = MOD)
{
    ll res = (ll)a * b;
    return ((res % c) + c) % c;
}
ll mulmod(ll a, ll b, ll m = MOD)
{
    ll q = (ll)(((ld)a * (ld)b) / (ld)m);
    ll r = a * b - q * m;
    if (r > m)
        r %= m;
    if (r < 0)
        r += m;
    return r;
}
template <typename T>
T expo(T e, T n)
{
    T x = 1, p = e;
    while (n)
    {
        if (n & 1)
            x = x * p;
        p = p * p;
        n >>= 1;
    }
    return x;
}
template <typename T>
T power(T e, T n, T m = MOD)
{
    T x = 1, p = e;
    while (n)
    {
        if (n & 1)
            x = mul(x, p, m);
        p = mul(p, p, m);
        n >>= 1;
    }
    return x;
}
template <typename T>
T extended_euclid(T a, T b, T &x, T &y)
{
    T xx = 0, yy = 1;
    y = 0;
    x = 1;
    while (b)
    {
        T q = a / b, t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}
template <typename T>
T mod_inverse(T a, T n = MOD)
{
    T x, y, z = 0;
    T d = extended_euclid(a, n, x, y);
    return (d > 1 ? -1 : mod_neg(x, z, n));
}

// Prime Generator
const int N = 1e7 + 10;
int prime[20000010];
bool isprime[N];
int nprime;
template <typename T>
void Sieve(T a)
{
    nprime = 0;
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            prime[nprime++] = i;
            for (int j = 2; i * j < N; j++)
                isprime[i * j] = false;
        }
    }
}

// Geometry Functions
template <typename T>
inline T PointDistanceHorVer(T x1, T y1, T x2, T y2) { return abs(x1 - x2) + abs(y1 - y2); }
template <typename T>
inline T PointDistanceDiagonally(T x1, T y1, T x2, T y2) { return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); }
template <typename T>
inline T PointDistanceMinimum(T x1, T y1, T x2, T y2)
{
    T tmp1 = abs(x1 - x2);
    T tmp2 = abs(y1 - y2);
    T tmp3 = abs(tmp1 - tmp2);
    T tmp4 = min(tmp1, tmp2);
    return tmp3 + tmp4;
}
template <typename T>
inline T PointDistance3D(T x1, T y1, T z1, T x2, T y2, T z2) { return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1)); }
template <typename T>
inline T Cube(T a) { return a * a * a; }
template <typename T>
inline T RectangularPrism(T a, T b, T c) { return a * b * c; }
template <typename T>
inline T Pyramid(T base, T height) { return (1.0 / 3) * base * height; }
template <typename T>
inline T Ellipsoid(T r1, T r2, T r3) { return (4.0 / 3) * PI * r1 * r2 * r3; }
template <typename T>
inline T IrregularPrism(T base, T height) { return base * height; }
template <typename T>
inline T Sphere(T radius) { return (4.0 / 3) * PI * radius * radius * radius; }
template <typename T>
inline T CylinderB(T base, T height) { return base * height; }
template <typename T>
inline T CylinderR(T radius, T height) { return PI * radius * radius * height; }
template <typename T>
inline T Cone(T radius, T base, T height) { return (1.0 / 3) * PI * radius * radius * height; }

// Direction Arrays
intt dx[] = {0, 0, 1, -1};
intt dy[] = {1, -1, 0, 0};

// Global Variables
vi v, v1, v2, v3, v4;
vi dp(200001);

// Utility Functions
bool possible(int x, int y, int n, int m) { return (x < n && x >= 0 && y < m && y >= 0); }

// Primality Check
bool isPrime(intt n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (intt i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Ordered Set
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Solve Function
void solve()
{
}

// Main Function
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    intt tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
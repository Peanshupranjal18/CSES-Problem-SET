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
    int n;
    cin >> n;
    map<int, int> compress;
    vector<int> a(n), b(n), p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> p[i];
        b[i]++;
        compress[a[i]], compress[b[i]];
    }

    int coords = 0;
    for (auto &v : compress)
    {
        v.second = coords++;
    }

    vector<vector<pair<int, int>>> project(coords);
    for (int i = 0; i < n; i++)
    {
        project[compress[b[i]]].emplace_back(compress[a[i]], p[i]);
    }

    vector<long long> dp(coords, 0);
    for (int i = 0; i < coords; i++)
    {
        if (i > 0)
        {
            dp[i] = dp[i - 1];
        }
        for (auto p : project[i])
        {
            dp[i] = max(dp[i], dp[p.first] + p.second);
        }
    }
    cout << dp[coords - 1] << endl;
}

// Main Function
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // intt tc;
    // cin >> tc;
    // while (tc--)
    solve();
    return 0;
}
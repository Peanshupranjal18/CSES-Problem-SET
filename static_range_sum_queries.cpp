#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define MOD 1000000007
using namespace std;

lli solve(vector<lli>& v,lli b,lli c){
    lli sum = 0;
    for(lli i=b-1;i<=c-1;i++){
        sum = sum + v[i];
    }
    return sum;
}

int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
    lli n,a;
    cin>>n>>a;
    vector<lli> v;
    for(lli i=0;i<n;i++){
        lli x;
        cin>>x;
        v.push_back(x);
    }
    while(a--){
        lli b,c;
        cin>>b>>c;
        lli x = solve(v,b,c);
        cout<<x<<"\n";
    }
return 0;
}
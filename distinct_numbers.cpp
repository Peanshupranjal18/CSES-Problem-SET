#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
    lli n;
    cin>>n;
    vector<int> v;
    lli a;
    for(lli i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    lli count=1;
    for(lli i=0;i<v.size()-1;i++){
       if(v[i]!=v[i+1]){
           count=count+1;
       }
    }
    cout<<count;

return 0;
}
#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define MOD 1000000007
using namespace std;

int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        int a,b;
        cin>>a>>b;
        if(max(a,b)>2*min(a,b)){
            cout<<"NO"<<"\n";
        }
        else if((a+b)%3==0){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
return 0;
}
#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define MOD 1000000007
using namespace std;

int solve(vector<int>& v){
    int mxcount = 0;
    int res = -1;

    unordered_map<int,int> map1;

    for(int i=0;i<v.size();i++){
        map1[v[i]]++;
    }

    for(auto x : map1){
        if(x.second>mxcount){
            res = x.first;
            mxcount = x.second;
        }
    }
    return res;
}

int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    int max_occurence = solve(v);
    vector<int> v1;
    for(int i=0;i<v.size();i++){
        v1.push_back(abs(v[i]-max_occurence));
    }

    int answer = accumulate(v1.begin(),v1.end(),0);

    cout<<answer;
    
return 0;
}
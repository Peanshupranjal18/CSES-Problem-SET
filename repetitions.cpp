#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;

//length of the longest substring
//correct code ......

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
    string s;
    getline(cin,s);
    vector<int> v;
    int count=1;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]){
            count++;
        }
        if(s[i]!=s[i+1]){
            v.push_back(count);
            count=1;
        }
    }
    v.push_back(count);
    sort(v.begin(),v.end(), greater<int>());
    cout<<v[0];
return 0;
}
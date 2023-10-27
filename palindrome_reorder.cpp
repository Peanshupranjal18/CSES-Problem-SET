#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define MOD 1000000007
using namespace std;

string getpalindrome(string str){

    unordered_map<char,int> hmap;
    //storing the count of the characters
    for(int i=0;i<str.length();i++){
        hmap[str[i]]++;
    }

    int oddCount = 0;
    char oddChar;
    for(auto x: hmap){
        if(x.second % 2 != 0){
            oddCount++;
            oddChar = x.first;
        }
    }

    if(oddCount > 1 || oddCount == 1 && str.length() % 2 ==0)return "NO SOLUTION";

    string firstHalf="", secondHalf="";
    for(auto x : hmap){
        string s(x.second/2,x.first);

        firstHalf = firstHalf + s;
        secondHalf = s+secondHalf;
    }

    return (oddCount ==1)?(firstHalf+oddChar+secondHalf):(firstHalf+secondHalf);
}

int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
    string str;
    getline(cin,str);
    string b = getpalindrome(str);
    cout<<b;
return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
int cntd(int i,string&s,vector<int>&dp){
    if(i>=s.size())return 0;
    if(dp[i]!=-1)return dp[i];
    long long cnt=0;
    vector<bool>used(26,false);
    for(int j=i;j<s.size();j++){
        int id=s[j]-'a';
        if(used[id])continue;
        used[id]=true;
        cnt=(1+cnt+cntd(j+1,s,dp))%(mod);
    }
    return dp[i]=cnt;
}
int main(){
    string s="aaa";
    int n=s.size();
    vector<int>dp(n,-1);
    cout<<cntd(0,s,dp);
    return 0;
}
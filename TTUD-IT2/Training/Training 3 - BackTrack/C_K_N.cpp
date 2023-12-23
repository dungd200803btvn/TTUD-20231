//C++ 
#include <bits/stdc++.h> 
#define ll long long
using namespace std;
int n,k;
const int MOD =1e9+7;
ll proc(int n,int k,vector<vector<ll>>&dp){
    if(k==0 || k==n){
        return 1;
    }if(dp[n][k]!=-1){
        return dp[n][k];
    }
    ll res = (proc(n-1,k-1,dp)+proc(n-1,k,dp))%MOD;
    dp[n][k] = res;
    return res;
}
int main() 
{ 
cin>>k>>n;
vector<vector<ll>> dp(n+1,vector<ll>(k+1,-1));
ll res = proc(n,k,dp);
cout<<res;
return 0;
}

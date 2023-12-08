#include<bits/stdc++.h>
using namespace std;
const int MAX= 1e5+4;
int n,a[MAX],dp[MAX];
int res=0;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[1] =a[1];
	dp[2] = max(a[1],a[2]);
	for(int i=3;i<=n;i++){
		dp[i] = max(dp[i-1],a[i]+dp[i-2]);
		if(dp[i]==dp[i-2]+a[i]){
		
		}
		res= max(res,dp[i]);
	}
	cout <<res;
	return 0;
} 
 

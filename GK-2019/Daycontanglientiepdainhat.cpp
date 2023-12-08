#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+4;
int a[MAX],dp[MAX];
int n;
int res=0;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[1] =1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			dp[i] = 1+dp[i-1];
		}else{
			dp[i] =1; 
		} 
		res = max(res,dp[i]);
	}
	cout <<res<<endl;
	return 0;
}

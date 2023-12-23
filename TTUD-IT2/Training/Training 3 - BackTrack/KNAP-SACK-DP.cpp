#include<bits/stdc++.h>
using namespace std;
int n,b;
const int MAX =31;
int value[MAX],weight[MAX];
int dp[MAX][MAX];
int res=0;
int main(){
	freopen("knapsack.txt","r",stdin);
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin >> weight[i] >>value[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=b;j++){
			if(j-weight[i]>=0){
					dp[i][j] = max(dp[i-1][j-weight[i]]+value[i],dp[i-1][j]);
			}
		
		}	
	}
	cout <<dp[n][b]<<endl;
	
	return 0;
}

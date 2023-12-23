#include<bits/stdc++.h>
using namespace std;
const int MAX=1e4+5;
int a[MAX];
int N;
int dp[MAX] ;
void proc(){
	dp[1] =1;
	int res=-1;
	for(int i=2;i<=N;i++){
		dp[i]=1;//th co so rat quan trong  
		for(int j=1;j<=i-1;j++){
			if(a[i]>a[j]){
				dp[i] = max(dp[i],1+dp[j]);
			}
		}
		res=max(res,dp[i]);
	}
	cout<<"Do dai day con tang dai nhat la: "<<res;
}
int main(){
	cin>>N;
	for(int i=1;i<=N;i++)cin>>a[i];
	proc();
	return 0;
}

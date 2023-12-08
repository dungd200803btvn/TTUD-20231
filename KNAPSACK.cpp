#include<bits/stdc++.h>
using namespace std;


void Print(int n,int w ,vector<vector<int>>& dp,vector<pair<int,int>>& items){
	vector<int> best_items;
	while(n>0){
		if(dp[n][w]==dp[n-1][w]){
			--n;
		}else{
			best_items.push_back(n);
			w-= items[n].first;
			--n;
		}
		
	}
	for(int i=best_items.size()-1;i>=0;i--){
		cout<< best_items[i]<< " ";
	}
	
}

void solution(int n,int w,vector<pair<int,int>>& items){
	vector<vector<int>> dp(n+1,vector<int>(w+1,0)); // luu giu tong gia tri cua cac do vat
	for(int i=1;i<=n;i++){
		for(int j=0;j<=w;j++){
			dp[i][j] = dp[i-1][j];
			if(j>= items[i].first){
					dp[i][j] = max(dp[i][j],dp[i-1][j-items[i].first]+items[i].second);
			}
		}
	}
	cout<< dp[n][w]<<endl;
	
	Print(n,w,dp,items);
	
}
int main(){
	int n,w;
	cin>>n>>w;
	vector<pair<int,int>> items(n+1);
	for(int i=1;i<=n;i++){
		cin >> items[i].first >> items[i].second;
	}
	solution(n,w,items);
	
	
	return 0;
}

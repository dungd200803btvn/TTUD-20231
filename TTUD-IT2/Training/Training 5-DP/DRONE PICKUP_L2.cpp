#include<bits/stdc++.h>
using namespace std;
const int MAX=3001;
int N,K; //N la so diem tren duong thang ,K la so diem dung toi da
int a[MAX],c[MAX]; //mang a luu luong xang co the lay o moi diem,c luu luong hang co the lay o moi diem
int dp[MAX][102]={-1}; // luu luong hang max co the lay khi diem ket thuc la i va so lan dung la j 
void input(){
	cin>>N>>K;
	for(int i=1;i<=N;i++)cin>>c[i];
	for(int i=1;i<=N;i++)cin>>a[i];
}
void proc(){
	//init 
	dp[1][1]  =c[1];
	for(int i=1;i<=N;i++){
		for(int j=1;j<=K+1;j++){
			for(int k=i+1;k<=min(N,i+a[i]);k++){
					if(dp[k][j+1]<dp[i][j]+c[k]){
						dp[k][j+1] = dp[i][j]+c[k];
					}
			}
		
		}
	}
	int res=-1;
	for(int k=1;k<=K+1;k++){
		res = max(res,dp[N][k]);
	}
	if(res==-1)cout<<"route not exist"<<endl;
	cout<<"total max of goods is: "<<res;
	
}
int main(){
	freopen("drone_pickup.txt","r",stdin);
	input();
	proc();
	return 0;
} 

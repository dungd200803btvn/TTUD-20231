#include<bits/stdc++.h>
using namespace std;
int N,M;//N la so chi nhanh,M la so khach hang
const int MAX=105;
const int MOD=1e9+7;
int a[MAX];//luu so nhan vien cua moi chi nhanh 
//luong khach hang ma moi chi nhanh phuc vu chia het cho so nv chi nhanh do
int dp[MAX][MAX]; // xay dung bang voi i chi nhanh va phuc vu cho j khach hang
void input(){
	cin>>N>>M;
	for(int i=1;i<=N;i++)cin>>a[i];
	
}
void proc(){
	dp[0][0] =1;
	for(int i=1;i<=N;i++){
		for(int j=a[i];j<=M;j++){
//xay dung bai toan thu i bang cach gia su chi nhanh thu i se phuc vu x*a[i] khach,bai toan tro thanh dem voi con lai i-1 chi nhanh va k khach da co dc tu bang dp 			
			for(int k=j-a[i];k>=0;k-=a[i]){
					dp[i][j] = (dp[i][j]+dp[i-1][k])%MOD;
			}
		
		}
	}
	cout <<dp[N][M];
}
int main(){
	ios_base::sync_with_stdio(false);    cin.tie(0);
	input();
	proc();	
	return 0;
}

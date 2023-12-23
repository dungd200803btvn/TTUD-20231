#include<bits/stdc++.h>
using namespace std;
const int MAXW = 601;
const int MAXN =201;
int W,H,N;
int w[MAXN],h[MAXN],dp[MAXW][MAXW];
int main(){
	freopen("marble.txt","r",stdin);
	cin>>W>>H;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>w[i]>>h[i];
	}
	for(int i=1;i<=W;i++){
		for(int j=1;j<=H;j++){
			//init chua cat gi thi hcn[i][j] se co luong vut di = i*j
			dp[i][j] = i*j;
			
			//neu hcn con ma ta dang xet trung khit voi 1 trong cac phien da thi luong vut di =0
			for(int k=1;k<=N;k++){
					if(i == w[k] && j == h[k]){
						dp[i][j] =0;
					}
			}
			// cat khoi da hcn kich thuoc i*j nay theo chieu rong va chieu cao 
			for(int k=1;k<i;k++){
				dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k][j]);
			}
			for(int k=1;k<j;k++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]);
			}
		
		}
	}
	cout <<dp[W][H];
	return 0;
}

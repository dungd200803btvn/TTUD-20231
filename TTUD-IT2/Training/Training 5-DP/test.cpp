//C++ 
#include <bits/stdc++.h> 
using namespace std;
#define pii pair<int,int> 
const int MAX=1e6+4;
int a[MAX];
int n,m;
pii p[MAX];
int dp[MAX][20];//dp[i][j] luu phan tu nho nhat cua day con bat dau tu i va co do dai 2^j
void proc(){
		cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)dp[i][0] =a[i];
    //bat dau o chi so i va co chieu dai 2^j thi i ko the chay den n dc
    for(int j=1;(1<<j)<=n;j++){
            for(int i=0;i<n-(1<<j)+1;i++){
        	dp[i][j] = min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    			}	
        }
    
}
void resolve(){

    cin>>m;
    int res=0;
    for(int i=1;i<=m;i++){
    	int x,y;
        cin >>x>>y;
         int len = y-x+1; //chieu dai cua day con
        int k =(int) log2(len);
        res+= min(dp[x][k],dp[y-(1<<k)+1][k]);
    }
    cout <<res;
}
int main() 
{ 
freopen("rmq.txt","r",stdin);   
    proc();
    resolve();
return 0;
}

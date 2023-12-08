//Dem so xau nhi phan do dai n sao cho :
/*ko chua 2 so 0 lien tiep 
cac so 1 lien nhau co do dai >=k1 va <=k2 
dp(i,0) xau nhi phan do dai i ket thuc boi 0
dp(i,1)xau nhi phan do dai i ket thuc boi 1*/
#include<bits/stdc++.h>
const int N = 1e4+5;
int n,k1,k2;
int mem[N][2];
using namespace std;
int dp(int i,int wd){
	if(i==0 ) return mem[i][wd] =1;
	if(mem[i][wd]) return mem[i][wd];
	int res=0;
	if(!wd) {
		res = dp(i-1,1);
	}else{
		for(int j=i-k2;j<=i-k1;j++){
			if(j>=0 ) res+= dp(j,0);
		}
	}
	return mem[i][wd] = res;
}
int main(){
	memset(mem,0,sizeof(mem));
	cin>>n>>k1>>k2;
	cout << dp(n,0) + dp(n,1);
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
const int N =20;
int n;
int C[N][N],mem[N][1<<N];
int dp(int i,int S){
	if(S== (1<<n)-1) return mem[i][S] =C[i][0];
	if(mem[i][S]!=-1) return mem[i][S];
	int res =1e9;
	for(int j=1;j<=n;j++){
		if(S & (1<<j)) continue;
		res = min(res,C[i][j]+dp(j,S|(1<<j)));
	}
	return mem[i][S] =res;
}
void input(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>> C[i][j];
		}
	}
}
void trace(int i,int S){
		cout << i << " -> ";
	if(S==(1<<n)-1) cout << 0<<endl;

	for(int j=1;j<=n;j++){
		if(S & (1<<j)) continue;
		if(mem[i][S]== C[i][j]+ mem[j][S | (1<<j)]){
			trace(j,S | (1<<j));
			break;
		}
	}
}
int main(){
	memset(mem,-1,sizeof(mem));
	input();
	cout << dp(0,1) <<endl;
	trace(0,1);
	return 0;
}

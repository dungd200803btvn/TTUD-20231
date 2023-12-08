#include<bits/stdc++.h>
using namespace std;
#define MAX 100
vector<int> T[MAX];
int n,m;
int conflict[MAX][MAX];
int x[MAX]; 
int load[MAX];
int res =1e6;
int max_load=0;
void input(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		int k;cin>>k;
		for(int j=0;j<k;j++){
			int x;cin>>x;
			T[x].push_back(i);  //T luu cac gv i co the day mon x
		}
	}
	int sl;cin>>sl;
	for(int i=0;i<sl;i++){
		int a,b;cin>>a>>b;
		conflict[a][b]=1;
		conflict[b][a]=1;
	}
	
}
bool check(int v,int k){
	for(int i=1;i<=k-1;i++){
		if(x[i]==v && conflict[k][i])
		return false;
	}
	return true;
}
void solution(){
	int max_load=0;
	for(int i=1;i<=m;i++){
		max_load = max(load[i],max_load);
	}
		if(max_load<res){
			res= max_load;
		}
}
void Try(int k){
	for(int v:T[k]){
		if(check(v,k)){
			x[k]=v;
			load[v]+=1;
			if(k==n) solution();
			else{
				if(load[v]<res){
					Try(k+1);
				}
			}
			load[v]-=1;
		}
	}
}
int main(){
	input();
	Try(1);
	cout<<res;
	return 0;
}

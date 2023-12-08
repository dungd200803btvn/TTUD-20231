#include<bits/stdc++.h>
using namespace std;
int n,k ;// n:so hanh khach can van chuyen ,k la so hanh khach tren 1 xe
#define MAX 100 
vector<vector<int>> c(MAX,vector<int>(MAX,0));
vector<int> x(MAX),x_best(MAX);
vector<bool> visited(MAX,false);
int cost=0,best_cost=1e9;
int load=0;
int c_min = 1e9;
void enter(){
	cin>>n>>k;
	for(int i=0;i<=2*n;i++){
		for(int j=0;j<=2*n;j++){
			cin>>c[i][j];
			if(i!=j){
				c_min = min(c_min,c[i][j]);
			}
		}
	}

}
int check(int v){
	if(visited[v]){
		return 0;
	}if(v>n){
		if(!visited[v-n]){
			return 0;
		}
	}else{
		if(load+1>n){
			return 0;
		}
	}
	return 1;
}
void solution(){
	if(cost+ c[x[2*n]][0]< best_cost){
		best_cost = cost+ c[x[2*n]][0];
		for(int i = 0;i<=2*n;i++){
			x_best[i] = x[i];
		}
	}
}

void Try(int k){
	for(int v=1;v<=2*n;v++){
		if(check(v)){
			x[k] =v;
			cost+= c[x[k-1]][x[k]];
			if(v<=n) load++; // them khach len xe
			else load--; // tra khach xuong xe
			visited[v] = true;
			if(k==2*n) solution();
			else{
				if(cost+(2*n+1-k)*c_min< best_cost){
					Try(k+1);
				}
			}
			if(v<=n) load-=1;
			else load+=1;
			visited[v] = false;
			cost-=c[x[k-1]][x[k]];
		}
	}
}
int main(){
	enter();
	Try(1);
	cout << best_cost<<endl;
	return 0;
}

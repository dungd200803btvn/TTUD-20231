//code dang bi sai out put 
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int c[2*MAX+1][2*MAX+1];
int n,k1,cost,best_cost,load,c_min=1e6;
int x[MAX];
int x_best[MAX];
bool visited[MAX];
void input(){
	cin>>n>>k1;
	for(int i=0;i<=2*n;i++){
		for(int j=0;j<=2*n;j++){
			cin>>c[i][j];
			if(i!=j&& c[i][j]<c_min){
				c_min =c[i][j];
			}
		
		}
	}
}
bool check(int v,int k){
	if(visited[v] == true){
	 return false;
	 
	  }// tham 1 lan roi ko tham lai

	if(v>n ){
		if(!visited[v-n]){
			return false;
		}
	}else{
			if(load+1>k1) return false;  //qua tai loai
	}
	
	 //tra khach ma chua don khach do ko duoc
	return true;
}
void solution(){
	if(cost+c[x[2*n]][0]<best_cost){
		best_cost =cost+c[x[2*n]][0];
		for(int i=0;i<=2*n;i++) x_best[i] = x[i];
	}
}
void Try(int k){
	for(int v=1;v<=2*n;v++){
		if(check(v,k)){
			x[k]=v;
			cost+=c[x[k-1]][x[k]];
			if(v<=n) load+=1;	else load-=1;
		
			visited[v] = true;
			if(k==2*n) solution();
			else{
				if(cost+(2*n+1-k)*c_min<best_cost){
					Try(k+1);
				}
			}
			
					if(v<=n) load-=1;	else load+=1;
					
						visited[v] = false;
							cost-=c[x[k-1]][x[k]];
		}
	}
}
void solve(){
	load=0;
	cost=0;
	best_cost=1e6;
	for(int i=1;i<=2*n;i++){
		visited[i] =false;
	}
	x[0]=0;
	Try(1);
}
int main(){
	input();
	solve();
	cout << best_cost<<endl;
	
	return 0;
}




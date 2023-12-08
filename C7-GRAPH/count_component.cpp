#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
vector<int> adj[N];
vector<int> comp(N,-1);

int n,m,curID=1;
void input(){
	cin>>n>>m;
	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	}
void dfs(int u){
	comp[u] = curID;
	for(const int &v: adj[u]){
		if(comp[v]==-1){
			dfs(v);
		}
	}
	
	
}
int main(){
	
	input();
	for(int u=1;u<=n;u++){
		if(comp[u]==-1){
			dfs(u);
			curID++;
		} 
	}
	for(int u=1;u<=n;u++){
		cout << u << " " << comp[u] << endl;
	}
	return 0;
}




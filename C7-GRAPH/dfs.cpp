#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
vector<int> adj[N];
vector<bool> visited(N,false);
vector<bool> marked(N,false);
int n,m;
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
	cout << u<< " ";
	visited[u]=true;
	for(const int &v: adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
	
	
}
int main(){
	
	input();
	for(int u=1;u<=n;u++){
		if(!visited[u]) dfs(u);
	}
	return 0;
}




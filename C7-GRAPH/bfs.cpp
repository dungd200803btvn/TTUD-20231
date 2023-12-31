#include<bits/stdc++.h>
using namespace std;
const int N =1e4+5;
vector<int> adj[N];
vector<bool> visited(N,false);
int n,m;
queue<int> q;
void BFS(int start){
	q.push(start);
	visited[start] =true;
	while(!q.empty()){
		int u= q.front();
		q.pop();
		cout << u << " ";
		for(int v:adj[u]){
			if(!visited[v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
}
void input(){
	cin>>n>>m;
	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
}
int main(){
	freopen("data.txt","r",stdin);
	input();
	for(int u=1;u<=n;u++){
		if(!visited[u]) BFS(u);
	}
	return 0;
}

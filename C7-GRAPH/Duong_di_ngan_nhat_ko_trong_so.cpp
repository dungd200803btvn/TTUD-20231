#include<bits/stdc++.h>
using namespace std;
const int N =1e4+5;
vector<int> adj[N];
vector<int> visited(N,-1);
int n,m;
queue<int> q;

void BFS(int start){
	q.push(start);
	visited[start] =0;
	while(!q.empty()){
		int u= q.front();
		q.pop();
		cout << u << " "<< visited[u]<<endl;
		for(int v:adj[u]){
			if(visited[v]==-1){
				q.push(v);
				visited[v] = 1+visited[u];
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
		if(visited[u]==-1) BFS(u);
	}
	return 0;
}

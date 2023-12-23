//C++ 
#include <bits/stdc++.h> 
using namespace std;
typedef pair<int,int> pii;
const int MAX= 1e4+5;
const int INF =1e3;
int n,m;
int w[MAX][MAX],C[MAX],D[MAX];//ma tran chi phi cua do thi moi
vector<int> adj[MAX];//danh sach ke do thi cu
vector<int> dist(MAX,INF);
vector<int> edge_dist(MAX,-1);
vector<bool> visited(MAX,false);
void input(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>C[i]>>D[i];
    }
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
         adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            w[i][j] = i==j?0:INF;
        }
    }
}
void BFS(int i){
    queue<int> q;   
    visited.clear();
    edge_dist[i] =0;
    q.push(i);
    while(!q.empty()){
        int u =q.front();q.pop();
        visited[u] =true;
        for(const int &v: adj[u]){
            if(!visited[v]){
                edge_dist[v] =1+ edge_dist[u];
                if(edge_dist[v]<=D[i]){
                    w[i][v] = C[i];
                    q.push(v);
                }
            }
        }
    }
}
void display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << w[i][j] << " ";          
        }
        cout <<endl;
    }
}
void dijkstra(int s,int t){
priority_queue<pii,vector<pii>, greater<pii>> pq;
dist[s] =0;
pq.push(make_pair(0,s));
while(!pq.empty()){
	int u = pq.top().second;
	int weigth = pq.top().first;
	pq.pop();
	for(int v=1;v<=n;v++){
		if(w[u][v]!=INF && u!=v){
			if(dist[v]>dist[u]+w[u][v]){
				dist[v] = dist[u]+w[u][v];
				pq.push(make_pair(dist[v],v));
			}
		}
	}
	}
	cout << dist[t] <<endl;
}
int main() 
{ 
freopen("bus_inter_city.txt","r",stdin);
input();
for(int i=1;i<=n;i++) BFS(i);
dijkstra(1,n);
return 0;
}





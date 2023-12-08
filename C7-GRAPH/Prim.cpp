#include<bits/stdc++.h>
using namespace std;
const int N =1e4+5;
const int INF =1e9;
int n,m;
typedef pair<int,int> ii;
typedef struct edge{
	int u,v,w;
	edge(int u1,int v1,int w1){
		u=u1;
		v=v1;
		w=w1;
	}	
}edge;
vector<vector<edge>> adj(N);
void input(){
	cin>>n>>m;
	int u,v,w;
	for(int i=0;i<m;i++){
		cin>>u >>v>>w;
		adj[u].push_back(edge(u,v,w));
		adj[v].push_back(edge(v,u,w));
	}
}
vector<edge> prim(int start,const vector<vector<edge>> &adj){
	
	vector<bool> inTree(N,false);
	vector<int> dist(N,INF);// kc tu 1 dinh x den cay
	vector<int> near(N,-1); // dinh tren cay ke voi dinh dang xet
	dist[start]=0;// rat quan trong 
	vector<edge> res;
	while(res.size()<adj.size()-1){
		int u=-1,v=-1,minDist = INF;
		for(int x=1;x<=n;x++){
			if(!inTree[x] && dist[x] <minDist){
				minDist = dist[x];
				v=x;
				u=near[x];
			}
		}
		if(v==-1) return res;//ket thuc vong for ma ko tim dc v thi chung to ko lien thong dung thuat toan
		inTree[v] =true;
		// neu v=start thi u tren cay ke voi no la -1 se ko tao 1 canh trong loi giai
		if(v!=start) res.push_back(edge(u,v,minDist));
		for(const edge &e:adj[v]){
			int t =e .v ; // dinh thu 2 ke voi v
			int w = e.w; // trong so 
			if(!inTree[t] && dist[t] >w){
				dist[t] = w;
				near[t] = v;
			}
		}
	}
	return res;
}
vector<edge> primPQ(int start ,const vector<vector<edge>> &adj){
	priority_queue<ii,vector<ii>,greater<ii>> PQ;
	int n = adj.size()-1;
	vector<int> dist(N,INF);
	vector<int> near(N,-1);
	dist[start] =0;
	PQ.push(make_pair(0,start)); // first la kc den cay,second la dinh dang xet
	vector<edge> res;
	while(res.size()< n){
		//xoa dinh tan tich cua dinh nay nhung thuoc cac cay chua hoan chinh truoc do
		while(!PQ.empty() && PQ.top().first!= dist[PQ.top().second]){
			PQ.pop();
		}
		if(PQ.empty()) return res;
		int v = PQ.top().second;
		int min_dist = PQ.top().first;
		int u1 = near[v];
			PQ.pop();
		if(v!=start) res.push_back(edge(u1,v,min_dist));
		for(const edge &e: adj[v]){
			int u = e.v;
			int w = e.w;
			if(dist[u]>w) {
				dist[u] =w;
				near[u] =v;
				PQ.push(make_pair(dist[u],u));
			}
		}
	}
	return res;
}
int main(){
	freopen("data.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);	
	input();
	vector<edge> res = prim(1,adj);	
	for(const edge & e:res){
		cout << e.u << " "<<e.v<<" "<<e.w<<endl;		
	}	
	vector<edge> res1 = primPQ(1,adj);
		printf("Su dung PQ\n");
	for(const edge & e:res1){
		cout << e.u << " "<<e.v<<" "<<e.w<<endl;		
	}
	return 0;
}

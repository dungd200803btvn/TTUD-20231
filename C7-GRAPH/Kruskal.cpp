#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m;
typedef struct edge{
	int u,v,w;
	edge(int u1,int v1,int w1){
		u=u1;
		v=v1;
		w=w1;
	}	
}edge;
vector<edge> edges;
typedef struct UF{
	vector<int> parent;
	UF(int n){
		parent = vector<int>(n);
		for(int i=1;i<=n;i++) parent[i] =i;
	}
	int Find(int x){
		if(parent[x]==x) return x;
		return parent[x] = Find(parent[x]);
	}
	void Unite(int x,int y){
		parent[Find(x)] = Find(y);
	}
} UF;
bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}
vector<edge> Kruskal(int n,vector<edge> edges){
	sort(edges.begin(),edges.end(),cmp);
	UF uf(n);
	vector<edge> res;
	for(const auto &e : edges){
		int u = e.u;
		int v = e.v;
		int w = e.w;
		if(uf.Find(u)!=uf.Find(v)){
			res.push_back(e);
			uf.Unite(u,v);
		}
	}
	return res;
}
void input(){
	cin>>n>>m;
	int u,v,w;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		edges.push_back(edge(u,v,w));
		
	}
}
int main(){
	freopen("data.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	input();
	int ans=0;
	vector<edge> res = Kruskal(n,edges);
	for(const auto &e:res){
		ans+= e.w;
		cout << e.u << ' ' << e.v <<" " << e.w << endl;
	}
	cout << "MST " << ans <<endl;
	return 0;
}

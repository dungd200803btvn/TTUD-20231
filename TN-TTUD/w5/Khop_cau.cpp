#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
int n,m; //N dinh va M canh
vector<int> a[MAX];
int p[MAX],num[MAX],low[MAX],khop[MAX],cau[MAX],child[MAX];
bool visited[MAX];
int cur =0;
void input(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
}
void DFS(int u){
	cur++;
	num[u] = cur;
	low[u] = num[u];
	for(int i=0;i< a[u].size();i++){
		int v = a[u][i];
		if(v==p[u]) continue; // bo qua dinh v la cha cua u 
		if(num[v]){
			low[u] = min(low[u],num[v]); // neu u v la canh nguoc ta cap nhat low u 
		}else{
			p[v] =u;
			DFS(v);
			low[u] = min(low[u],low[v]); // cap nhat low u la gia tri min cua low cac con cua u
		}
	}
}
int main(){
//	freopen("khop_cau.txt","r",stdin);
	input();
	int anscau=0,anskhop=0;
	for(int i=1;i<=n;i++){
		if(!num[i])DFS(i);
		
	}
	for(int i=1;i<=n;i++){
		int v= p[i];
		if(v>0) child[v]++;
	}
	//dk khop: 
	for(int i=1;i<=n;i++){
		int u =p[i];
		if(u>0 && p[u]>0 && low[i]>=num[u])khop[u] =1;
	}
	for(int i=1;i<=n;i++){
		if(p[i]==0 && child[i]>=2)khop[i] =1;
	}
	for(int i=1;i<=n;i++){
		anskhop+= khop[i]==1;
	}
	for(int  i=1;i<=n;i++){
		if(p[i]!=0 && low[i]>=num[i])anscau++;
	}
	cout << anskhop<<" "<<anscau<<endl;
	return 0;
}

//C++ 
#include <bits/stdc++.h> 
using namespace std;
const int N =1e6+5;
int n,m,cur=0;
vector<int> adj[N];
int low[N];
vector<int> num(N,-1);
vector<bool> connect(N,false); 
int res=0;
void input(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
}

void scc(int u){
  stack<int> s;  //nhiem vu luu cac dinh cua tplt manh hien tai
    s.push(u);
    low[u] = num[u] =cur++;
    connect[u] = true;
    for(int x:adj[u]){
        if(num[x]==-1){
            scc(x);
            low[u] = min(low[u],low[x]);
        }else{
            if(connect[x]){
                low[u] = min(low[u],num[x]);
            }
            //day la 1 canh nguoc         
        }
    }
    //duyet het cay dfs goc u roi,neu num[u] = low[u] tuc la co chu trinh tuc la co thanh phan ltm
    if(low[u] == num[u]){
        res++;
        // xoa het toan bo cac dinh cua tplm nay ra khoi do thi de k anh huong den viec tinh
        // low cua cac dinh van con trong do thi
        while(true){
            int a = s.top();s.pop();
            connect[a] = false;
            if(a==u){
                break;
            }
        }
    }
}
int main() 
{ 
	freopen("tpltm.txt","r",stdin);
    input();
    for(int i=1;i<=n;i++){
        if(num[i]==-1)scc(i);
    }
    cout <<res;
return 0;
}


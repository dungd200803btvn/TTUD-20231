#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e4+5;

 struct Arc{
	int v,w;
	Arc(int _v,int _w){	
		v =_v;
		w = _w;	
	}

	
};
int duration[N],d[N],F[N];
vector<Arc> A[N];
vector<int> L;
int ans;
void input(){
	memset(d,0,sizeof(d));
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>duration[i];
	for(int k=1;k<=m;k++){
		int u,v;cin>>u>>v;
		A[u].push_back(Arc(v,duration[u]));
		d[v]++; //so cong viec phai thuc hien truoc khi lam v 
	}
}
void topoSort(){
	//ko tao chu trinh vi neu co chu trinh thi cv bi phu thuoc lan nhau dead lock
	//co  1 chuoi thu tu duyet cong viec dam bao thoi gian moi cv co the bat dau la som nhat  
	queue<int> q;
	for(int v=1;v<=n;v++){
		if(d[v]==0) {
			q.push(v);
		}
	}
	while(!q.empty()){
		int x =q.front();
		q.pop();
		L.push_back(x);
		for(int i =0;i<A[x].size();i++){
			int y = A[x][i].v;
			int w = A[x][i].w;
			d[y]--;
			if(d[y]==0)q.push(y);
		}
		
	}
}
void solve(){
	//F[v] luu thoi gian ngan nhat co the bat dau tien hanh cv v
	
	memset(F,0,sizeof(F));
	ans =0;
	for(int i=0;i<L.size();i++){
		int x = L[i];
		cout <<"Duyet den cong viec: "<<x<<endl; 
		ans = max(ans,F[x]+duration[x]); // can lay max de co the hoan thanh dc cong viec x va them cv x vao tap cv da hoan thanh
		cout <<"Cap nhat ans ="<< ans<<endl;
	cout << "Cap nhat cac dinh ke voi dinh hien tai"<<endl;	
		for(int j=0;j<A[x].size();j++){
			int v= A[x][j].v;
			int w = A[x][j].w;
			F[v] =max(F[v],F[x]+w);//F[v] la gia tri lon nhat cua thoi diem tat ca cac dk tien quyet cua v thuc hien xong 
			cout <<"F["<<v<<"] = "<<F[v]<<endl;
		}
	}
	cout << ans;
}
int main(){
	freopen("make-span-schedule.txt","r",stdin);
	input();
	topoSort();
	cout <<"Thu tu duyet topo la: "<<endl;
	for(int i=0;i<L.size();i++){
		cout << L[i] << " ";
	} 
	cout <<endl;
	solve();
	return 0;
}

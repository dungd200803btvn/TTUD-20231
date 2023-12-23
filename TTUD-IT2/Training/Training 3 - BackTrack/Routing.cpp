#include<bits/stdc++.h>
using namespace std;
int n,r;
const int MAX=101;
int c[MAX][MAX];
int c_min =1e6,f,f_min;
int x[MAX];
int len;
bool visited[MAX];
	vector<int> place;
bool check(int v,int k){
	// v ko phai la diem den ma chi la thu tu diem den tu 1 den len-1 
	if(visited[place[v]]){
		return false;
	}
	if(c[x[k-1]][place[v]]==0) return false;
	return true;
}
void init(){
	x[0] =place[0];
	x[len] =place[len];
	f=0;
	f_min =1e6;
	for(int i=0;i<=len;i++){
		cout <<place[i]<<" ";
	}
	for(int i=1;i<len;i++){
		visited[place[i]] =false;
	}
	cout<<endl;
}
void solution(){
	if(c[x[len-1]][place[len]]!=0){
		if(f+c[x[len-1]][place[len]]<f_min){
		f_min = f+c[x[len-1]][place[len]];
	}
	}
	
	return;
}
void Try(int k){
	for(int v=1;v<len;v++){
		if(check(v,k)){
			x[k] =place[v];
			visited[place[v]]=true;
			f+=c[x[k-1]][x[k]];
			if(k==len-1){
				solution();
			}else{
				if(f+c_min*(len-1-k)< f_min){
					Try(k+1);
				}
			}
			f-=c[x[k-1]][x[k]];
			visited[place[v]]=false;
		}
	}
}
int main(){
	freopen("routing.txt","r",stdin);
	cin>>n>>r;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(i!=j){
				c_min = min(c_min,c[i][j]);
			}
		}
	}
			string s;
			getline(cin,s);
	for(int i=1;i<=r;i++){
		place.clear();
		
		getline(cin,s);
		stringstream ss;
		ss<< s;
		while(!ss.eof()){
			int a;
			ss>>a;
			place.push_back(a);
		}
		 len = place.size()-1;
		 cout <<"Gia tri cua len "<<len<<endl;
		init();
		Try(1);
		
	
				cout<<f_min<<endl;
		
	
	}
	return 0;
} 

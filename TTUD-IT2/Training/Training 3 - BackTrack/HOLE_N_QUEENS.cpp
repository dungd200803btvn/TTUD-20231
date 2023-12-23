#include<bits/stdc++.h>
using namespace std;
const int N= 13;
int n,m;
bool h[N][N];//danh dau lo trong tren ban co
// a luu tong hang +cot cua 1 o,b luu hieu hang va cot cua 1 o
// neu 2 o bat ki trung a hoac b thi 2 o do nam tren cac duong cheo chinh hoac phu 
bool a[2*N],b[2*N],c[N];
int res;
void solution(){
	res++;
	return;
}
void Try(int k){
	//k la hang ,i la cot
	for(int i=0;i<n;i++){
		if(!c[i] && !h[k][i] && !a[k+i] && !b[k-i+n]){
			c[i] =a[k+i]=b[k-i+n]=true;
			if(k==n-1){
				solution();
			}else{
				Try(k+1);
			}
				c[i] =a[k+i]=b[k-i+n]=false;
		}
	}
}
int main(){
	freopen("hole_n_queen.txt","r",stdin);
	while(cin>>n>>m){
		if(n==0 && m==0)break;
					memset(a,0,sizeof(a));
					memset(b,0,sizeof(b));
					memset(c,0,sizeof(c));
					memset(h,0,sizeof(h));
		for(int i=0;i<m;i++){
			int x,y;cin>>x>>y;
			h[--x][--y] =true;
		}
		res=0;
		Try(0);
		cout<<res<<endl;
	}
	return 0;
}

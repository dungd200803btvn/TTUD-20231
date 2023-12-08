#include<bits/stdc++.h>
using namespace std;
#define MAX 23
	int n;
int c[MAX][MAX];
int x[MAX];
int f = 0;
int c_min = INT_MAX;
int f_min = INT_MAX;
bool visited[MAX];
void Try(int k){
	for(int v=1;v<=n;v++){ // cac hanh khach o thanh pho tu 1 den n va di den thanh pho i+n 
		if(!visited[v]){
			visited[v]=true;
			x[k]= v;
			x[k+1] =v+n;
			f+= c[x[k-1]][x[k]]+ c[x[k]][x[k+1]];
			if(k==2*n-1){ //vi khach cuoi cung phuc vu them 1 luot nua la dat 2n luot la ket thuc
			f_min = min(f_min,f+c[x[k+1]][0]);
			}else{
				if(f+(2*n-k)*c_min <= f_min){
					Try(k+2);
				}
			}
			visited[v]=false;
			f-= c[x[k-1]][x[k]]+ c[x[k]][x[k+1]];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>n;
	for(int i=0;i<2*n+1;i++){
		for(int j=0;j<2*n+1;j++){
			cin>>c[i][j];
			c_min = min(c_min,c[i][j]);
		}
		visited[i] =false;
	}
	x[0]=0; //taxi ban dau o thanh pho 0 
	
	Try(1);
	cout<< f_min<<endl;
	return 0;
}

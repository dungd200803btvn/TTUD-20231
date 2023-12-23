#include<bits/stdc++.h>
using namespace std;
int n,K,Q,segment,nbRoutes; //n la so khach ,K la so xe,Q la tai trong moi xe
const int MAX=20;
int d[MAX],load[MAX],x[MAX];// d la yeu cau cua moi khach 
int y[MAX];//luu diem den dau tien cua moi xe
bool visited[MAX];
int ans=0;
bool check(int i,int k){
	//i la 1 trong cac diem 0 den n,k la so thu tu cua xe
	if(i>0 && visited[i]){
		return false;
	}
	if(load[k]+d[i]>Q){
		return false;
	}
	return true;
}
void solution(){
	ans++;
	for(int i=1;i<=K;i++){
		cout << "Route["<<i<<"] is: 0->"<<" ";
		int s = y[i];
	
		for(int v=s;v!=0;v=x[v]){
			cout << v <<"-> ";
		}
		cout<<0<<endl;
	}
	cout<<endl;

}
void Try_X(int s,int k){
	for(int i=0;i<=n;i++){
	
		if(check(i,k)){
			x[s] = i;
			visited[i] =true;
			load[k]+=d[i];
			segment++;
			
			if(i>0){
				
				Try_X(i,k);
			}else{
				
				if((k==K) ){
					if(segment==nbRoutes+n){
							solution();
					}
				
				}else{
					Try_X(y[k+1],k+1);
				}
			}
				visited[i] =false;
			load[k]-=d[i];
			segment--;
		}
	}
}
int check1(int i,int k){
	 if(i == 0) return 1;
    if(load[k] + d[i] > Q) return 0;
    return !visited[i];
}
void Try_Y(int k){
	for(int i = y[k-1]+1;i<=n;i++){
		
		if(check1(i,k)){
				y[k] =i;
				visited[i] =true;
		load[k]+=d[i];
		segment++;
		if(k<K){
			
			Try_Y(k+1);
			
		}else{
			nbRoutes = segment;
			Try_X(y[1],1);
			
		}
			visited[i] =false;
				load[k]-=d[i];
				segment--;
		}
	}	
	}

int main(){
	freopen("cvrpcount.txt","r",stdin);
	cin>>n>>K>>Q;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	d[0] =0; 

	
	for(int i=1;i<=n;i++){
		visited[i] =false;
	}
	y[0] = 0;
	Try_Y(1);
	
	cout <<"So cach xep la: "<<ans;
	
	return 0;
}







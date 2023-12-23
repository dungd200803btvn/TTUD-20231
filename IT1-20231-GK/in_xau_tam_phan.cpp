#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int MAX=1005;
int x[MAX];
int n,cnt=0;
bool check(int i,int k){
	if(k>0 && (i==0 &&x[k-1]==0) || (i==1 && x[k-1]==1)){
		return false;
	}
	return true;
}
void print(){
	for(int i=0;i<n;i++){
		cout<< x[i] <<" ";
	}
	cout<<endl;
}
void solution(){
	cnt= (cnt+1)%MOD;
	print();
	return;
}
void Try(int k){
	for(int i=0;i<=2;i++){
		if(check(i,k)){
			x[k] = i ;
			if(k==n-1){
				solution();
			}else{
				Try(k+1);
			}
		}
	}
}
int main(){
	cin>>n;
	Try(0);
	cout<<cnt;
	return 0;
}

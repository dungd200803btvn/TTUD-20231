#include<bits/stdc++.h>
using namespace std;
int n,b;
const int MAX=31;
int a[MAX];
void input(){
	cin>>n>>b;
	for(int i=1;i<=n;i++)cin>>a[i];
}
void proc(int idx,int sum,int &cnt){
	if(idx==n+1){
		if(sum==b){
			cnt++;
		}
		return;
	}
	proc(idx+1,sum+a[idx],cnt);
	proc(idx+1,sum-a[idx],cnt);
	
}
int main(){
	freopen("giaipheptinh.txt","r",stdin);
	input();
	int cnt=0;
	proc(2,a[1],cnt);
	cout<<cnt;
	return 0;
}


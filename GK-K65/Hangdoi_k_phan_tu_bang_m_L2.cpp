#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+4;
int n,k,m;
int a[MAX];
	queue<int> q;
void print(int cnt){

	for(int i=cnt-k+1;i<=cnt;i++){
		cout <<a[i]<< " ";
	
	}
	cout<<endl;
}
int main(){
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	int sum=0,cnt=0;
	for(int i=1;i<=k;i++){
		sum+=a[i];
		q.push(a[i]);
	}
	if(sum==m)cnt++;print(k);
	for(int i=k+1;i<=n;i++){
		int x = q.front();
		sum-=x;
		q.pop();
		q.push(a[i]);
		sum+=a[i];
		if(sum==m)cnt++;print(i);
	}
	cout <<cnt;
	return 0;
}

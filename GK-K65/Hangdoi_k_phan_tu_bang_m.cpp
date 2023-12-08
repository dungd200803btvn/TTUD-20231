#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,m;
	cin>>n>>k>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	queue<int> q;
	int sum=0,cnt=0;
	for(int i=0;i<k;i++){
		int x = a[i];
		sum+=x;
		q.push(x);
	}
	if(sum==m) cnt++;
	for(int i=k;i<n;i++){
		sum-= q.front();
		q.pop();
		sum+=a[i];
		q.push(a[i]);
		if(sum==m) cnt++;
	}
	cout <<cnt<<endl;
		
	return 0;
}

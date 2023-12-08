#include<bits/stdc++.h>
using namespace std;
int n,b;
const int MAX=31;
int a[MAX];
vector<char> ch;
void print(){
	for(int i=0;i<n-1;i++){
		cout << a[i]<< ch[i];
	}
	cout << a[n-1] <<"="<<b<<endl;
	
}
void proc(int idx,int sum,int &cnt){
	if(idx==n){
		if(sum==b){
			cnt++;
		print();
		}
			return;
	}
	ch.push_back('+');
	proc(idx+1,sum+a[idx],cnt);
	ch.pop_back();
	ch.push_back('-');
	proc(idx+1,sum-a[idx],cnt);
	ch.pop_back();
}
int main(){
	freopen("giaipheptinh.txt","r",stdin);
	cin>>n>>b;
	for(int i=0;i<n;i++)cin>>a[i];
	int cnt=0;
	
	proc(1,a[0],cnt);
	cout<<cnt;
	return 0;
} 

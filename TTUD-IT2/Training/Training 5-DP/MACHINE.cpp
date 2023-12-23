#include<bits/stdc++.h>
using namespace std;
const int MAX=2e6+5;
int s[MAX],t[MAX];
int n;
int res = 0;
int max_x[MAX]={0};// luu doan dai nhat co the lay dc ma ket thuc o chi so<=x
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
			max_x[t[i]] = max(max_x[t[i]],t[i]-s[i]);//cap nhat tam thoi gia tri cua cac diem ket thuc cac doan la do dai doan do
	}
	for(int i=1;i<=MAX;i++){
	max_x[i] = max(max_x[i],max_x[i-1]);// vi t[i] gan dat den N nen ta can tinh den N
	}
	//xet lan luot tung doan, chung ta lay doan do cong voi doan dai nhat truoc do de dam bao chung ko overlap
	for(int i=1;i<=n;i++){
		if(max_x[s[i]-1]>0){
			res = max(res,t[i]-s[i]+max_x[s[i]-1]);
		}
	}
	if(res==0)cout<<-1;
	cout <<res;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+4;
int n;
int a[MAX];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int cnt=1;
	for(int i=2;i<=n;i++){
		if(a[i] <=a[i-1])cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}

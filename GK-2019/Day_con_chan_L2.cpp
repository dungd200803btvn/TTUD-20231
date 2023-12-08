#include<bits/stdc++.h>
using namespace std;
const int MAX =1e6+5;
int a[MAX],f[MAX],cnt=0;
void print(int i,int j){
	for(int k=i;k<=j;k++){
		cout << a[k] <<" ";
	}
	cout<<endl;
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[1]=a[1];
	for(int i=2;i<=n;i++){
		f[i] =a[i]+f[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum = f[j]-f[i-1];
			if(sum%2==0){
				++cnt;
				cout<<"Loi giai thu: "<<cnt<<endl;
				print(i,j);
			}
		}
	}
	cout<<cnt;
	return 0;
}

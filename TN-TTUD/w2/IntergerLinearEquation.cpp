#include<bits/stdc++.h>
using namespace std;
#define MAX 50
		int n,m;
		int a[MAX];
		int x[MAX];
		int t[MAX];
	int cnt=0,f=0;
void print(){
	cnt++;
/*	for(int i=1;i<=n;i++){
		cout<< x[i]<< " ";
	}
	cout << endl;*/
}
void check(){
	if(f==m){
		print();
		return;
	}
	return;
}
void Try(int k){
	for(int v=1;v<=(m-f-(t[n]-t[k]))/a[k];v++){
		x[k] =v;
		f=f+a[k]*x[k];
		if(k==n ){
		check();
		}else{
			Try(k+1);
		}
			f-=a[k]*x[k];
	}
}
void init(){
		cin>>n>>m;
t[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		t[i]=t[i-1]+a[i];
	}
}
int main(){
init();
Try(1);
cout<<cnt<<endl;
	return 0;
}

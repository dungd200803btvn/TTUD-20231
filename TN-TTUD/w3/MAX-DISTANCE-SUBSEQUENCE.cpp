#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int a[MAX];
int n,c;
int T;
bool check(int dis){
	int sl=1;
	int last=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-last >=dis){
			sl++;
			last = a[i];
		}
		if(sl>=c) return true; //du c phan tu thi true
	}
	return false; //ko du thi false
}
int MaxDistance(){
	int l=0; int r= a[n]-a[1]; //khoang cach ban dau
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid)) l=mid+1; //tang distance len 
		else r = mid-1; //giam distacne di
	}
	return r;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>c;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		cout << MaxDistance() <<endl;
		
	}
	return 0;
}

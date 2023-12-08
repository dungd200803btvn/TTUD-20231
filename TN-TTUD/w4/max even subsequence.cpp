#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
const int INF = -1e9;
int a[N];
long long s0[N],s1[N];
int n;
void input(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]%2==0){
		s0[1] = a[1];
		s1[1] =INF;
	}else{
		s1[1] = a[1];
			s0[1] =INF;
	}
}
int main(){
	input();
	for(int i=2;i<=n;i++){
		if(a[i]%2 ==0){
			if(s0[i-1]!=INF){
				s0[i] = max(s0[i-1]+a[i],a[i]);
			}else{
				s0[i] = a[i];
			}
			if(s1[i-1]!=INF){
				s1[i] = s1[i-1]+a[i];
			}else{
				s1[i] = INF;
			}
		}else{
			if(s0[i-1]!=INF){
				s1[i] = max(s0[i-1]+a[i],a[i]);
			}else{
				s1[i] = a[i];
			}
			if(s1[i-1]!=INF){
				s0[i] = s1[i-1]+a[i];
			}else{
				s0[i] = INF;
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(s0[i]>ans){
			ans  = s0[i];
		}
	}
	if(ans ==0){
		cout << "NOT_FOUND"<<endl;
	}
	cout <<ans<<endl;
	return 0;
}

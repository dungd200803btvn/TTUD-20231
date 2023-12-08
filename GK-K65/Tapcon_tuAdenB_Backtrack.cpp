#include<bits/stdc++.h>
using namespace std;
const int MAX =1e6+5;
int n,A,B;
int a[MAX];
int sum=0;
int cnt=0;
void Try(int k){
	for(int i=0;i<=1;i++){
		if(i){
			sum+=a[k];
			if(sum>=A && sum<=B)cnt++;
				if(k<n-1 && sum<=B) Try(k+1);
				sum-=a[k];
			
		}else{
			if(k<n-1) Try(k+1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>A>>B;
	for(int i=0;i<n;i++)cin>>a[i];
	Try(0);
	cout<<cnt;
	return 0;
}



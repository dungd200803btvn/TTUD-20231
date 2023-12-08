#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
pair<int,int> a[MAX];
bool compare(pair<int,int> a, pair<int,int> b){
	return a.second < b.second;
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin >>a[i].first >> a[i].second;
	}
	sort(a+1,a+n+1,compare);
	int res=0; int last=-1;
	for(int i=1;i<=n;i++){
		if(a[i].first > last){
			res++;
			last = a[i].second;
		}
	}
	cout <<res;
	return 0;
}

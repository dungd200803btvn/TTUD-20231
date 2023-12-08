#include<bits/stdc++.h>
using namespace std;
priority_queue<int>pq;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		pq.push(x);
	}
	string input;
	cin>>input;
	while(input!="*"){
		if(input=="insert"){
			int x;cin>>x;
			pq.push(x);
		}else{
			cout << pq.top()<<endl;
			pq.pop();
		}
		cin>>input;
	}
	return 0;
}

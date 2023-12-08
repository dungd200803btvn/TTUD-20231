#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		pq.push(x);
	}
	string input;
	cin>>input;
	while(input[0]!='*'){
		if(input== "insert"){
			int x;cin>>x;
			pq.push(x);
		}else{
			cout<< pq.top()<<endl;
			pq.pop();
		}
		cin>>input;
	}
	return 0;
}

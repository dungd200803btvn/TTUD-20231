#include<bits/stdc++.h>
using namespace std;
struct Compare{
bool operator()(int a,int b){
	return a>b;
}	
};
//mac dinh la giam dan
//muon tang dan thi khai bao ham greater co nghia tang dan hoac tu viet struct so sanh va ghi de phuong thuc operator 
priority_queue<int,vector<int>,greater<int>> pq;

int main(){
	freopen("priority_queue.txt","r",stdin);
	string input;cin>>input;
	while(input!="#"){
		if(input=="PUSH"){
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

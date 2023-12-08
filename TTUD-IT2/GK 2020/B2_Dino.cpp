#include<bits/stdc++.h>
using namespace std;
const int MAX= 1e5+5;
int p[MAX];
string s;
int n;
	queue<int> q;
	stack<int> st;
void input(){
	// nap du lieu vao stack de stack ko rong thi moi proc dc
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=n;i>=1;i--) st.push(p[i]);
	cin>>s;
	
}
void proc(){

	for(int i=0;i< s.size();i++){
		if(s[i]=='C'&& !st.empty()){
			int x = st.top();
			st.pop();
			q.push(x);
		}else{
			if(!q.empty()){
				int y = q.front();
				q.pop();
				st.push(y);
			}
		}
	}
	while(!st.empty()){
		int a = st.top();
		cout<< a << " ";
		st.pop();
	}	
}
int main(){
	input();
	proc();
	return 0;
}

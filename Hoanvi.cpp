#include<bits/stdc++.h>
using namespace std;
#define MAX 15
int n;
vector<bool> visited(MAX,false);
vector<int> x(MAX);
void print(){
for(int i=1;i<=n;i++){
	cout << x[i] << " ";
}
cout <<endl;
}
bool check(){
	for(int i=3;i<=n;i++){
		if(x[i]>x[i-1]&& x[i-1]>> x[i-2]){
			return false;
		}
	}
	return true;
}
void Try(int k){
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			x[k] =i;
			visited[i] = true;
			if(k==n){
				if(check()){
					print();
				}
				
			}else{
				Try(k+1);
			}
			visited[i] = false;
		}
	}
}
int main(){
	cin>>n;
	Try(1);
	return 0;
} 

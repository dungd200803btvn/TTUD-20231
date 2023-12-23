#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	vector<int> v;
	bool f=false;
	for(int i=0;i<m;i++){
		int x;cin>>x; 
		v.push_back(x);
	}
	if(v[m-1]<n){
		v[m-1]++;
		f=true;
	}else{
		for(int i=m-2;i>=0;i--){
			if(v[i] < v[i+1]-1){
				v[i]++;
			
				for(int j=i+1;j<m;j++){
					v[j] = v[j-1]+1;
				}
					f=true;
				break;
			}
		}
	}
	if(f){
		for(int i=0;i<m;i++){
			cout << v[i]<< " ";
		}
	}else{
		cout <<-1;
	}
	
	return 0;
}

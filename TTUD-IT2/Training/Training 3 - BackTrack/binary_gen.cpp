#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	string s;cin>>s;
	bool f = false;
	for(int i=n-1;i>=0;i--){
		if(s[i]=='0'){
			s[i] = '1';
			f= true;
			for(int j=i+1;j<n;j++){
				s[j] ='0';
			}
			break;
		}
	}
	if(f){
		cout<<s;
	}else{
		cout <<-1;
	}
	
	
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int compute(const string &s){
	int res=0,cur=0;
	if(s[0]=='+' ||s.back() == '+' || s.find("++")!=string::npos){
			cout<<"NOT_CORRECT"<<endl;
		return 0;
	}
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])){
			int num = s[i]-'0';
			while(i+1<s.length() && isdigit(s[i+1])) {
				num = num*10 + (s[++i] -'0');
			}
			cur = num;
			res = (res+cur)%MOD;
			
		}else if(s[i]=='+'){  
			continue;
		}else{			
			cout<<"NOT_CORRECT"<<endl;
			return 0;
		}
	}
	return res;
}
int main(){
	freopen("expression.txt","r",stdin);
	for(int i=0;i<5;i++){
		cout<<"Test case :" <<i+1<<endl;
		string s;cin>>s;
		cout<<"Bieu thuc la: "<<s<<" "<<"= "<<endl;
	int res =0;
	res = compute(s);
	if(res!=0){
			cout<<res;
	}
	}
	return 0;
} 

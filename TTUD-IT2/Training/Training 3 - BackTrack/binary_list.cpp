#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+4;
int N,K,I;
// liet ke xau nhi phan do dai n ma ko co i bit 0 lien tiep
// dua ra xau nhi phan thu k
int dem=0,cnt=0;
int x[MAX];
int t=0;
bool check(int v,int k){
	if(v==0 && dem+1==I)return false;
	return true;
}
void print(){
	for(int i=0;i<N;i++){
		cout << x[i]<<" ";
	}
	cout<<endl;
}
void solution(){
	cnt++;

	if(cnt==K){
			print();
			exit(0);
	}
}
void Try(int k){
	for(int v=0;v<=1;v++){
		if(check(v,k)){
			x[k] = v;
			if(v==0){
				dem++;
			}else{
				t=dem;
				dem=0;
			}
			if(k==N-1){
				solution();
			}else{
				Try(k+1);
			}
			if(v==0) dem--;else{
				dem =t;
			}
		}
	}
}
int main(){
	cin>>N>>K>>I;
	Try(0);
	if(cnt < K)cout<<-1;
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int MAX=10;
int x[MAX];
bool visited[MAX];
int cnt=0;
void print(){
	printf("1 no cua bai toan la: HUST=%d, SOICT = %d\n",x[0]*1000+x[1]*100+x[2]*10+x[3],x[2]*10000+x[4]*1000+x[5]*100+x[6]*10+x[3]);
}
void solution(int N){
	int hust = x[0]*1000+x[1]*100+x[2]*10+x[3];
	int soict = x[2]*10000+x[4]*1000+x[5]*100+x[6]*10+x[3];
	if(hust+soict==N){
		cnt++;
		print();
		return;
	}
	return;
}
bool check(int i,int a){
	// chu H va chu S la so hang lon nhat thi phai khac 0
	if(i==0 && (a==0||a==2)) return false;
	if(visited[i]) return false;
	return true;
}
void Try(int a,int N){
	for(int i=0;i<=9;i++){
		if(check(i,a)){
			x[a] =i;
			visited[i] = true;
			if(a==6){
				solution(N);
			}else{
				Try(a+1,N);
			}
				visited[i] = false;
		}
	}
}
int main(){
	int T;cin>>T;
	while(T--){
		int N;cin>>N;
		cnt =0;
		Try(0,N);
		cout<<cnt<<endl;
		
	}
	return 0;
}

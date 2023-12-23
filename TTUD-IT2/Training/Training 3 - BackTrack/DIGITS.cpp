#include<bits/stdc++.h>
using namespace std;
//ICT HUSK tuong ung x[0] den x[6]
//ICT-K62+HUST =n
int x[10];
bool visited[10];
int n;
int cnt=0;
void print(){
	cout << x[0]<<x[1]<<x[2]<<" - "<<x[6]<<6<<2<<" + "<<x[3]<<x[4]<<x[5]<<x[2]<<" = " <<n<<endl;
}
void solution(){
	int ict = x[0]*100+x[1]*10+x[2];
	int k62 = x[6]*100+62;
	int hust = x[3]*1000+x[4]*100+x[5]*10+x[2];
	if(ict-k62+hust==n){
		cnt++;
		print();
	}
	return;
}
void Try(int k){
	for(int i=1;i<=9;i++){
		if(!visited[i]){
			x[k] =i;
			visited[i] =true;
			if(k==6){
				solution();
			}else{
				Try(k+1);
			}
			visited[i] =false;
		}
	}
}
int main(){
	cin>>n;
	Try(0);
	cout<< cnt;
	return 0;
}

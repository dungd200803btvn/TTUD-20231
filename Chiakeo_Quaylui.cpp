#include<bits/stdc++.h>
using namespace std;
#define MAX 15
int m,n;
int cur=0,result=0;
vector<bool> visited(MAX,false);
vector<int> x(MAX);
void print(){
for(int i=1;i<=n;i++){
	cout << x[i] << " ";
}
cout <<endl;
}

void Try(int k){
	int start = k==n? m- cur:1; //nguoi cuoi cung thi lay toan bo so keo con lai neu khong thi lay tu 1 tro di 
	for(int i=start;i<= m-cur-(n-k);i++){ 
		x[k] =i;
		cur+= i;
		if(k==n){
			print();
			result++;
		}else Try(k+1);
		cur-=i;
	}
	
}
int main(){
	cin>>m>>n;
	Try(1);
	cout<< result<<endl;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+4;
int n,k,a[MAX],f[MAX];
double res = -100.0;
void input(){
		cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[1] =a[1];
	for(int i=2;i<=n;i++){
		f[i] =f[i-1]+a[i];
	}
}
void proc(){
	for(int i=1;i<=n-k;i++){
		for(int j=i+k-1;j<=n;j++){
			int sum = f[j]-f[i-1];
			double avg = 	(double)sum/(j-i+1);
			if(avg>res){
				res= avg;
			}
		}
	}
	printf("%.5lf",res);
}
int main(){
input();
proc();
	return 0;
}

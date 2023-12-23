#include<bits/stdc++.h>
const double M_PI = 3.1415926535897932384626433832795;
#include <cmath>
#define ld long double
using namespace std;
		//N la so chiec banh cung chieu cao nhung khac ban kinh
		//F la so nguoi ban 
		//Tong so nguoi la F+1(tinh ca minh),moi nguoi can co 1 mieng banh bang nhau va dien tich lon nhat
		const int MAX=10001;
		int N,F;
		int r[MAX];
		long double volume[MAX];//luu ban kinh,dien tich  cua nhung chiec banh	
		bool check(ld mid){
			int p=0;
			for(int i=1;i<=N;i++){
				p+=  volume[i]/mid;
			}
			if(p>F){
				return true;
			}else{
				return false;
			}
		
		}
		long double Compute(ld r1[]){
			ld l =0,r = volume[N],mid;
				while(r-l>=1e-6){
					mid = (l+r)/2;
					if(check(mid)){
						l =mid;
					}else{
						r=mid;
					}
				}
				return l;			
		}
int main(){
	freopen("pie.txt","r",stdin);
	int T;cin>>T;
	while(T--){
		cin>>N>>F;
		for(int i=1;i<=N;i++){
			cin>>r[i];
		}
		sort(r+1,r+N+1);
		for(int i=1;i<=N;i++){
			volume[i] = r[i]*r[i]* M_PI;			
		
		}
			printf("%.6Lf\n",Compute(volume)); 		
	}
	return 0;
}


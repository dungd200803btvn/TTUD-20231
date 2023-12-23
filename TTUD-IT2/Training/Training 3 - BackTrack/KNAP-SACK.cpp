#include<bits/stdc++.h>
using namespace std;
#define pdi pair<double,int>
const int MAX=31;
int n,b,b_k; // n la so do vat b la trong luong cai tui
int a[MAX],c[MAX]; // a la trong luong c la gia tri cua vat thu j 
int x[MAX],x_best[MAX];
int f,f_best=-1e9;
vector<pdi> v;
int A[MAX],C[MAX];
void input(){
	cin>>n>>b;

	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];  
	
		
	}
	for(int i=1;i<=n;i++){
			v.push_back(make_pair((1.0*c[i])/(1.0*a[i]),i));
	}
	sort(v.begin(),v.end(),greater<pdi>());
	for(int i=0;i<n;i++){
		A[i+1] = a[v[i].second];
		C[i+1] = c[v[i].second];
	}
		b_k =b;
	f=0;
	f_best=0;
}
void solution(){
	if(f>f_best){
		f_best =f;
	for(int i=1;i<=n;i++){
		x_best[i] = x[i];
	}
	}
		return ;
}
void Try(int k){
	int t_k =0;
	cout << "b_k hien tai "<<b_k<<"  C[k] hien tai: "<<C[k]<<endl; 
	if(b_k >= A[k]){
		t_k =1;
	}
	cout << "t_k hien tai "<<t_k<<endl;
	for(int i=0;i<=t_k;i++){
		x[k] = i;
		b_k-=A[k]*x[k];
		f+= C[k]*x[k];
		cout << "b_k hien tai "<<b_k<<"  f hien tai: "<<f<<endl; 
		if(k==n){
			solution();
		}else{
			
			if(f + C[k+1]*ceil((1.0*b_k)/ (1.0*A[k+1])) > f_best){
				Try(k+1);
			}
		}
			b_k+=A[k]*x[k];
		f-= C[k]*x[k];	
			
	}
	
}
int main(){
	freopen("knapsack.txt","r",stdin);
	input();
	Try(1);
	cout<<f_best<<endl;
	for(int i=1;i<=n;i++){
		cout << x_best[i] <<" ";
	}
	cout <<endl;
	return 0;
}

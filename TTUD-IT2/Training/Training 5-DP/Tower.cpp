#include<bits/stdc++.h>
using namespace std;
const int MAX=100;
//co toi da 30 khoi da,moi khoi da khi xoay tao ra 3 dang khac nhau nen max=90
typedef struct block{
	int x,y,z;
}block;
block a[MAX];
int d;

int dp(int i,int d){
	//chon khoi da thu i lam dinh chop
	int kq =a[i].z;
	//duyet tat ca cac khoi con lai xem khoi nao co the xep o duoi cua i thi ta cap nhat chieu cao
	for(int k=1;k<=3*d;k++){
		if(a[k].x >a[i].x && a[k].y > a[i].y|| 
			a[k].x >a[i].y && a[k].y > a[i].x){
				kq = max(kq,a[i].z+dp(k,d));
			}
	}
	return kq;
	
}
void proc(int d,int cnt){
	int res=0;
	//thu lan luot tat ca cac khoi lam dinh,xep thap va so sanh chieu cao toi uu
	for(int i=1;i<=3*d;i++){
		res = max(res,dp(i,d));
	}
	 printf("Case %d: maximum height = %d\n", cnt++, res);
}
void input(){
	cin>>d;
	int cnt=1;
	while(d!=0){
		for(int i=1;i<=d;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[3*i-2].x =x;
			a[3*i-2].y =y;
			a[3*i-2].z =z;
			a[3*i-1].x =y;
			a[3*i-1].y =z;
			a[3*i-1].z =x;
			a[3*i].x =z;
			a[3*i].y =x;
			a[3*i].z =y;
		}
		proc(d,cnt);
		cnt++;
		cin>>d;
		
	}
}
int main(){
	input();
	return 0;
}

//C++ 
#include <bits/stdc++.h> 
using namespace std;
int N,K1,K2;
const int MAX= 1005;
const int MOD=1e9+7;
long long s0[MAX],s1[MAX];
//s0[i] la cach xep ngay cuoi cung la ngay thu i la ngay nghi  
//s1[i] la cach xep ngay cuoi cung la ngay thu i la ngay lam viec

int main() 
{ 
    cin>>N>>K1>>K2;
    for(int i=0;i<=N;i++){
        s0[i] = 0;
        s1[i] =0;
    }
    s0[1] =1;
    s1[K1] =1;
    s0[0] =1;
//vi lam viec thi can it nhat K1 ngay nen ta chi can xep lich voi K1+1 tro di
for(int i=K1+1;i<=N;i++){
    s0[i] = s1[i-1]; s1[i] =0;
    for(int j=K1;j<=K2;j++){
        if(i-j>=0){
             s1[i] = (s1[i]+s0[i-j])%MOD;
        }
       
    }
}
long long res= (s0[N]+s1[N])%MOD;
cout <<res;
return 0;
}

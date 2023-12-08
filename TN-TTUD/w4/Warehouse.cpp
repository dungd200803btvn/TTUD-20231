//C++ 
#include <bits/stdc++.h> 
using namespace std;
int N,T,D;
const int MAX =1005;
int a[MAX],t[MAX];
int f[MAX][MAX];
long long res=0;
void input(){
    cin>>N>>T>>D;
    for(int i=1;i<=N;i++)cin>>a[i];
      for(int i=1;i<=N;i++)cin>>t[i];
}

void proc(){
    for(int i=1;i<=N;i++){
        for(int j=t[i];j<=T;j++){
            for(int k = max(0,i-D);k<i;k++){
                f[i][j] = max(f[i][j],f[k][j-t[i]]+a[i]);
            }
            res= max(res,f[i][j]);
        }
    }
    cout <<res<<endl;
}
int main() 
{ 
input();
proc();
return 0;
}

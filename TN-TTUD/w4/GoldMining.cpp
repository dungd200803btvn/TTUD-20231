#include <bits/stdc++.h> 
using namespace std;
const int MAX= 1e6+5;
int n,L1,L2;
int a[MAX];
long long res=0;
long long F[MAX];//F[i] la luong vang lon nhat khi ket thuc o nha kho i
void input(){
    cin>>n>>L1>>L2;
    for(int i=1;i<=n;i++)cin>>a[i];
}
void resolve(){
    deque<int> d; // hang doi loai bo cac phan tu qua xa i o dau va cac phan tu ko tot hon F[j] o cuoi de hang doi ko qua dai
    F[1]=a[1];
    for(int i=2;i<=n;i++){
        while(!d.empty()&& d.front() < i-L2) d.pop_front();
        int j= i-L1;
        if(j>=1){
            while(!d.empty()&& F[d.back()] < F[j]) d.pop_back();
            d.push_back(j);
        }
        F[i] = a[i]+ (d.empty()? 0: F[d.front()]);
        res = max(res,F[i]);
    }
    cout <<res<<endl;
}
int main() 
{ 
input();
resolve();
return 0;
}


#include <bits/stdc++.h> 
using namespace std;
#define MAX 1000005
const int MOD =1e9+7;
int a[MAX];
int tmp[MAX];//mang tam thoi 
int n;
int Merge(int l,int m,int r){ 
    int k=l, i=l,j=m+1,cnt=0;
    while(i<=m && j<=r){
        if(a[i]<=a[j]){
            tmp[k++] = a[i++]; //copy a[i] vao tmp truoc
        }else{
             tmp[k++] = a[j++];
             cnt = (cnt+ m-i+1)%MOD; // tu a[i] den a[m] tao m-i+1 cap nghich the so voi a[j]
        }
    }
    while(i<=m){
        tmp[k++] = a[i++];
    }while(j<=r){
        tmp[k++] = a[j++];
    }
    for(int i=l;i<=r;i++){
        a[i] =tmp[i];
    }
    return cnt;
}
int MergeSort(int l,int r){
    int cnt=0;
    int mid;
    if(l<r){
         mid = (l+r)/2;
         cnt = (cnt+MergeSort(l,mid)) %MOD;
           cnt= (cnt+MergeSort(mid+1,r)) %MOD;
           cnt = (cnt+Merge(l,mid,r)) %MOD;
    }
    return cnt; 
}
int main() 
{ 
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
cout<<MergeSort(1,n);
return 0;
}

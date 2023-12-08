#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	vector<int> a(n);
		vector<int> Trace(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> L(n,1); // th co so : khi chon 1 phan tu duy nhat 
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				L[i] = max(L[i],L[j]+1); // L[i] la day con tang dai nhat ma ket thuc o chi so i,
										//neu a[i] lon hon 1 trong cac so dung truoc cta dang xet,cta them a[i] vao day con ket thuc tai j va cap nhat gia tri moi cho L[i]
			}
		}
	}
	cout << *max_element(L.begin(),L.end())<<endl;
	return 0;
}



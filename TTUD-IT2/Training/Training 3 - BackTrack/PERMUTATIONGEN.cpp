#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	// Tim phan tu dau tien tu phai qua trai ma v[i] <v[i+1]
	int i = n-2;
	while(i>=0 && v[i]>v[i+1])i--;
	// hoan vi sap xep theo thu tu giam dan -> cuoi cung roi thi k the tim hoan vi tiep theo
	if(i<0){
	cout<<-1;
	return 0;
	}
	
	//Tim cach tang v[i] len 1 cach it nhat: tu phai qua trai tim phan tu dau tien >v[i]
	int j = n-1;
	while(v[j]<v[i])j--;
	swap(v[i],v[j]);
	// vi tu i+1 den n-1 van dang giam dan nen can dao nguoc de thanh tang dan 
	reverse(v.begin()+i+1,v.end());
	for(int i=0;i<v.size();i++){
		cout << v[i]<<" ";
	}
	return 0;
}



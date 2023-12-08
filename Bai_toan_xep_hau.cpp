#include<bits/stdc++.h>
using namespace std;
int a[100];
int n;
int result=0;
bool OK(int row,int col){
	for(int i=1;i<=row-1;i++){
		if(a[i]==col || abs(row-i)== abs(a[i]-col)){  // neu con hau hien tai cung cot hoac trung duong cheo voi 1 trong so cac con hau truoc do thi ko xep dc 
			return false;
		}
	}
	return true;
}
void print(){
	for(int i=1;i<=n;i++){
		cout << a[i] << " ";
	}
	cout<<endl;
	result++;
}
void SolveQueen(int row){
	for(int col=1;col<=n;col++){
		if(OK(row,col)){
			a[row]=col;
			if(row==n) print();
			SolveQueen(row+1);
		}
	}
}
int main(){
	cin>>n;
	SolveQueen(1);
	cout<< result<<endl;
	return 0;
}

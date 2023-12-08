#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4+5;
int n, a[MAX];
int mem[MAX];
int dp(int i){
	if(mem[i] != -1) return mem[i];
	int res = 1;
	for(int j = 1; j < i; j++){
		if(a[j] < a[i]){
			res = max(res, 1 + dp(j));
		}
	}
	return mem[i] = res;
}
int pos = -1;
int solve(){
	int ans = 1;
	for(int i = 1; i <= n; i++){
		if(ans < dp(i)){
			ans = dp(i);
			pos = i;
		}
	}
	return ans;
}
void trace(int i){
	for(int j = 1; j < i; j++){
		if(mem[i] == 1 + mem[j] && a[j] < a[i]){
			trace(j);
			break;
		}
	}
	cout << a[i] << " ";
}

int main(){
	memset(mem, -1, sizeof(mem));
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	cout << solve() << endl;
	trace(pos);
	return 0;
}


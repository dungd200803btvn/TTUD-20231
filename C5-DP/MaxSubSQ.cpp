/*#include<bits/stdc++.h>
using namespace std;
#define MAX 1001
int a[MAX],mem[MAX];
int n;
int dp(int i){
	if(i==1) return a[1];
	if(mem[i]!=-1) return mem[i];
	int res = max(a[i],a[i]+mem[i-1]);
	return mem[i] =res;
}
int pos =-1;
int solve(){
		dp(n-1);
	int ans =0;
	for(int i=0;i<n;i++){
		ans = max(ans,mem[i]);
		if(ans == mem[i]) pos=i;
	}
	return ans;
}
void trace(int i){
	if(i<1)  return;
	if(mem[i]==a[i]+mem[i-1]){
		trace(i-1);
	}
	cout << a[i] << " ";
}
int main(){
cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	memset(mem,-1,sizeof(mem));

	int result = solve();
cout<< result<<endl;
	cout <<"Truy vet" <<endl;
	

	return 0;
}*/


#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int a[MAX], mem[MAX];
int n;

int dp(int i) {
    if (i == 0) return a[0];
    if (mem[i] != -1) return mem[i];
    int res = max(a[i], a[i] + dp(i - 1));
    return mem[i] = res;
}

int pos = -1;

int solve() {
    dp(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans < mem[i]) {
            ans = mem[i];
            pos = i;
        }
    }
    return ans;
}

void trace(int i) {
    if (i < 0) return;
    if (i == 0 || mem[i] == a[i] + mem[i - 1]) {
        trace(i - 1);
    }
    cout << a[i] << " ";
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(mem, -1, sizeof(mem));

    int result = solve();
    cout << result << endl;
    cout << "Truy vet: ";
    trace(pos); // Fix this line to use 'pos' instead of 'n-1'

    return 0;
}


/*#include<bits/stdc++.h>
using namespace std;

int maxLeft(const vector<int>& arr,int l,int r){
	int lSum =0,sum =0;
	for(int i=r;i>=l;i--){
		sum+=arr[i];
		lSum = max(sum,lSum);
	}
	return lSum;
}
int maxRight(const vector<int>& arr,int l,int r){
	int lSum =0,sum =0;
	for(int i=l;i<=r;i++){
		sum+=arr[i];
		lSum = max(sum,lSum);
	}
	return lSum;
}
int SubSQMAX(const vector<int>& arr,int l,int r){
	if(l==r){
		return arr[l];
	}
	int mid = (l+r)/2;
	int wl = SubSQMAX(arr,l,mid);
	int wr = SubSQMAX(arr,mid+1,r);
	int wm = maxLeft(arr,l,mid) + maxRight(arr,mid+1,r);
	return max(max(wl,wr),wm);
}
int main(){
	
	int n;	cin>>n;
	vector<int> arr(n);

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int result = SubSQMAX(arr,0,arr.size()-1);
	cout << result<<endl;
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;

int maxLeft(const vector<int>& arr, int l, int r) {
    int lSum = 0, sum = 0;
    for (int i = r; i >= l; i--) {
        sum += arr[i];
        lSum = max(sum, lSum);
    }
    return lSum;
}

int maxRight(const vector<int>& arr, int l, int r) {
    int lSum = 0, sum = 0;
    for (int i = l; i <= r; i++) {
        sum += arr[i];
        lSum = max(sum, lSum);
    }
    return lSum;
}

int SubSQMAX(const vector<int>& arr, int l, int r) {
    if (l == r) {
        return arr[l];
    }
    int mid = (l + r) / 2;
    int wl = SubSQMAX(arr, l, mid);
    int wr = SubSQMAX(arr, mid + 1, r);
    int wm = maxLeft(arr, l, mid) + maxRight(arr, mid + 1, r);
    return max(max(wl, wr), wm);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n); // C?p phát b? nh? cho vector arr

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = SubSQMAX(arr, 0, arr.size() - 1);
    cout << result << endl;
    
    return 0;
}


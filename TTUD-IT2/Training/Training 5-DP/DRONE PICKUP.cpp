
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int x;
	int max1;	
	freopen("drone_pickup.txt","r",stdin);
    int N, K;
    cin >> N >> K;
    vector<int> c(N + 1), a(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    int dp[N+1][K+2] = {-1};
    // Base case: Stopping at point 1
    dp[1][1] = c[1];
 	cout<< "Diem dung dau tien la diem: "<<1 <<" la diem dung thu "<<1<<" luong hang lay duoc la "<<c[1]<<" "<<endl;
    for (int i = 1; i <= N; ++i) {
        for (int k = 1; k <= K+1; ++k) {
            // Continue without stopping     
			 if (dp[i][k] != -1) {
                cout << "Diem dung tiep theo la diem: " << i << " la diem dung thu " << k << " luong hang lay duoc la " << dp[i][k] << " " << endl;
            }
            // Try stopping at j, where j is between i and i+a[i]
            for ( int j = i + 1; j <= min(N, i + a[i]); ++j) {
                
                if(dp[j][k + 1]<dp[i][k] + c[j]){
                	 dp[j][k + 1] = dp[i][k] + c[j];
                	  //cout<< "Diem dung tiep theo la diem: "<<j <<" la diem dung thu "<<k+1<<" luong hang lay duoc la "<<dp[j][k + 1]<<" "<<endl;
				}
               
            }
           
        }
    }
    int max_goods = -1;
    // Find the maximum goods among the possible routes
    for (int k = 1; k <= K+1; ++k) {
        max_goods = max(max_goods, dp[N][k]);
    }

    if (max_goods == -1) {
        cout << "No route exists." << endl;
    } else {
        cout << "Tong luong hang thu duoc lon nhat la: " <<max_goods << endl;
    }

    return 0;
}




#include<bits/stdc++.h>
using namespace std;
int findMaxSum(const std::vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 0);
    if (n == 1) {
        return a[0];
    } 
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);
    for (int i = 2; i < n; ++i) {
        dp[i] =max(dp[i - 1], dp[i - 2] + a[i]);
    }   
    return dp[n - 1];
}

int main() {
    int n;
	cin >> n;
    if (n <= 0) {
        cout << "Day rong, tong la 0." << std::endl;
        return 0;
    }

    std::vector<int> a(n);
    std::cout << "Nh?p các s? nguyên dýõng c?a d?y: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int maxSum = findMaxSum(a);

    std::cout << "T?ng l?n nh?t c?a t?p con không ch?a 2 ph?n t? liên ti?p: " << maxSum << std::endl;

    return 0;
}


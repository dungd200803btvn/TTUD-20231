#include <iostream>
#include <vector>

using namespace std;

bool isEven(int num) {
    return num % 2 == 0;
}

void printSubarray(const vector<int>& a, int i, int j) {
    for (int k = i; k < j; k++) {
        cout << a[k] << " ";
    }
    cout << endl;
}
int result=0;
void  countAndPrintEvenSubarrays(const vector<int>& a) {
    int n = a.size();
    
    
    // T?o m?t m?ng prefixSum ð? tính t?ng tích l?y
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + a[i];
    }
    
    // Duy?t qua t?t c? c?p (i, j) ð? xem có d?y con nào có t?ng là s? ch?n không
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int subarraySum = prefixSum[j] - prefixSum[i];
            if (subarraySum % 2 == 0) {
                printSubarray(a, i, j);
                result++;
            }
        }
    }
    cout << "Tong so day con chan la: " << result<<endl;
}

int main() {
    int n;
    cout << "Nh?p ð? dài c?a d?y s? a: ";
    cin >> n;
    
    vector<int> a(n);
    cout << "Nh?p các ph?n t? c?a d?y a: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
      
    
    cout << "Các d?y con ch?n trong d?y a là: " << endl;
  countAndPrintEvenSubarrays(a);
    
    return 0;
}


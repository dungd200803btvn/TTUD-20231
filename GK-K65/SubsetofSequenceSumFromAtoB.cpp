


#include <iostream>
#include <vector>

using namespace std;

// Hàm ð? quy ð? t?o và ð?m các t?p con th?a m?n ði?u ki?n
int countSubsets(vector<int>& arr, int n, int A, int B, int idx, int sum) {
    // N?u ð? duy?t h?t t?t c? ph?n t?
    if (idx == n) {
        // Ki?m tra xem t?ng c?a t?p con có n?m trong kho?ng [A, B] hay không
        if (sum >= A && sum <= B) {
            return 1;
        } else {
            return 0;
        }
    }

    // Trý?ng h?p 1: Không bao g?m ph?n t? t?i v? trí idx
    int count1 = countSubsets(arr, n, A, B, idx + 1, sum);

    // Trý?ng h?p 2: Bao g?m ph?n t? t?i v? trí idx
    int count2 = countSubsets(arr, n, A, B, idx + 1, sum + arr[idx]);

    // T?ng s? t?p con th?a m?n ði?u ki?n
    return count1 + count2;
}

int main() {
    int n, A, B;
   
    cin >> n>>A>>B;

    vector<int> arr(n);

    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

  

    int totalSubsets = countSubsets(arr, n, A, B, 0, 0);
    cout << "S? t?p con th?a m?n ði?u ki?n là: " << totalSubsets << endl;

    return 0;
}



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// H�m t�nh giai th?a
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// H�m t?m ho�n v? th? k
vector<int> kthPermutation(int n, int k) {
    vector<int> permutation;
    vector<int> numbers;

    // Kh?i t?o vector ch?a c�c s? t? 1 �?n n
    for (int i = 1; i <= n; ++i) {
        numbers.push_back(i);
    }

    // Gi?m gi� tr? c?a k �? t�nh ch? s? t? 0
    k--;

    // X�y d?ng ho�n v? th? k
    for (int i = n - 1; i >= 0; --i) {
        int index = k / factorial(i);
        k %= factorial(i);
        permutation.push_back(numbers[index]);
        numbers.erase(numbers.begin() + index);
    }

    return permutation;
}

int main() {
    int n, k;
    cin >> n >> k;

    // Ki?m tra xem k c� h?p l? kh�ng
    if (k > factorial(n)) {
        cout << -1;
    } else {
        // T?m v� in ra ho�n v? th? k
        vector<int> result = kthPermutation(n, k);
        for (int i = 0; i < n; ++i) {
            cout << result[i] << " ";
        }
    }

    return 0;
}


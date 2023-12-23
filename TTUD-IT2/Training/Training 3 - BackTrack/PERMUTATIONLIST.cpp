#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tính giai th?a
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Hàm t?m hoán v? th? k
vector<int> kthPermutation(int n, int k) {
    vector<int> permutation;
    vector<int> numbers;

    // Kh?i t?o vector ch?a các s? t? 1 ð?n n
    for (int i = 1; i <= n; ++i) {
        numbers.push_back(i);
    }

    // Gi?m giá tr? c?a k ð? tính ch? s? t? 0
    k--;

    // Xây d?ng hoán v? th? k
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

    // Ki?m tra xem k có h?p l? không
    if (k > factorial(n)) {
        cout << -1;
    } else {
        // T?m và in ra hoán v? th? k
        vector<int> result = kthPermutation(n, k);
        for (int i = 0; i < n; ++i) {
            cout << result[i] << " ";
        }
    }

    return 0;
}


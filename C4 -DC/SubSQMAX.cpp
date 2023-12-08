#include <iostream>
#include <vector>

using namespace std;

// Hàm tính t?ng l?n nh?t c?a ðo?n con ch?a ph?n t? gi?a left và right
int maxCrossingSum(const vector<int>& arr, int left, int mid, int right) {
    // Tính t?ng c?a ðo?n con bên trái c?a mid
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= left; --i) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    // Tính t?ng c?a ðo?n con bên ph?i c?a mid
    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; ++i) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    // T?ng c?a ðo?n con l?n nh?t ch?a mid
    return left_sum + right_sum;
}

// Hàm chính t?m ðo?n con l?n nh?t trong m?ng
int findMaxSubarraySum(const vector<int>& arr, int left, int right) {
    if (left == right) {
        // Trý?ng h?p cõ s?: M?ng ch? có m?t ph?n t?
        return arr[left];
    }

    // T?m ph?n t? gi?a m?ng
    int mid = (left + right) / 2;

    // T?m ðo?n con l?n nh?t ? ba trý?ng h?p:
    // 1. Trong ðo?n con bên trái c?a mid
    // 2. Trong ðo?n con bên ph?i c?a mid
    // 3. G?m c? mid
    int left_max = findMaxSubarraySum(arr, left, mid);
    int right_max = findMaxSubarraySum(arr, mid + 1, right);
    int crossing_max = maxCrossingSum(arr, left, mid, right);

    // Tr? v? t?ng l?n nh?t c?a ba trý?ng h?p trên
    return max(max(left_max, right_max), crossing_max);
}

int main() {
    vector<int> arr = {-2, 11, -4, 2, -3, -10};  // Ví d? v? m?t m?ng

    int maxSum = findMaxSubarraySum(arr, 0, arr.size() - 1);

    cout << "Ðo?n con l?n nh?t có t?ng là: " << maxSum << endl;

    return 0;
}


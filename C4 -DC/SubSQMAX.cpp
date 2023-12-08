#include <iostream>
#include <vector>

using namespace std;

// H�m t�nh t?ng l?n nh?t c?a �o?n con ch?a ph?n t? gi?a left v� right
int maxCrossingSum(const vector<int>& arr, int left, int mid, int right) {
    // T�nh t?ng c?a �o?n con b�n tr�i c?a mid
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= left; --i) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    // T�nh t?ng c?a �o?n con b�n ph?i c?a mid
    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; ++i) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    // T?ng c?a �o?n con l?n nh?t ch?a mid
    return left_sum + right_sum;
}

// H�m ch�nh t?m �o?n con l?n nh?t trong m?ng
int findMaxSubarraySum(const vector<int>& arr, int left, int right) {
    if (left == right) {
        // Tr�?ng h?p c� s?: M?ng ch? c� m?t ph?n t?
        return arr[left];
    }

    // T?m ph?n t? gi?a m?ng
    int mid = (left + right) / 2;

    // T?m �o?n con l?n nh?t ? ba tr�?ng h?p:
    // 1. Trong �o?n con b�n tr�i c?a mid
    // 2. Trong �o?n con b�n ph?i c?a mid
    // 3. G?m c? mid
    int left_max = findMaxSubarraySum(arr, left, mid);
    int right_max = findMaxSubarraySum(arr, mid + 1, right);
    int crossing_max = maxCrossingSum(arr, left, mid, right);

    // Tr? v? t?ng l?n nh?t c?a ba tr�?ng h?p tr�n
    return max(max(left_max, right_max), crossing_max);
}

int main() {
    vector<int> arr = {-2, 11, -4, 2, -3, -10};  // V� d? v? m?t m?ng

    int maxSum = findMaxSubarraySum(arr, 0, arr.size() - 1);

    cout << "�o?n con l?n nh?t c� t?ng l�: " << maxSum << endl;

    return 0;
}


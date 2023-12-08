#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    // �?c d?y x1, x2, ..., xn
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    // �?c ma tr?n chi ph� d
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
        }
    }

    int m;
    cin >> m;

    // �?c c�c r�ng bu?c i, j
    vector<pair<int, int>> constraints(m);
    for (int i = 0; i < m; ++i) {
        cin >> constraints[i].first >> constraints[i].second;
    }


    // Ki?m tra c�c r�ng bu?c i, j
    for (const auto& constraint : constraints) {
        int i = constraint.first - 1;
        int j = constraint.second - 1;
        if (find(x.begin(), x.end(), i + 1) > find(x.begin(), x.end(), j + 1)) {
            cout << -1 << endl;
            return 0;
        }
    }

    // T�nh t?ng chi ph�
    int totalCost = 0;
    for (int i = 0; i < n - 1; ++i) {
        totalCost += d[x[i] - 1][x[i + 1] - 1];
    }

    // C?ng chi ph� t? �i?m cu?i v? �i?m �?u
    totalCost += d[x[n - 1] - 1][x[0] - 1];

    cout << totalCost << endl;

    return 0;
}


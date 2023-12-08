#include <iostream>
#include <vector>

using namespace std;

void solve(int index, vector<int> &sequence, vector<char> &operators, int target, int current, int &count) {
    if (index == sequence.size()) {
        if (current == target) {
            count++;
            for (int i = 0; i < sequence.size() - 1; i++) {
                cout << sequence[i] << operators[i];
            }
            cout << sequence.back() << " = " << target << endl;
        }
        return;
    }

    operators.push_back('+');
    solve(index + 1, sequence, operators, target, current + sequence[index], count);
    operators.pop_back();

    operators.push_back('-');
    solve(index + 1, sequence, operators, target, current - sequence[index], count);
    operators.pop_back();
}

int main() {
		freopen("giaipheptinh.txt","r",stdin);
    int n, b;
    cout << "Nh?p s? ph?n t? trong d?y (2 <= n <= 30): ";
    cin >> n;
    cout << "Nh?p giá tr? b: ";
    cin >> b;

    vector<int> sequence(n);
    cout << "Nh?p " << n << " ph?n t? c?a d?y: ";
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    vector<char> operators;
    int count = 0;
    solve(0, sequence, operators, b, 0, count);
cout<< count<<endl;
    if (count == 0) {
        cout << "Không có l?i gi?i nào." << endl;
    }

    return 0;
}


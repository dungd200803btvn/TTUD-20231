
#include <iostream>
#include <vector>
using namespace std;
void solve(int index, vector<int> &sequence, int target, int current, int &count) {
    if (index == sequence.size()) {
        if (current == target) {
            count++;
        }
        return;
    }

    // Th? thêm s? dýõng
    solve(index + 1, sequence, target, current + sequence[index], count);
    
    // Th? thêm s? âm
    solve(index + 1, sequence, target, current - sequence[index], count);
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

    int count = 0;
    solve(1, sequence, b,sequence[0], count); 

    cout << "S? l?i gi?i: " << count << endl;

    return 0;
}



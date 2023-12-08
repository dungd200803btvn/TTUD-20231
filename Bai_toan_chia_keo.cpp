#include <iostream>
#include <vector>

using namespace std;
int result=0;
void generateSolutions(int n, int M, vector<int>& solution, int currentSum, int currentPos) {
    if (currentPos == n) {
        if (currentSum == M) {
          
            cout << "Nghiem: ";
            for (int i = 0; i < n; i++) {
                cout << solution[i] << " ";
            }
            cout << endl;
            result++;
        }
        return;
    }

 	
    for (int i = 1; i <= M - currentSum; i++) {
        solution[currentPos] = i;
        generateSolutions(n, M, solution, currentSum + i, currentPos + 1);
    }
}

int main() {
    int n, M;
    cout << "Nhap so bien (n): ";
    cin >> n;
    cout << "Nhap tong (M): ";
    cin >> M;

    vector<int> solution(n);

    generateSolutions(n, M, solution, 0, 0);
		cout<< "So ket qua la: " << result<<endl;
    return 0;
}


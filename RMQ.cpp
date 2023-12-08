#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int a[MAX];
int M[MAX][20];
//M[i][j] de tim min trong day bat dau tu cho so i va co chieu dai 2^j
//Dung pp chia doi de tim min cua day o nua trai va phai
void process(int n) {
    for (int i = 0; i < n; i++) {
        M[i][0] = a[i];
      //  cout << "M[" << i << "][0] la: " << M[i][0] << endl;
    }
    for (int j = 1; (1 << j) <= n; j++) { //chay den khi 2^j ==n thi dung k can chay j qua lon
        for (int i = 0; i + (1 << j) - 1 < n; i++) {  // chay den khi chi so bat dau + chieu dai mang dang xet ==n-1 thi dung
            M[i][j] = min(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]); //chia doi trai phai
         //   cout << "M[" << i << "][" << j << "] la: " << M[i][j] << endl;
        }
    }
}

int main() {
    long long result = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    process(n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        int k = (int)log2(r - l + 1); //tinh xau chieu dai k du phu het l va r 
    //    cout << "Gia tri cua k la " << k << endl;
        result += min(M[l][k], M[r - (1 << k) + 1][k]); // chia nua trai phai de quet het chieu rong tu l den r 
        // vi du l=1 r=15 k = 3 thi quet tu 1->8 va 8->15
      //  cout << "Ket qua hien tai la: " << result << endl;
    }
    cout << result << endl;
    return 0;
}


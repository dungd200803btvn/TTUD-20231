#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX_N = 11;
const int MAX_K = 10;
const int INF = 1e9 ;// A high value to represent infinity

int n, k;
vector<vector<int>> c(2 * MAX_N, vector<int>(2 * MAX_N, 0));
vector<vector<vector<int>>> dp(MAX_N, vector<vector<int>>(1 << MAX_N, vector<int>(MAX_N, -1)));

int tsp(int u, int mask, int passengers) {
    if (mask == (1 << n) - 1) {
        return c[u][0]; // Return to the starting point
    }
    
    if (dp[u][mask][passengers] != -1) {
        return dp[u][mask][passengers];
    }
    
    int ans = INF;
    for (int v = 1; v <= n; v++) {
        if (!(mask & (1 << (v - 1))) && passengers < k) {
            int new_mask = mask | (1 << (v - 1));
            ans = min(ans, c[u][v] + tsp(v, new_mask, passengers + 1));
        }
    }
    dp[u][mask][passengers] = ans;
    return  ans;
}

int main() {
    cin >> n >> k;

    // Read the distance matrix
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * n + 1; j++) {
            cin >> c[i][j];
        }
    }

    int shortest_route = tsp(0, 0, 0);
    cout << shortest_route << endl;

    return 0;
}


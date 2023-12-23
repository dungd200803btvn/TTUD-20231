#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int n, K, Q;
vector<int> d;
vector<vector<int>> c;
vector<vector<int>> best_routes;
int best_distance = INF;

void branchAndBound(int truck, vector<vector<int>>& routes, vector<bool>& visited, int current_distance) {
    if (truck == K) {
        // T?t c? c�c xe t?i �? ��?c g�n ��?ng �i, c?p nh?t gi?i ph�p t?t nh?t
        if (current_distance < best_distance) {
            best_distance = current_distance;
            best_routes = routes;
        }
        return;
    }

    for (int client = 1; client <= n; ++client) {
        if (!visited[client]) {
            int remaining_capacity = Q - d[client];
            if (remaining_capacity >= 0) {
                // G�n kh�ch h�ng v�o ��?ng �i c?a xe t?i hi?n t?i
                visited[client] = true;
                routes[truck].push_back(client);

                // Recursively explore the next truck
                branchAndBound(truck + 1, routes, visited, current_distance + c[0][client]);

                // Backtrack
                visited[client] = false;
                routes[truck].pop_back();
            }
        }
    }
}

int main() {
    // Nh?p d? li?u
    cin >> n >> K >> Q;
    d.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }

    c.resize(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cin >> c[i][j];
        }
    }

    // Kh?i t?o
    vector<vector<int>> routes(K);
    vector<bool> visited(n + 1, false);

    // Gi?i quy?t b�i to�n s? d?ng ph��ng ph�p Branch and Bound
    branchAndBound(0, routes, visited, 0);

    // Xu?t k?t qu?
    cout << best_distance << endl;

    return 0;
}


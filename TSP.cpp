#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define START 0

int n;
vector<int> tp;
vector<vector<int>> a;
vector<bool> visited;
int minCost = INT_MAX;
vector<vector<int>> minCostPaths;

struct Constraint {
    int i;
    int j;
};

vector<Constraint> constraints;

bool checkConstraints(vector<Constraint>& constraints) {
    for (const Constraint& constraint : constraints) {
        int i = constraint.i - 1;
        int j = constraint.j - 1;
        int idx_i = -1;
        int idx_j = -1;

        // Find positions of i and j in the tour
        for (int idx = 0; idx < n; idx++) {
            if (tp[idx] == i) {
                idx_i = idx;
            } else if (tp[idx] == j) {
                idx_j = idx;
            }
        }

        // If i does not come before j, return false
        if (idx_i > idx_j) {
            return false;
        }
    }
    return true;
}

void print() {
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        int from = tp[i];
        int to = tp[(i + 1) % n];
        totalCost += a[from][to];
        cout << from + 1 << " -> ";
    }
    cout << START + 1 << " (Total Cost: " << totalCost << ")" << endl;
}

void travel(int idx) {
    if (idx == n) {
        int totalCost = 0;
        if (checkConstraints(constraints)) {
            for (int i = 0; i < n; i++) {
                int from = tp[i];
                int to = tp[(i + 1) % n];
                totalCost += a[from][to];
            }
            if (totalCost < minCost) {
                minCost = totalCost;
                minCostPaths.clear();
                minCostPaths.push_back(tp);
            } else if (totalCost == minCost) {
                minCostPaths.push_back(tp);
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && a[tp[idx - 1]][i] > 0) {
            tp[idx] = i;
            visited[i] = true;
            travel(idx + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;

    tp.resize(n);
    visited.resize(n, false);
    a.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
 int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        constraints.push_back({u, v});
    }
    
    
    tp[0] = START;
    visited[START] = true;

   

    travel(1);

    if (minCost == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << "Minimum Cost: " << minCost << endl;
        cout << "Paths with Minimum Cost:" << endl;
        for (const vector<int>& path : minCostPaths) {
            tp = path;
            print();
        }
    }

    return 0;
}


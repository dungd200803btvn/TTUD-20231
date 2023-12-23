#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

struct State {
    int n, K, Q;
    vector<int> d, y, load, x;
    vector<vector<int>> c;
    int segment, nbRoute, res;
    vector<bool> visited;
};

void input(State &state) {
    cin >> state.n >> state.K >> state.Q;
    state.d.resize(state.n + 1);
    state.c.resize(state.n + 1, vector<int>(state.n + 1));

    state.d[0] = 0;

    for (int i = 1; i <= state.n; i++) {
        cin >> state.d[i];
    }

    for (int i = 0; i <= state.n; i++) {
        for (int j = 0; j <= state.n; j++) {
            cin >> state.c[i][j];
        }
    }
}

bool check1(State &state, int v, int k) {
    if (v > 0 && state.visited[v]) return false;
    if (state.load[k] + state.d[v] > state.Q) return false;
    return true;
}

void solution(State &state) {
    int f = 0;

    for (int k = 1; k <= state.K; k++) {
        int s = state.y[k];
        f += state.c[0][s];
        int t = s; // t luu vi tri hien tai

        for (int v = s; v != 0; v = state.x[v]) {
            f += state.c[t][v];
            t = v;
        }

        f += state.c[t][0];
    }

    state.res = min(state.res, f);
}

void Try_X(State &state, int s, int k) {
    for (int v = 0; v <= state.n; v++) {
        if (check1(state, v, k)) {
            state.x[s] = v;
            state.load[k] += state.d[v];
            state.segment++;
            state.visited[v] = true;

            if (v > 0) {
                // chua quay ve diem ban dau tuc la hanh trinh cua xe k chua ket thuc
                Try_X(state, v, k);
            } else {
                if (k == state.K) {
                    if (state.segment == state.n + state.nbRoute) {
                        solution(state);
                    }
                } else {
                    Try_X(state, state.y[k + 1], k + 1);
                }
            }

            state.load[k] -= state.d[v];
            state.segment--;
            state.visited[v] = false;
        }
    }
}

bool check(State &state, int v, int k) {
    if (state.visited[v]) return false;
    if (state.load[k] + state.d[v] > state.Q) return false;
    return true;
}

void Try_Y(State &state, int k) {
    for (int v = state.y[k - 1] + 1; v <= state.n; v++) {
        if (check(state, v, k)) {
            state.y[k] = v;
            state.visited[v] = true;
            state.load[k] += state.d[v];
            state.segment++;

            if (k < state.K) {
                Try_Y(state, k + 1);
            } else {
                state.nbRoute = state.segment;
                Try_X(state, state.y[1], 1);
            }

            state.visited[v] = false;
            state.load[k] -= state.d[v];
            state.segment--;
        }
    }
}

void solve(State &state) {
    state.visited.resize(state.n + 1, false);
    state.y.resize(state.K + 1);
    state.load.resize(state.K + 1);
    state.x.resize(state.n + 1);

    state.y[0] = 0;
    Try_Y(state, 1);
    cout << state.res;
}

int main() {
		freopen("cvrp.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    State state;
    input(state);
    solve(state);

    return 0;
}


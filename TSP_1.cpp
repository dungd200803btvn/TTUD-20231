#include <bits/stdc++.h>
#define int long long
#define task "tsp."
#define inf 1e9 + 7

using namespace std;

const int maxn = 21;
int n, current_cost, best_cost;
int visited[maxn], x_best[maxn], x[maxn], c[maxn][maxn];

void enter()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];
    x[1] = 1;
    visited[1] = 1;
    best_cost = inf;
}


void update_best_solution(int current_cost)
{
    if (current_cost + c[x[n]][1] < best_cost)
    {
        best_cost = current_cost + c[x[n]][1];

        for (int i = 1; i <= n; ++i)
            x_best[i] = x[i];
    }
}


void print_best_solution()
{
     cout << best_cost << endl;

     for (int i = 1; i <= n; ++i)
        cout << x_best[i] << "->";
     cout << 1;
}

// GiaÒi thuâòt nhaình vaÌ câòn.
void branch_and_bound(int i)
{
    if (current_cost >= best_cost)
        return;

    for (int j = 2; j <= n; ++j)
        if (!visited[j])
        {
            visited[j] = 1;
            x[i] = j;
            current_cost += c[x[i - 1]][j];

            // ÐaÞ sinh xong môòt câìu hiÌnh, câòp nhâòt chi phiì tôìt nhâìt.
            if (i == n)
                update_best_solution(current_cost);
            // Chýa sinh xong, tiêìp tuòc sinh thaÌnh phâÌn tiêìp theo võìi chi phiì tãng thêm.
            else
                branch_and_bound(i + 1);

            visited[j] = 0;
            current_cost -= c[x[i - 1]][j];
        }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    enter();
    branch_and_bound(2);
    print_best_solution();

    return 0;
}


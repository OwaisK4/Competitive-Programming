#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define MOD 1000000007
using namespace std;
using pii = pair<int, int>;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void print(vector<T> &array, int size = numeric_limits<int>::max()) {
    for (int i = 0; i < min<int>(size, array.size()); i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}
template <typename T>
void print(T X) {
    cout << X << "\n";
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<int> gorillas(w);
    for (int i = 0; i < w; i++) {
        cin >> gorillas[i];
    }
    sort(all(gorillas), greater<int>());
    vector<vector<int>> diff_matrix(n, vector<int>(m, 0));
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         diff_matrix[i][j] = 0;
    //     }
    // }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x1, y1, x2, y2;
            x1 = i;
            y1 = j;
            x2 = x1 + k - 1;
            y2 = y1 + k - 1;
            if (x2 >= n || y2 >= m) {
                continue;
            }
            diff_matrix[x1][y1]++;
            if (x2 + 1 < n)
                diff_matrix[x2 + 1][y1]--;
            if (y2 + 1 < m)
                diff_matrix[x1][y2 + 1]--;
            if (x2 + 1 < n and y2 + 1 < m)
                diff_matrix[x2 + 1][y2 + 1]++;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            diff_matrix[i][j] += diff_matrix[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            diff_matrix[i][j] += diff_matrix[i][j - 1];
        }
    }

    vector<int> grid_counts;
    for (int i = 0; i < n; i++) {
        // print(diff_matrix[i]);
        for (int j = 0; j < m; j++) {
            grid_counts.push_back(diff_matrix[i][j]);
        }
    }
    sort(all(grid_counts), greater<int>());

    int answer = 0;
    int i = 0, j = 0;
    while (i < gorillas.size() && j < grid_counts.size()) {
        answer += (gorillas[i] * grid_counts[j]);
        i++;
        j++;
    }
    cout << answer << "\n";
}

signed main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
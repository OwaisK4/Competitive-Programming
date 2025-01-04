#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

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

int n, m;
vector<vector<char>> matrix;
vector<vector<bool>> visited;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i];
        int b = y + dy[i];
        if (a >= 0 && a < n && b >= 0 && b < m && matrix[a][b] == '.' && !visited[a][b]) {
            dfs(a, b);
        }
    }
}

signed main() {
    fastio;
    cin >> n >> m;
    matrix.assign(n, vector<char>(m, ' '));
    visited.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}
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
using pii = pair<int, int>;

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

vector<vector<int>> lake;
vector<vector<bool>> visited;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

bool isSafe(int x, int y, int n, int m) {
    if (x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == false && lake[x][y] != 0) {
        return true;
    }
    return false;
}

int dfs(int x, int y, int n, int m) {
    visited[x][y] = true;
    int answer = lake[x][y];
    for (int i = 0; i < 4; i++) {
        if (isSafe(x + dx[i], y + dy[i], n, m)) {
            answer += dfs(x + dx[i], y + dy[i], n, m);
        }
    }
    return answer;
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        lake.assign(n, vector<int>(m, 0));
        visited.assign(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> lake[i][j];
            }
        }
        int maximum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && lake[i][j] != 0) {
                    int depth = dfs(i, j, n, m);
                    maximum = max(maximum, depth);
                }
            }
        }
        cout << maximum << "\n";
    }

    return 0;
}
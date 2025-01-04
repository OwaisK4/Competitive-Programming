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

int n, m, a, b;
int x_start, y_start;
int x_end, y_end;
vector<vector<char>> matrix;
vector<vector<char>> visited;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<char> direction = {'U', 'D', 'L', 'R'};

signed main() {
    fastio;
    cin >> n >> m;
    matrix.assign(n, vector<char>(m, ' '));
    visited.assign(n, vector<char>(m, '#'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'A') {
                x_start = i;
                y_start = j;
            } else if (matrix[i][j] == 'B') {
                x_end = i;
                y_end = j;
            }
        }
    }
    // for (auto &it : matrix) {
    //     print(it);
    // }
    queue<pair<int, int>> q;
    q.push({x_start, y_start});
    visited[x_start][y_start] = 'X';
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            a = x + dx[i];
            b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && matrix[a][b] != '#' && visited[a][b] == '#') {
                q.push({a, b});
                visited[a][b] = direction[i];
            }
        }
    }
    // for (auto &it : visited) {
    //     print(it);
    // }

    if (visited[x_end][y_end] != '#') {
        cout << "YES\n";
        string path;
        char parent;
        int x = x_end;
        int y = y_end;
        parent = visited[x][y];
        while (parent != 'X') {
            path += parent;
            int change = find(all(direction), parent) - direction.begin();
            x -= dx[change];
            y -= dy[change];
            parent = visited[x][y];
        }
        reverse(all(path));
        cout << path.size() << "\n";
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
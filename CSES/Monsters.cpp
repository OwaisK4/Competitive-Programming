#include <bits/stdc++.h>
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
int x_start, y_start;
vector<vector<char>> matrix;
vector<vector<int>> dist;
vector<vector<char>> previous;
vector<pair<int, int>> monsters;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<char> direction = {'L', 'R', 'U', 'D'};

signed main() {
    fastio;
    cin >> n >> m;
    matrix.assign(n, vector<char>(m, ' '));
    dist.assign(n, vector<int>(m, INT_MAX));
    previous.assign(n, vector<char>(m, 'X'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'A') {
                x_start = i;
                y_start = j;
            } else if (matrix[i][j] == 'M') {
                monsters.push_back({i, j});
            }
        }
    }
    queue<pair<pair<int, int>, int>> q;
    int x, y, cnt;
    for (auto &it : monsters) {
        x = it.first;
        y = it.second;
        cnt = 0;
        q.push({{x, y}, cnt});
        dist[x][y] = cnt;
    }
    while (!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        cnt = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int a = x + dy[i];
            int b = y + dx[i];
            if (a >= 0 && a < n && b >= 0 && b < m && (matrix[a][b] == '.' || matrix[a][b] == 'A') && cnt + 1 < dist[a][b]) {
                dist[a][b] = cnt + 1;
                q.push({{a, b}, cnt + 1});
            }
        }
    }
    // for (auto &it : dist) {
    //     for (auto &jt : it) {
    //         if (jt != INT_MAX)
    //             cout << jt << " ";
    //         else
    //             cout << 'X' << " ";
    //     }
    //     cout << "\n";
    // }

    x = x_start;
    y = y_start;
    cnt = 0;

    q.push({{x, y}, cnt});
    previous[x][y] = 'A';
    while (!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        cnt = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int a = x + dy[i];
            int b = y + dx[i];
            char move = direction[i];
            if (a >= 0 && a < n && b >= 0 && b < m && matrix[a][b] == '.' && previous[a][b] == 'X' && cnt + 1 < dist[a][b]) {
                q.push({{a, b}, cnt + 1});
                previous[a][b] = move;
            }
        }
    }
    // cout << "\n";
    // for (auto &it : previous) {
    //     print(it);
    // }
    bool found = false;
    int i, j;
    if (!found)
        for (i = 0; i < n; i += n - 1) {
            for (j = 0; j < m; j++) {
                if (previous[i][j] != 'X') {
                    // cout << "Found = " << i << ", " << j << "\n";
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
    if (!found)
        for (j = 0; j < m; j += m - 1) {
            for (i = 0; i < n; i++) {
                if (previous[i][j] != 'X') {
                    // cout << "Found = " << i << ", " << j << "\n";
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
    if (found) {
        // cout << "x = " << i << ", y = " << j << "\n";
        cout << "YES\n";
        string path;
        char parent = previous[i][j];
        while (parent != 'A') {
            path += parent;
            int index = find(all(direction), parent) - direction.begin();
            i -= dy[index];
            j -= dx[index];
            parent = previous[i][j];
        }
        reverse(all(path));
        print(path.size());
        print(path);
    } else {
        cout << "NO";
    }

    return 0;
}
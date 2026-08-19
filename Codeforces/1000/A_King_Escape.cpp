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

vector<vector<int>> board;
vector<bool> visited;
vector<int> dx = {1, -1, 0, 0, -1, -1, 1, 1};
vector<int> dy = {0, 0, -1, 1, -1, 1, -1, 1};

bool isSafe(int x, int y, int n) {
    if (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == 0) {
        return true;
    }
    return false;
}

void queenMoves(int a, int b, int n) {
    board[a][b] = 1;
    for (int i = 0; i < dx.size(); i++) {
        int x = a, y = b;
        while (isSafe(x + dx[i], y + dy[i], n)) {
            board[x + dx[i]][y + dy[i]] = 1;
            x += dx[i];
            y += dy[i];
        }
    }
}

void dfs(int x, int y, int n) {
    board[x][y] = 2;
    for (int i = 0; i < dx.size(); i++) {
        if (isSafe(x + dx[i], y + dy[i], n)) {
            dfs(x + dx[i], y + dy[i], n);
        }
    }
}

signed main() {
    fastio;
    int n;
    cin >> n;
    board.assign(n, vector<int>(n, 0));
    visited.assign(n, false);

    int ax, bx, cx;
    int ay, by, cy;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;

    ax--;
    ay--;
    bx--;
    by--;
    cx--;
    cy--;

    // board[bx][by] = 2;
    // board[cx][cy] = 3;

    queenMoves(ax, ay, n);
    dfs(bx, by, n);
    // for (auto &it : board) {
    //     print(it);
    // }
    if (board[cx][cy] == 2) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
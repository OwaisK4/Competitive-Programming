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

void solve() {
    vector<int> board(101, -1);
    vector<int> ladders(101, -1);
    vector<int> snakes(101, -1);
    int n, m;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ladders[a] = b;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        snakes[a] = b;
    }

    board[0] = 0;
    board[1] = 0;
    for (int i = 1; i < 100; i++) {
        if (board[i] == -1) {
            continue;
        }
        for (int k = 1; k <= 6; k++) {
            if (i + k > 100) {
                break;
            }
            if (ladders[i + k] != -1) {
                if (board[ladders[i + k]] == -1) {
                    board[ladders[i + k]] = board[i] + 1;
                } else {
                    board[ladders[i + k]] = min(board[ladders[i + k]], board[i] + 1);
                }
            } else if (snakes[i + k] != -1) {
                if (board[snakes[i + k]] == -1) {
                    board[snakes[i + k]] = board[i] + 1;
                } else {
                    board[snakes[i + k]] = min(board[snakes[i + k]], board[i] + 1);
                }
            } else {
                if (board[i + k] == -1) {
                    board[i + k] = board[i] + 1;
                } else {
                    board[i + k] = min(board[i + k], board[i] + 1);
                }
            }
        }
    }

    for (int i = 1; i < 100; i++) {
        if (board[i] == -1) {
            continue;
        }
        for (int k = 1; k <= 6; k++) {
            if (i + k > 100) {
                break;
            }
            if (ladders[i + k] != -1) {
                if (board[ladders[i + k]] == -1) {
                    board[ladders[i + k]] = board[i] + 1;
                } else {
                    board[ladders[i + k]] = min(board[ladders[i + k]], board[i] + 1);
                }
            } else if (snakes[i + k] != -1) {
                if (board[snakes[i + k]] == -1) {
                    board[snakes[i + k]] = board[i] + 1;
                } else {
                    board[snakes[i + k]] = min(board[snakes[i + k]], board[i] + 1);
                }
            } else {
                if (board[i + k] == -1) {
                    board[i + k] = board[i] + 1;
                } else {
                    board[i + k] = min(board[i + k], board[i] + 1);
                }
            }
        }
    }
    if (board[100] != -1) {
        cout << board[100] << "\n";
    } else {
        cout << -1 << "\n";
    }

    // print(board);
    // print(ladders);
    // print(snakes);
}

signed main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        // break;
    }

    return 0;
}
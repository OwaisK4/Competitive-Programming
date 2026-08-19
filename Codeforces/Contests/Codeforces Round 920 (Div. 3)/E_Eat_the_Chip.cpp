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

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int h, w, ya, xa, yb, xb;
        cin >> h >> w >> ya >> xa >> yb >> xb;
        if (ya >= yb) {
            cout << "Draw\n";
            continue;
        }
        int diff = yb - ya;
        if ((diff - 1) % 2 == 0) {
            if (abs(xa - xb) <= 1) {
                cout << "Alice\n";
                continue;
            }
            if (xa < xb) {
                int possible = w - xa;
                if (((diff) / 2) <= possible) {
                    cout << "Draw\n";
                } else {
                    cout << "Alice\n";
                }
            } else {
                int possible = xa - 1;
                if (((diff) / 2) <= possible) {
                    cout << "Draw\n";
                } else {
                    cout << "Alice\n";
                }
            }
        } else {
            if (abs(xa - xb) <= 1) {
                cout << "Bob\n";
                continue;
            }
            if (xa < xb) {
                // int possible = w - xb;
                int possible = xb - 1;
                if (((diff - 1) / 2) <= possible) {
                    cout << "Draw\n";
                } else {
                    cout << "Bob\n";
                }
            } else {
                // print("Here");
                // int possible = xb - 1;
                int possible = w - xb;
                if (((diff - 1) / 2) <= possible) {
                    cout << "Draw\n";
                } else {
                    cout << "Bob\n";
                }
            }
        }
    }

    return 0;
}
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

vector<vector<int>> adj_matrix;
int t = 1;

void solve() {
    int n, x, y;
    cin >> n;
    adj_matrix.assign(n + 1, vector<int>(n + 1, 0));
    int a = 1;
    int b = 2;
    set<int> s = {1};
    for (int i = 0; i < 15 * n; i++) {
        cout << "? " << b << " " << a << "\n";
        fflush(stdout);
        cin >> x;
        if (a == x || b == x) {
            adj_matrix[a][b] = 1;
            adj_matrix[b][a] = 1;
            s.insert(a);
            s.insert(b);
        } else {
            int k = 1;
            cout << "? " << b << " " << x << "\n";
            cout.flush();
            cin >> y;
            while (b != y && x != y && i + k < 15 * n) {
                cout << "? " << b << " " << x;
                cout.flush();
                x = y;
                cin >> y;
                k++;
            }
            if (i + k >= 15 * n) {
                cin >> y;
                t = 0;
                return;
            }
            adj_matrix[b][x] = 1;
            adj_matrix[x][b] = 1;
            s.insert(b);
            s.insert(x);
            i += k;
        }
        while (s.find(b) != s.end()) {
            b++;
        }
        if (b > n) {
            break;
        }
    }
    map<int, int> mp;
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adj_matrix[i][j] == 1 && mp[i] != j) {
                cout << i << " " << j << " ";
                mp[i] = j;
                mp[j] = i;
                break;
            }
        }
    }
    cout << "\n";
    cout.flush();
}

signed main() {
    // fastio;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
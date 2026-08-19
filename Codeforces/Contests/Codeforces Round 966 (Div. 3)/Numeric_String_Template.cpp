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
    int n;
    cin >> n;
    vector<pii> a(n);
    map<int, int> a_index;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        if (a_index.count(a[i].first)) {
            a[i].second = a_index[a[i].first];
        }
        a_index[a[i].first] = i;
    }
    int m;
    cin >> m;
    vector<string> st(m);
    for (int i = 0; i < m; i++) {
        cin >> st[i];
    }
    for (int i = 0; i < m; i++) {
        string current = st[i];
        if (a.size() != current.size()) {
            cout << "NO\n";
            continue;
        }
        map<int, int> s_index;
        bool valid = true;
        for (int j = 0; j < current.size(); j++) {
            if (s_index.count(current[j])) {
                int s_value = s_index[current[j]];
                int a_value = a[j].second;
                if (s_value != a_value) {
                    valid = false;
                    break;
                }
            } else if (a[j].second != j) {
                valid = false;
                break;
            }
            s_index[current[j]] = j;
        }
        if (valid) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
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
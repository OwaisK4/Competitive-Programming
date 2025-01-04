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
    vector<int> a(n), prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    partial_sum(all(a), prefix.begin() + 1);
    // print(prefix);
    string s;
    cin >> s;

    int answer = 0;
    int i = 0, j = n - 1;
    while (i < j) {
        if (s[i] == 'L' && s[j] == 'R') {
            answer += (prefix[j + 1] - prefix[i]);
            i++;
            j--;
        } else if (s[i] == 'R') {
            i++;
        } else if (s[j] == 'L') {
            j--;
        }
    }
    cout << answer << "\n";

    vector<int> ls, rs;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            ls.push_back(i);
        } else if (s[i] == 'R') {
            rs.push_back(i);
        }
    }
    sort(all(ls));
    sort(all(rs));

    // int i = 0, j = rs.size() - 1;
    // while (i < ls.size() && j >= 0) {
    //     if (ls[i])
    // }

    // int i = 0;
    // int j = 0;
    // while (i < ls.size() & j < rs.size()) {
    //     if (ls[i] > rs[j]) {
    //     }
    // }
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
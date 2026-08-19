#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define MOD 10000000007
using namespace std;
using pii = pair<int, int>;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    int n, m;
    cin >> n >> m;
    vector<int> x(n + 1, 0), indexes(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        indexes[x[i]] = i;
    }
    vector<pii> operations(m);
    for (int i = 0; i < m; i++) {
        cin >> operations[i].first >> operations[i].second;
    }
    // print(x);
    // print(indexes);
    int cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (indexes[i] < indexes[i - 1]) {
            cnt++;
        }
    }
    // cout << cnt << " ";
    for (auto &[a, b] : operations) {
        set<pii> inversions;
        // cout << a << ", " << b << "\n";
        if (x[a] - 1 >= 1)
            inversions.insert({x[a] - 1, x[a]});
        if (x[a] + 1 <= n)
            inversions.insert({x[a], x[a] + 1});
        if (x[b] - 1 >= 1)
            inversions.insert({x[b] - 1, x[b]});
        if (x[b] + 1 <= n)
            inversions.insert({x[b], x[b] + 1});

        for (auto &[left, right] : inversions) {
            if (indexes[left] > indexes[right]) {
                cnt--;
            }
        }
        swap(x[a], x[b]);
        indexes[x[a]] = a;
        indexes[x[b]] = b;
        for (auto &[left, right] : inversions) {
            if (indexes[left] > indexes[right]) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}

signed main() {
    fastio;
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
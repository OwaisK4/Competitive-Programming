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
// using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), answer;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ordered_set<pii> window;
    for (int i = 0; i < k; i++) {
        window.insert({a[i], i});
    }
    int index = (k - 1) / 2;
    int element = window.find_by_order(index)->first;
    answer.push_back(element);

    for (int i = k; i < n; i++) {
        int previous = a[i - k];
        int next = a[i];
        window.erase(window.find({previous, i - k}));
        window.insert({next, i});
        // for (auto it : window) {
        //     cout << it.first << " ";
        // }
        // cout << "\n";
        int index = (k - 1) / 2;
        int element = window.find_by_order(index)->first;
        answer.push_back(element);
    }
    print(answer);
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
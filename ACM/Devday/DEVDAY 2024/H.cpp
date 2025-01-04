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
#define MOD 10000000007
using namespace std;
using pii = pair<int, int>;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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
    ordered_set s;
    for (int i = 0; i < n; i++) {
        s.insert(i + 1);
    }
    vector<int> answer;

    int i = 0;
    while (s.size() > 0) {
        int n = s.size();
        i = (i + k) % n;
        auto position = (s.find_by_order(i));
        answer.push_back(*position);
        s.erase(position);
    }
    for (auto it : answer) {
        cout << it << " ";
    }
}

signed main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
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

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

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
template <typename T, typename... Ts>
void print(T X, Ts... Y) {
    cout << X << " ";
    print(Y...);
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> nums(n), prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    partial_sum(all(nums), prefix.begin() + 1);
    // print(prefix);
    // return;

    multiset<int> s;
    // for (int i = 0; i < a; i++) {
    //     s.insert(prefix[i]);
    // }
    deque<int> dq;
    dq.push_back(0);
    s.insert(prefix[dq.back()]);
    int left = 1;
    int best = LONG_LONG_MIN;
    for (int i = a; i <= n; i++) {
        // for (auto it : s) {
        //     cout << it << " ";
        // }
        // print("");
        int current = prefix[i] - *s.begin();
        best = max(best, current);
        dq.push_back(left);
        left++;
        s.insert(prefix[dq.back()]);
        if (dq.size() > (b - a + 1)) {
            s.erase(s.find(prefix[dq.front()]));
            dq.pop_front();
        }
    }
    print(best);
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
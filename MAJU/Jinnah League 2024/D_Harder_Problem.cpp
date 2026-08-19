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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // int uniques = set(all(a)).size();
    set<pii> s;
    map<int, int> counter;
    counter[a[0]] = 1;

    set<int> used;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (used.contains(a[i]))
            continue;
        b[k] = a[i];
        used.insert(a[i]);
        k++;
        counter[a[i]] = 1;
        s.insert({counter[a[i]], a[i]});
    }
    int max_cnt = 1;
    for (int i = k; i < n; i++) {
        if (counter[a[i]] < max_cnt || s.begin()->first == max_cnt) {
            b[i] = a[i];
            s.erase({counter[a[i]], a[i]});
            counter[a[i]]++;
            max_cnt = max(max_cnt, counter[a[i]]);
            s.insert({counter[a[i]], a[i]});
        } else {
            auto [cnt, val] = *s.begin();
            b[i] = val;
            s.erase(s.begin());
            counter[b[i]]++;
            max_cnt = max(max_cnt, counter[b[i]]);
            s.insert({counter[b[i]], b[i]});
        }
    }
    print(b);

    // print(cnt);
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
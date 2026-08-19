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
    int n, l, r;
    cin >> n;
    vector<pii> a(n);
    ordered_set<int> s;
    map<int, int> mp;
    for (int i = 1; i <= (int)2 * n; i++) {
        s.insert(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        if (l == r) {
            s.erase(l);
            mp[l]--;
        }
        a[i] = {l, r};
    }
    string answer(n, '1');
    for (int i = 0; i < n; i++) {
        tie(l, r) = a[i];
        if (l == r) {
            if (mp[l] < -1)
                answer[i] = '0';
            continue;
        }
        int cnt = s.order_of_key(r + 1) - s.order_of_key(l);
        if (cnt == 0)
            answer[i] = '0';
    }
    print(answer);
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
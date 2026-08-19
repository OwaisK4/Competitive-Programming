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
template <typename A>
ostream &operator<<(ostream &os, const tuple<A, A, A> &p) {
    return os << '(' << get<0>(p) << ", " << get<1>(p) << ", " << get<2>(p) << ')';
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> made;
    vector<tuple<int, int, int>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int s = a[i] + a[j];
            if (!made.contains(s))
                mp.push_back({s, i + 1, j + 1});
            made[s] = 1;
        }
    }
    // sort(all(mp));
    int N = mp.size();
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int s = get<0>(mp[i]) + get<0>(mp[j]);
            int a = get<1>(mp[i]);
            int b = get<2>(mp[i]);
            int c = get<1>(mp[j]);
            int d = get<2>(mp[j]);
            set<int> st = {a, b, c, d};
            if (s == x && st.size() == 4) {
                print(a, b, c, d);
                return;
            }
        }
    }
    print("IMPOSSIBLE");
    // print(mp);
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
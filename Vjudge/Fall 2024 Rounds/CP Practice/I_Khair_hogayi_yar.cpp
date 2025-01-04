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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<string, set<string>> mp;
    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        mp[s1].insert(s2);
        mp[s2].insert(s1);
    }
    int maximum = 0;
    vector<string> answer;
    for (int i = 0; i <= (1 << n); i++) {
        int cnt = 0;
        vector<string> used;
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) {
                continue;
            }
            bool valid = true;
            for (int k = 0; k < used.size(); k++) {
                if (mp[a[j]].count(used[k])) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                used.push_back(a[j]);
            }
        }
        if (maximum < used.size()) {
            maximum = used.size();
            answer = used;
        }
    }
    print(maximum);
    sort(all(answer));
    for (auto it : answer) {
        print(it);
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
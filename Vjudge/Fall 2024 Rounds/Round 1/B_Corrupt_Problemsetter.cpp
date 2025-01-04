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
void print(T X, bool newline = true) {
    cout << X;
    if (newline) {
        cout << "\n";
    }
}

void solve(int t) {
    int n;
    cin >> n;
    vector<int> a(n), b;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (mp[i]) {
            mp[i]--;
        } else if (mp[n - i - 1]) {
            mp[n - i - 1]--;
        } else {
            cout << "Case " << t + 1 << ": no\n";
            return;
        }
    }
    cout << "Case " << t + 1 << ": yes\n";
}

signed main() {
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i);
    }

    return 0;
}
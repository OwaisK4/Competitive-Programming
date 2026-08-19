#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define int long long
#define all(a) a.begin(), a.end()
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vii vector<pair<int, int>>
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
    int q = 0;
    int u = 1, v, k;
    map<int, int> mp;

    // while (q < 50) {
    int low = 2, high = 1e8;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        cout << "? " << u << " " << mid << endl;
        cin >> v;
        if (v != -1) {
            mp[mid] = v;
            low = mid;
        } else {
            high = mid - 1;
        }
        q++;
    }
    auto ks = views::keys(mp);
    vector<int> keys(all(ks));
    for (int i = 0; i < keys.size() && i + q < 50; i++) {
        cout << "? " << keys[i] << " " << u << endl;
        cin >> v;
        if (v != mp[keys[i]]) {
            cout << "! " << v + mp[keys[i]] << endl;
            return;
        }
    }
    for (int i = 2; i <= low; i++) {
        for (int j = i + 1; j <= low; j++) {
            cout << "? " << i << " " << j << endl;
            cin >> v;
            cout << "? " << j << " " << i << endl;
            cin >> k;
            if (v != k) {
                cout << "! " << v + k << endl;
                return;
            }
            q++;
            if (q >= 50) {
                cout << "! " << 0 << endl;
                return;
            }
        }
    }
    // }
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
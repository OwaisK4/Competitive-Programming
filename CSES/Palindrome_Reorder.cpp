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

void solve() {
    string s;
    cin >> s;
    map<char, int> mp;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
    int odds = 0;
    char o = '-1';
    for (auto it : mp) {
        if (it.second % 2 != 0) {
            odds++;
            o = it.first;
        }
    }
    if (odds > 1) {
        cout << "NO SOLUTION";
        return;
    }

    deque<char> dq;
    for (int i = 0; i < mp[o]; i++) {
        dq.push_back(o);
    }
    for (auto it : mp) {
        if (it.first != o) {
            int half = it.second / 2;
            for (int i = 0; i < half; i++) {
                dq.push_back(it.first);
                dq.push_front(it.first);
            }
        }
    }
    for (auto it : dq) {
        cout << it;
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
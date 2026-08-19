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

string s;

void f(int l, int r, int value, map<int, int> &possible) {
    if (l >= r + 1) {
        possible[value]++;
        // print(value);
    }
    for (int i = l + 1; i <= r + 1; i++) {
        string sub = s.substr(l, i - l);
        f(i, r, value + stoll(sub), possible);
    }
}

// void possible(int l, int r, vi &values) {
// string sub = s.substr(l, r - l + 1);
// values.push_back(stoll(sub));
// for (int i = l; i < r; i++) {
//     int value = f(l, i);
// f(i + 1, r, values);
// }
// int value = f(l, r);
// }

void solve() {
    while (true) {
        cin >> s;
        if (s == "END")
            break;
        int n = s.size();
        int answer = 0;
        for (int i = 0; i < n - 1; i++) {
            map<int, int> a, b;
            f(0, i, 0, a);
            f(i + 1, n - 1, 0, b);
            for (auto it : a) {
                if (b.count(it.first)) {
                    answer += (a[it.first] * b[it.first]);
                }
            }
        }
        print(answer);
        // break;
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
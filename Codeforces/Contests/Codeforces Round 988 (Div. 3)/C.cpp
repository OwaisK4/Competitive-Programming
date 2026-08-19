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

vector<bool> prime(2e5 + 1, true);

void solve() {
    int n;
    cin >> n;

    vector<int> a, evens;

    for (int i = 1; i <= n; i += 2) {
        a.push_back(i);
    }
    for (int i = 2; i <= n; i += 2) {
        evens.push_back(i);
    }
    bool found = false;
    for (int i = 0; i < evens.size(); i++) {
        if (!prime[a.back() + evens[i]]) {
            found = true;
            a.push_back(evens[i]);
            evens.erase(i + evens.begin());
            break;
        }
    }
    if (!found) {
        print(-1);

    } else {
        a.insert(a.end(), all(evens));
        print(a);
    }
}

signed main() {
    fastio;
    int n = 2e5 + 1;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
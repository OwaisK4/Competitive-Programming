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

bool p[(int)1e6 + 1];
vector<int> primes;

void solve() {
    int h;
    cin >> h;
    int attack = 1;
    int i = 0;
    for (int i = 0; (1 << i) - 1 <= h; i++) {
        int s = (1 << i) - 1;
        if (h == s) {
            print(i);
            return;
        }
        if (p[h - s]) {
            print(i + 1);
            return;
        }
    }
    print(-1);
    return;
}

signed main() {
    fastio;
    fill(p, p + (int)1e6 + 1, true);
    // p[1] = false;

    for (int i = 2; i * i <= (int)1e6; i++) {
        if (!p[i])
            continue;
        for (int j = 2 * i; j <= (int)1e6; j += i) {
            p[j] = false;
        }
    }
    for (int i = 2; i <= 1e6; i++) {
        if (p[i])
            primes.push_back(i);
    }
    // print(primes);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
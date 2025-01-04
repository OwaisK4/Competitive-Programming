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

int binpow(int x, int n) {
    if (n == 0) {
        return 1;
    }
    int answer = ((binpow(x, n / 2) % MOD) + MOD) % MOD;
    answer *= answer;
    if (n & 1)
        answer *= x;
    answer = ((answer % MOD) + MOD) % MOD;
    return answer;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int S = 0, sum = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        cur += a[i];
        cur = max(cur, 0LL);
        S = max(S, cur);
    }
    sum = (sum % MOD + MOD) % MOD;
    S = S % MOD;
    int t = 1;
    for (int i = 0; i < k; i++) {
        t = t * 2 % MOD;
    }
    int ans = (sum + S * t - S + MOD) % MOD;
    cout << ans << '\n';
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
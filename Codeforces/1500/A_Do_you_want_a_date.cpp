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

int binmult(int a, int b) {
    if (b == 0) {
        return 0;
    }
    int answer = binmult(a, b / 2) % MOD;
    answer = (answer * 2) % MOD;
    if (b & 1) {
        answer = (answer + a) % MOD;
    }
    return answer;
}

int binpow(int x, int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x % MOD;
    }
    int answer = binpow(x, n / 2) % MOD;
    answer = binmult(answer, answer);
    answer %= MOD;
    if (n & 1) {
        answer *= x;
        answer %= MOD;
    }
    return answer;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));

    int answer = 0;
    for (int i = 1; i < n; i++) {
        int times = binpow(2, i) - 1;
        answer += binmult(a[i], times);
        answer %= MOD;
    }
    for (int i = n - 2; i >= 0; i--) {
        int times = binpow(2, n - i - 1) - 1;
        answer -= binmult(a[i], times);
        answer = ((answer % MOD) + MOD) % MOD;
    }
    cout << answer;
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
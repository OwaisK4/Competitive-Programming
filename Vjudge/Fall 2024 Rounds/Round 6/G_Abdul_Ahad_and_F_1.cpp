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

vector<int> a;
vector<char> ops;

int f(int l, int r, int depth) {
    if (l == r) {
        return a[l];
    }
    int answer = 0;
    for (int i = l; i < r; i++) {
        int value;
        if (ops[i] == '+') {
            value = f(l, i, depth + 1) + f(i + 1, r, depth + 1);
            // value = ((value % MOD) + MOD) % MOD;
        } else if (ops[i] == '*') {
            value = f(l, i, depth + 1) * f(i + 1, r, depth + 1);
            // value = ((value % MOD) + MOD) % MOD;
        } else {
            value = f(l, i, depth + 1) - f(i + 1, r, depth + 1);
            // value = ((value % MOD) + MOD) % MOD;
        }
        if (depth == 0)
            answer += value;
    }
    answer = ((answer % MOD) + MOD) % MOD;
    return answer;
}

void solve() {
    int n;
    while (cin >> n) {
        a.assign(n, 0);
        ops.assign(n - 1, '0');
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> ops[i];
        }
        int answer = f(0, n - 1, 0);
        print(answer);

        // print(a2);
        // print(max(answer, a2));
    }
}

signed main() {
    fastio;
    solve();

    return 0;
}
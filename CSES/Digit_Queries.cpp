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

int binpow(int x, int n) {
    if (n == 0) {
        return 1;
    }
    int answer = binpow(x, n / 2);
    answer *= answer;
    if (n & 1) {
        answer *= x;
    }
    return x;
}

void solve() {
    int k;
    cin >> k;
    string nines = "9";
    int i = 1;
    while (true) {
        int m = stoll(nines);
        if (k < m) {
            break;
        }
        k -= m;
        i++;
        if (i == 2) {
            nines = "100";
        } else {
            nines += '0';
        }
    }
    int x = k;
    while (x % i != 0) {
        x++;
    }

    string value = to_string(binpow(10, i - 1) + (k / i) - 1);
    int answer = value[value.size() - 1 - (x - k)] - '0';
    print(answer);
    // print(k, false);
    // print(" ", false);
    // print(i);
    // print(value);
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
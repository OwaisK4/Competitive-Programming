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
    } else if (n == 1) {
        return x;
    }
    int answer = binpow(x, n / 2);
    answer *= answer;
    if (n & 1) {
        answer *= x;
    }
    return answer;
}

void solve() {
    int n, k;
    cin >> n >> k;

    if (n < k) {
        print(n);
    } else if (n == k) {
        print(1);
    } else {
        if (k == 1) {
            print(n);
        } else {
            int s = k;
            int x = 0;
            while (true) {
                s = binpow(k, x);
                x++;
                if (binpow(k, x) > n) {
                    break;
                }
            }
            int answer = 0;
            while (x >= 0) {
                int div = binpow(k, x);
                answer += (n / div);
                n %= div;
                x--;
            }
            print(answer);
        }
    }
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
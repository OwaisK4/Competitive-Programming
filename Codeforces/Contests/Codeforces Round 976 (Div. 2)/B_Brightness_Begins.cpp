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

int first_true(int low, int high, int target) {
    high++;
    while (low < high) {
        int mid = low + (high - low) / 2;
        int sq = mid * mid;
        if (sq >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

// vector<int> dp(1e7, 0);

void solve() {
    int k;
    cin >> k;

    if (k == 0 || k == 1) {
        print(k + 1);
        return;
    }

    // int s = first_true(1, sqrt(k) + 1, k);
    int s = sqrt(k);
    if (s * s < k) {
        s++;
    }
    int o = s * s;
    int answer;
    if (k > (o - s)) {
        answer = (k + s);
    } else {
        answer = (k + s - 1);
    }
    print(answer);
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
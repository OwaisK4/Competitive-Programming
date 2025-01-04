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

void solve(int c) {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
        // cin >> a[i].first >> a[i].second;
    }

    int minimum = INT_MAX;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (B[i] < minimum) {
            minimum = B[i];
            index = i + 1;
        } else if (A[i] > minimum) {
            minimum = A[i];
            index = i + 1;
        } else {
            minimum += (minimum / (i + 1));
        }
    }

    double answer = (double)index / (double)minimum;

    for (int i = 0; i < n; i++) {
        double t = (double)(i + 1) / (double)answer;
        if (t < A[i] || t > B[i]) {
            cout << "Case #" << c << ": " << -1 << "\n";
            return;
        }
    }

    cout << "Case #" << c << ": " << fixed << setprecision(9) << answer << "\n";
}

signed main() {
    file_read("./subsonic_subway_validation_input.txt");
    file_write("./subsonic_subway_validation_output.txt");
    // fastio;
    int i = 1;
    int t = 1;
    cin >> t;
    while (i <= t) {
        solve(i);
        i++;
    }

    return 0;
}
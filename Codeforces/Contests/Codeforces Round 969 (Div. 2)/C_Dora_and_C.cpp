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

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> c(n), answer(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    // int target = max(lcm(a, b), *max_element(all(c)));
    int target = lcm(a, b);
    if (target < *max_element(all(c))) {
        target += *max_element(all(c));
    }
    cout << "Target = " << target << "\n";
    for (int i = 0; i < n; i++) {
        // int above = target + c[i];
        // int below = c[i];
        // int temp = (abs(below - target) < abs(above - target)) ? below : above;
        // temp = abs(temp - target);
        // int temp = target + c[i];
        // cout << "Temp = " << temp << "\n";

        // temp %= a;
        // temp %= b;
        int above = target + c[i];
        int temp = above;
        cout << "Temp = " << temp << "\n";
        if (a != b) {
            temp %= abs(a - b);
        }
        answer[i] = temp;
    }
    sort(all(answer));
    int value = answer.back() - answer.front();
    cout << value << "\n";
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
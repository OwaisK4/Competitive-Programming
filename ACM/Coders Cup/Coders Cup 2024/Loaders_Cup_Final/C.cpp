#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
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
using namespace std;

vector<bool> prime(2e7 + 1, true);
vector<int> a;

void solve() {
    int n;
    cin >> n;
    // for (int i = 2; i * i <= n; i++) {
    //     if ()
    // }
    int answer = a[n - 1];
    cout << answer << "\n";
}

signed main() {
    fastio;
    int n = 2e6 + 1;
    for (int p = 2; p <= n; p++) {
        if (prime[p] == true) {
            a.push_back(p);
            // cout << p << "\n";
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
        if (a.size() > 15000) {
            break;
        }
    }
    // cout << "Size = " << a.size() << "\n";
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
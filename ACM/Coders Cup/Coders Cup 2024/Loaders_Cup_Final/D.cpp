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

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0, answer = 0;
    int index = -1;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum >= l && sum <= r) {
            answer++;
            sum = 0;
            index = i;
        }
        if (sum > r) {
            int j = index + 1;
            while (j <= i) {
                sum -= a[j];
                j++;
                if (sum >= l && sum <= r) {
                    answer++;
                    sum = 0;
                    index = i;
                    break;
                } else if (sum < l) {
                    index = j - 1;
                    break;
                }
            }
            // sum = 0;
            // index = i;
        }
    }
    cout << answer << "\n";
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
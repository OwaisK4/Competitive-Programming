#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

vector<int> prefix_sum;

// int first_true(int low, int high, int target, int s) {
//     high++;
//     while (low < high) {
//         int mid = low + (high - low) / 2;
//         if (s + prefix_sum[mid + 1] >= target) {
//             high = mid;
//         } else {
//             low = mid + 1;
//         }
//     }
//     return high;
// }

void solve() {
    int n, s;
    cin >> n >> s;
    prefix_sum.assign(n + 1, 0);
    map<pii, int> dist;
    vector<pii> cities;
    for (int i = 0; i < n; i++) {
        int xi, yi, ki;
        cin >> xi >> yi >> ki;
        dist[{xi, yi}] = ki;
        cities.push_back({xi, yi});
    }
    auto cmp = [&](pii &c1, pii &c2) {
        double r1 = (c1.first * c1.first) + (c1.second * c1.second);
        double r2 = (c2.first * c2.first) + (c2.second * c2.second);
        return r1 < r2;
    };
    sort(all(cities), cmp);

    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + dist[cities[i - 1]];
    }
    // print(prefix_sum);
    int target = 1000000; // 1 million
    auto it = lower_bound(all(prefix_sum), target - s);
    if (it == prefix_sum.end()) {
        cout << -1;
        return;
    }
    int pos = it - prefix_sum.begin() - 1;
    // cout << pos;
    pii city = cities[pos];
    double radius = sqrt((city.first * city.first) + (city.second * city.second));
    cout << fixed << setprecision(7) << radius;
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
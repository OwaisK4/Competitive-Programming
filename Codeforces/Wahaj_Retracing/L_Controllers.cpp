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
int negatives = 0, positives = 0;
int a, b;

bool first_true(int low, int high) {
    high++;
    while (low < high) {
        int mid = low + (high - low) / 2;
        int sum = 0;
        if (mid >= negatives) {
            sum -= negatives * a;
            int diff = (mid - negatives);
            sum += diff * b;
            sum += (positives - diff) * b;
        } else {
            sum -= mid * a;
            int diff = (negatives - mid);
            sum += (positives + diff) * b;
        }

        if (sum <= 0) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

void solve() {
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char temp;
        cin >> temp;
        if (temp == '+')
            positives++;
        else
            negatives++;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        int answer = first_true(0, n);
        if (answer != n + 1) {
            int sum = 0;
            if (answer >= negatives) {
                sum -= negatives * a;
                int diff = (answer - negatives);
                sum += diff * b;
                sum += (positives - diff) * b;
            } else {
                sum -= answer * a;
                int diff = (negatives - answer);
                sum += (positives + diff) * b;
            }
            if (sum == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            cout << "NO\n";
        }
    }
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
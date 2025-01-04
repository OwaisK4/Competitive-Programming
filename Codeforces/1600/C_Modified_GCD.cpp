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

vector<int> get_factors(int x) {
    vector<int> factors;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            factors.push_back(i);
            if (i * i < x) {
                factors.push_back(x / i);
            }
        }
    }
    sort(all(factors));
    return factors;
}

vector<int> vector_union(vector<int> &a_factors, vector<int> &b_factors) {
    vector<int> answer;
    int i = 0, j = 0;
    while (i < a_factors.size() && j < b_factors.size()) {
        if (a_factors[i] == b_factors[j]) {
            answer.push_back(a_factors[i]);
            i++;
            j++;
        } else if (a_factors[i] < b_factors[j]) {
            i++;
        } else {
            j++;
        }
    }
    return answer;
}

void solve() {
    int a, b;
    cin >> a >> b;
    vector<int> a_factors = get_factors(a);
    vector<int> b_factors = get_factors(b);
    vector<int> factors = vector_union(a_factors, b_factors);
    // print(a_factors);
    // print(b_factors);
    // print(factors);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int low, high;
        cin >> low >> high;
        auto right = upper_bound(all(factors), high);
        auto left = lower_bound(all(factors), low);
        if (left == right) {
            cout << -1 << "\n";
        } else {
            cout << *(right - 1) << "\n";
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
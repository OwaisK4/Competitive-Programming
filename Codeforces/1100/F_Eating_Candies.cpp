#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

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

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> w(n), prefix(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }
        partial_sum(all(w), prefix.begin() + 1);

        int max_candies = 0;
        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int candies = prefix[left];
            int target = prefix[n] - candies;
            auto it = lower_bound(prefix.begin() + left, prefix.end(), target);
            if (it != prefix.end() && *it == target) {
                int right = prefix.end() - 1 - it;
                max_candies = max(max_candies, left + right);
            }
        }
        cout << max_candies << "\n";
    }

    return 0;
}
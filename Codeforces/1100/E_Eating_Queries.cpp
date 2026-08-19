#include <bits/stdc++.h>
#include <ext/numeric>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
using namespace __gnu_cxx;

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

int first_true(vector<int> &array, int low, int high, int target) {
    high++;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (array[mid] >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n), prefix(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(all(a), greater<int>());
        partial_sum(all(a), prefix.begin());
        // print(prefix);
        for (int i = 0; i < q; i++) {
            int target;
            cin >> target;
            int cnt = first_true(prefix, 0, prefix.size() - 1, target);
            if (cnt == prefix.size()) {
                cout << -1 << "\n";
            } else {
                cout << cnt + 1 << "\n";
            }
        }
    }

    return 0;
}
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
void print(T array) {
    for (auto it = begin(array); it != end(array); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}

vector<int> a;
vector<int> prefix;

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        a.assign(n, 0);
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(all(a));
        partial_sum(all(a), prefix.begin() + 1);

        int left = 0;
        int right = n - 1;
        for (int i = 0; i < n; i++) {
            if (a[left] < l) {
                left++;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (a[right] > r) {
                right--;
            }
        }
        left++;
        right++;
        // cout << "Left = " << left << "\n";
        // cout << "Right = " << right << "\n";

        int i = left, j = left;
        int maximum = 0;
        int current = 0;
        while (i <= right && j <= right && i <= j) {
            if ((prefix[j] - prefix[i - 1]) <= k) {
                j++;
                current++;
                maximum = max(maximum, current);
            } else {
                i++;
                current--;
            }
        }
        cout << maximum << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(T array) {
    for (auto it = begin(array); it != end(array); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    int n, q;
    cin >> n >> q;
    vector<int> a(n), prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    partial_sum(all(a), prefix.begin() + 1);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        int left = n - x;
        int right = left + y;
        int answer = prefix[right] - prefix[left];
        // cout << left << " " << right << " ";
        cout << answer << "\n";
    }

    return 0;
}
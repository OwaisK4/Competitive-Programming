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

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }
        // int answer = *max_element(all(a)) - *min_element(all(a));
        int answer = a[n - 1] - a[0];
        answer = max(answer, a[n - 1] - *min_element(a.begin(), a.end() - 1));
        answer = max(answer, *max_element(a.begin() + 1, a.end()) - a[0]);

        // for (int i = 0; i < n - 1; i++) {
        //     answer = max(answer, a[i + 1] - a[i]);
        // }
        for (int i = 0; i < n; ++i) {
            answer = max(answer, a[(i - 1 + n) % n] - a[i]);
        }

        cout << answer << "\n";
    }

    return 0;
}
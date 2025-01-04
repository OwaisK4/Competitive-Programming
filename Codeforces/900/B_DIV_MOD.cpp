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
    int t;
    cin >> t;
    while (t--) {
        int l, r, a;
        cin >> l >> r >> a;
        int answer = (r / a) + (r % a);
        // int x = (r / a) * a - 1;
        int x = r - (r % a) - 1;
        if (l <= x) {
            int second = (x / a) + (x % a);
            answer = max(answer, second);
        }
        cout << answer << "\n";
    }

    return 0;
}
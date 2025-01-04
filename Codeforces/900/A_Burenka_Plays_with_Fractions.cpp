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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int left, right;
        left = a * d;
        right = b * c;
        int answer = 0;
        if (left == right) {
            cout << answer << "\n";
            continue;
        }

        int mark = gcd(left, right);
        if (mark != left) {
            answer++;
        }
        if (mark != right) {
            answer++;
        }
        cout << answer << "\n";
    }

    return 0;
}
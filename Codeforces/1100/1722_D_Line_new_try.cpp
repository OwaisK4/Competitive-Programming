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
vector<char> facing;
vector<int> diff;
vector<int> prefix;

template <typename T>
void print(T array) {
    for (auto it = begin(array); it != end(array); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        facing.assign(n, '\0');
        diff.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> facing[i];
        }
        int total = 0;
        for (int i = 0; i < n; i++) {
            int current, opposite;
            if (facing[i] == 'L') {
                current = i;
                opposite = n - i - 1;
                total += current;
            } else {
                current = n - i - 1;
                opposite = i;
                total += current;
            }
            if (opposite > current)
                diff[i] = abs(i - (n - i - 1));
            else
                diff[i] = 0;
        }
        sort(all(diff), greater<int>());
        // print(diff);

        for (int i = 0; i < n; i++) {
            total += diff[i];
            cout << total << " ";
        }
        cout << "\n";
    }
    return 0;
}
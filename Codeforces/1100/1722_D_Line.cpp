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
vector<int> counts;
vector<int> prefix;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        facing.assign(n, '\0');
        counts.assign(n, 0);
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> facing[i];
        }
        for (int i = 0; i < n; i++) {
            if (facing[i] == 'L') {
                counts[i] = i;
            } else {
                counts[i] = n - i - 1;
            }
        }

        partial_sum(all(counts), prefix.begin() + 1);
        int total = prefix[n];

        for (int i = 0; i < n; i++) {
            int current;
            int opposite;
            if (facing[i] == 'L') {
                current = i;
                opposite = n - i - 1;
            } else {
                current = n - i - 1;
                opposite = i;
            }
            if (opposite > current) {
                total += (opposite - current);
            }
            cout << total << " ";
        }
        for (auto it : counts) {
            // cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}
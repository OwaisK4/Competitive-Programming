#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

signed main() {
    fastio;
    int score = 0;
    int i, j, k = 0;
    int n = 15;

    for (int i = 0; i < n + 1; i++) {
        if (i == 5) {
            cout << "k = " << k << "\n";
            cout << "score = " << score << "\n";
        }
        for (int j = i + 1; j < (i + 1); j++) {
            for (int k = 1; k < (i + j); k++) {
                score++;
                // cout << score << "\n";
            }
        }
    }
    // cout << score << "\n";

    return 0;
}

#include <climits>
#include <iostream>
#include <vector>
#define int long long
using namespace std;

int n, L;
vector<int> a;
int dp[1001][2][31];
int f(int index, int last, int L) {
    if (index == n) {
        return 0;
    }
    if (dp[index][last][L] != -1) {
        return dp[index][last][L];
    }
    int answer = INT_MIN;
    if (a[index] == last)
        answer = max(answer, f(index + 1, last, L) + 1);
    else
        answer = max(answer, f(index + 1, last, L));
    if (L > 0) {
        if (a[index] == (1 - last))
            answer = max(answer, f(index + 1, 1 - last, L - 1) + 1);
        else
            answer = max(answer, f(index + 1, 1 - last, L - 1));
    }
    return dp[index][last][L] = answer;
}

void solve() {
    cin >> n >> L;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 31; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    int answer = f(0, 0, L);
    cout << answer << "\n";
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
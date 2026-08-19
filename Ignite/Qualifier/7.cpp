#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define MOD 1000000007
using namespace std;
using pii = pair<int, int>;
template <typename T>
void print(T X) {
    cout << X << "\n";
}

vi m, a, tm1, ta;
int m0, a0, dm, da;
int n;

vvi dp;

int f(int index, int team) {
    if (index == n) {
        return (team == 0) ? dm : da;
    }
    if (dp[index][team] != -1) {
        return dp[index][team];
    }
    int answer = LONG_LONG_MAX;
    if (team == 0) {
        answer = min(answer, f(index + 1, 0) + m[index]);
        // if (index + 1 < n)
        answer = min(answer, f(index + 1, 1) + m[index] + tm1[index]);
    } else {
        answer = min(answer, f(index + 1, 1) + a[index]);
        // if (index + 1 < n)
        answer = min(answer, f(index + 1, 0) + a[index] + ta[index]);
    }
    return dp[index][team] = answer;
}

void solve() {
    cin >> n;
    dp.assign(n, vi(2, -1));
    m.assign(n, 0);
    a.assign(n, 0);
    tm1.assign(n, 0);
    ta.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> tm1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> ta[i];
    }
    cin >> m0 >> a0 >> dm >> da;
    int answer = min(m0 + min(f(0, 0), f(0, 1) + tm1[0]), a0 + min(f(0, 1), f(0, 0) + ta[0]));
    print(answer);
}

signed main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
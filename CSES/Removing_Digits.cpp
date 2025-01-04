#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

vector<int> digitize(int n) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    // reverse(all(digits));
    return digits;
}

vector<int> dp(1e6 + 1, -1);

int f(int n) {
    if (n == 0) {
        return 0;
    }
    if (dp[n] != -1) {
        return dp[n];
    }

    vector<int> d = digitize(n);
    int answer = LONG_LONG_MAX;
    for (int i = 0; i < d.size(); i++) {
        if (d[i] == 0) {
            continue;
        }
        answer = min(answer, f(n - d[i]) + 1);
    }
    return dp[n] = answer;
}

signed main() {
    fastio;
    int n;
    cin >> n;
    int answer = f(n);
    cout << answer;

    return 0;
}
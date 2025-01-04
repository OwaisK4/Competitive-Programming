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
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

signed main() {
    // fastio;

    freopen("/home/owaisk4/Win_backup/Speed Programming/Meta Hacker Cup 2023/Round 1/here_comes_santa_claus_input.txt", "r", stdin);
    freopen("/home/owaisk4/Win_backup/Speed Programming/Meta Hacker Cup 2023/Round 1/output.txt", "w", stdout);

    int T;
    cin >> T;
    int c = 1;
    while (T--) {
        int N;
        cin >> N;
        vector<int> X(N);
        for (int i = 0; i < N; i++) {
            cin >> X[i];
        }
        sort(all(X));
        if (N != 5) {
            double a = (X[0] + X[1]) / 2.0;
            double b = (X[N - 1] + X[N - 2]) / 2.0;
            double answer = b - a;
            cout << "Case #" << c++ << ": " << answer;
        } else {
            double a1 = (X[0] + X[1]) / 2.0;
            double a2 = (X[0] + X[2]) / 2.0;
            // double a2 = (X[0] + X[1] + X[2]) / 3.0;
            double b1 = (X[N - 1] + X[N - 2]) / 2.0;
            double b2 = (X[N - 1] + X[N - 3]) / 2.0;
            // double b2 = (X[N - 1] + X[N - 2] + X[N - 3]) / 3.0;
            double answer = max(b1 - a2, b2 - a1);
            cout << "Case #" << c++ << ": " << fixed << setprecision(10) << answer;
        }
        // if (T > 0) {
        cout << "\n";
        // }
        // cout << answer << "\n";
    }

    return 0;
}
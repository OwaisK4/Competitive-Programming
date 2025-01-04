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
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int minimum = min(min(a, b), c);
        if (a % minimum || b % minimum || c % minimum) {
            cout << "NO\n";
            continue;
        }
        int answer = 0;
        if (a != minimum)
            answer += ((a / minimum) - 1);
        if (b != minimum)
            answer += ((b / minimum) - 1);
        if (c != minimum)
            answer += ((c / minimum) - 1);

        if (answer <= 3) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
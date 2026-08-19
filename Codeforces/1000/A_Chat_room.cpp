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
    string s;
    cin >> s;

    string test = "hello";
    int start = 0, end = 0;
    while (!test.empty() && (end = s.find(test[0], start)) != s.npos) {
        start = end + 1;
        // cout << s[end] << " ";
        test.erase(test.begin());
    }
    if (test.empty()) {
        cout << "\nYES";
    } else {
        cout << "\nNO";
    }

    return 0;
}
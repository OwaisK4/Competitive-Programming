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
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            cout << 0;
        } else {
            if (s[i + 1] == '.') {
                cout << 1;
            } else {
                cout << 2;
            }
            i++;
        }
    }

    return 0;
}
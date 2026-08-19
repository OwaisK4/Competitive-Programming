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
    int upper = 0, lower = 0;
    for (auto it : s) {
        if (it >= 'a' && it <= 'z')
            lower++;
        else
            upper++;
    }
    if (upper > lower) {
        transform(all(s), s.begin(), ::toupper);
    } else {
        transform(all(s), s.begin(), ::tolower);
    }
    cout << s;

    return 0;
}
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
void print(T array) {
    for (auto it = begin(array); it != end(array); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}

bool perfect(int x) {
    int s = sqrt(x);
    if (s * s == x) {
        return true;
    } else {
        return false;
    }
}

bool dist(int x1, int x2, int y1, int y2) {
    int answer = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    int s = sqrt(answer);
    if (s * s == answer) {
        return true;
    } else {
        return false;
    }
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            cout << 0 << "\n";
            continue;
        }
        if (dist(x, 0, y, 0)) {
            cout << 1 << "\n";
            continue;
        } else {
            cout << 2 << "\n";
            continue;
        }

        // if (perfect(x) || perfect(y)) {
        //     cout << 2 << "\n";
        // } else {
        //     cout << 3 << "\n";
        // }
    }

    return 0;
}
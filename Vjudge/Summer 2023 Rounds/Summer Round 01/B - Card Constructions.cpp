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

int f(int h) {
    if (h == 1) {
        return 2;
    } else {
        int answer = f(h - 1) + h * f(1) + h - 1;
        return answer;
    }
}

signed main() {
    fastio;
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }
        int pyramid = 2;
        int mul_3 = 0;
        int counter = 0;
        while (n >= 2) {
            int next = pyramid + 5 + (3 * mul_3++);
            if (next <= n) {
                pyramid = next;
            } else {
                n -= pyramid;
                counter++;
                pyramid = 2;
                mul_3 = 0;
            }
        }
        cout << counter << "\n";
    }

    return 0;
}
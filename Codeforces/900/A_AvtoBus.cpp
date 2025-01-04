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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n < 4) {
            cout << -1 << "\n";
            continue;
        }
        int max_buses = -1;
        int min_buses = -1;
        if (n % 4 == 0) {
            max_buses = n / 4;
        } else {
            int x = n;
            int y = 0;
            // while (x >= 0) {
            for (int i = 0; i < 10; i++) {
                if (x % 4 == 0 && y % 6 == 0) {
                    max_buses = (x / 4) + (y / 6);
                    break;
                }
                x--;
                y++;
            }
        }
        if (n % 6 == 0) {
            min_buses = n / 6;
        } else {
            int x = 0;
            int y = n;
            // while (y >= 0) {
            for (int i = 0; i < 10; i++) {
                if (x % 4 == 0 && y % 6 == 0) {
                    min_buses = (x / 4) + (y / 6);
                    break;
                }
                x++;
                y--;
            }
        }
        min_buses = (min_buses == -1) ? max_buses : min_buses;
        max_buses = (max_buses == -1) ? min_buses : max_buses;

        if (min_buses == -1 && max_buses == -1) {
            cout << -1 << "\n";
            continue;
        }

        cout << min_buses << " " << max_buses << "\n";
    }

    return 0;
}
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<pair<int, int>> indexes;
        for (int i = 0; i < n; i++) {
            indexes.push_back({a[i], i});
        }
        sort(all(indexes));

        int cnt = 0;
        sort(all(a));
        int value = a[0];
        for (int i = 1; i < n; i++) {
            if (value < a[i]) {
                cnt++;
                value += a[i];
            }
            while (value == a[i]) {
                value += a[i];
                i++;
                if (i >= n) {
                    break;
                }
            }
            if (i >= n || value > a[i]) {
                break;
            }
        }

        vector<int> positions;
        for (int i = cnt; i < n; i++) {
            positions.push_back(indexes[i].second + 1);
        }
        sort(all(positions));

        // cout << (n - cnt) << "\n";
        cout << positions.size() << "\n";
        print(positions);
    }

    return 0;
}
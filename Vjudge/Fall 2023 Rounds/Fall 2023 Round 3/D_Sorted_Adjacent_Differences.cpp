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

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        vector<int> array, dups, negatives;
        for (auto &[key, value] : mp) {
            if (key < 0) {
                negatives.push_back(key);
                continue;
            }
            int cnt = 0;
            if (value > 1) {
                if (value % 2 == 0) {
                    cnt = value;
                } else {
                    cnt = value - 1;
                    array.push_back(key);
                }
                for (int i = 0; i < cnt; i++) {
                    dups.push_back(key);
                }
            } else {
                array.push_back(key);
            }
        }
        // sort(all(negatives), greater<int>());
        sort(all(negatives));

        for (auto it : dups) {
            cout << it << " ";
        }
        for (auto it : array) {
            cout << it << " ";
        }
        for (auto it : negatives) {
            cout << it << " ";
        }
        cout << "\n";
    }

    return 0;
}
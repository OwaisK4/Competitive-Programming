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
        vector<int> a(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }

        // for (auto it : mp) {
        //     if (it.second == 1) {
        //         count++;
        //     }
        // }

        int count = mp.size();
        int total = mp.size();
        for (int i = 0; i < n; i++) {
            if (count) {
                count--;
            } else {
                total++;
            }
            cout << total << " ";
        }
        cout << "\n";
    }

    return 0;
}
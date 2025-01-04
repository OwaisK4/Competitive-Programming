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
        int value = a[0];
        if (count(all(a), value) == n) {
            cout << "Yes\n";
            continue;
        }
        bool flag = true;
        for (auto it : mp) {
            if (it.second > 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
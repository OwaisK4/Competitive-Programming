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
        vector<pair<int, int>> sorted;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sorted.push_back({a[i], i});
        }
        sort(sorted.rbegin(), sorted.rend());

        queue<int> q;
        for (int i = 0; i < n; i++) {
            int index = sorted[i].second;
            for (int j = index; j < n && a[j] != -1; j++) {
                q.push(a[j]);
                a[j] = -1;
            }
        }
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << "\n";
    }

    return 0;
}

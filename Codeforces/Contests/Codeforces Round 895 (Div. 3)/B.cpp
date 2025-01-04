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
        vector<pair<int, int>> ds(n); // first is d, second is s;
        for (int i = 0; i < n; i++) {
            cin >> ds[i].first >> ds[i].second;
        }
        // sort(all(ds));
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            int answer = ds[i].first;
            if (ds[i].second % 2 == 0) {
                answer += (ds[i].second / 2) - 1;
            } else {
                answer += (ds[i].second / 2);
            }
            pq.push(answer);
        }
        cout << pq.top() << "\n";
    }

    return 0;
}
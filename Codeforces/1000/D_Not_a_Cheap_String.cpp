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
        string w;
        cin >> w;
        int p;
        cin >> p;
        map<char, int> mp;
        priority_queue<int> pq;
        int sum = 0;
        for (int i = 0; i < w.size(); i++) {
            int value = w[i] - 'a' + 1;
            sum += (value);
            pq.push(value);
        }
        // cout << "sum = " << sum << "\n";
        while (sum > p && !pq.empty()) {
            sum -= pq.top();
            mp[pq.top() + 'a' - 1]++;
            pq.pop();
        }
        if (pq.empty()) {
            cout << "\n";
            continue;
        }
        for (int i = 0; i < w.size(); i++) {
            if (mp[w[i]] > 0) {
                mp[w[i]]--;
            } else {
                cout << w[i];
            }
        }
        cout << "\n";
    }

    return 0;
}
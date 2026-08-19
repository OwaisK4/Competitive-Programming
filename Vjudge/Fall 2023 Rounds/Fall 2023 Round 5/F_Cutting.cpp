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
    int n, B;
    cin >> n >> B;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> possible_cuts;
    int odds = 0, evens = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            evens++;
        } else {
            odds++;
        }
        if (odds == evens && i != n - 1) {
            possible_cuts.push_back(i);
        }
    }
    if (possible_cuts.empty()) {
        cout << 0;
        return 0;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto it : possible_cuts) {
        pq.push(abs(a[it] - a[it + 1]));
    }

    int cnt = 0;
    int sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        if (sum > B) {
            break;
        }
        cnt++;
        pq.pop();
    }
    cout << cnt;

    return 0;
}
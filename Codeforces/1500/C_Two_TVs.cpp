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
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++) {
        cin >> start[i] >> end[i];
    }
    sort(all(start));
    sort(all(end));

    int i = 0, j = 0;
    int current = 0, max_current = 0;
    while (i < n && j < n) {
        if (start[i] <= end[j]) {
            current++;
            max_current = max(max_current, current);
            i++;
        } else {
            current--;
            j++;
        }
    }
    if (max_current <= 2) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
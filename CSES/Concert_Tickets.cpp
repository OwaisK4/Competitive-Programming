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

int last_true(vector<int> &array, int low, int high, int target) {
    low--;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (array[mid] < target) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> tickets(n), customers(m);
    for (int i = 0; i < n; i++) {
        cin >> tickets[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> customers[i];
    }
    multiset<int> t(all(tickets));
    for (int i = 0; i < m; i++) {
        int c = customers[i];
        auto it = t.upper_bound(c);
        if (it != t.begin() && *(prev(it)) <= c) {
            cout << *prev(it) << "\n";
            t.erase(prev(it));
        } else {
            cout << -1 << "\n";
        }
    }

    // sort(all(tickets));
    // for (int i = 0; i < m; i++) {
    //     int c = customers[i];
    //     int index = last_true(tickets, 0, tickets.size() - 1, c);
    //     if (index == -1) {
    //         cout << -1 << "\n";
    //     } else {
    //         cout << tickets[index] << "\n";
    //     }
    // }

    return 0;
}
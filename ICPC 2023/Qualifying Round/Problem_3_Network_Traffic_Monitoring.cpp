#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

vector<int> x;
vector<int> first_order;
vector<int> second_order;

signed main() {
    fastio;
    int t;
    cin >> t;

    int threshold;
    cin >> threshold;
    while (t--) {
        int n;
        cin >> n;
        x.assign(n, 0);
        first_order.assign(n - 1, 0);
        second_order.assign(n - 2, 0);

        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        for (int i = 0; i < n - 1; i++) {
            first_order[i] = abs(x[i + 1] - x[i]);
        }
        for (int i = 0; i < n - 2; i++) {
            second_order[i] = abs(first_order[i + 1] - first_order[i]);
        }
        // print(x);
        // print(first_order);
        // print(second_order);
        for (int i = 0; i < n - 2; i++) {
            if (second_order[i] >= threshold) {
                cout << 1 << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
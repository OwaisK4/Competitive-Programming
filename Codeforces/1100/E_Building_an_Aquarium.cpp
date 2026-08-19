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

int f(int h, vector<int> &a) {
    int n = a.size();
    int x = 0;
    for (int i = 0; i < n; i++) {
        x += max(h - a[i], 0LL);
    }
    return x;
}

int bin_search(int low, int high, int x, vector<int> &a) {
    low--;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (f(mid, a) <= x) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int h = bin_search(0, 2e9, x, a);
        cout << h << "\n";
    }

    return 0;
}
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m + 1);
    for (int i = 0; i < m + 1; i++) {
        cin >> a[i];
    }

    int friends = 0;
    for (int i = 0; i < m; i++) {
        int diff = 0;
        int current = a[i];
        int fedor = a[m];
        // cout << bitset<10>(current) << " " << bitset<10>(fedor) << "\n";
        // int range = max(__lg(current), __lg(fedor));
        for (int j = 0; j <= 30; j++) {
            if ((current & (1 << j)) != (fedor & (1 << j))) {
                diff++;
            }
        }
        // cout << "range = " << range << "\n";
        // cout << "diff = " << diff << "\n";
        if (diff <= k) {
            friends++;
        }
    }
    cout << friends << "\n";

    return 0;
}
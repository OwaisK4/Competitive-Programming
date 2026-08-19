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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int segment = 0;
    int current = 0;
    int previous = 0;
    for (int i = 0; i < n; i++) {
        int k = a[i];
        while (a[i] == k && i < n) {
            i++;
            current++;
        }
        i--;
        segment = max(segment, min(current, previous));
        previous = current;
        current = 0;
    }
    cout << (segment * 2) << "\n";

    return 0;
}
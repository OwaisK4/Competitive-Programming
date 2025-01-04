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

bool is_distinct(int year) {
    int a = 0;
    while (year) {
        int digit = year % 10;
        year /= 10;
        if (a & (1 << digit)) {
            return false;
        }
        a |= (1 << digit);
    }
    return true;
}

signed main() {
    fastio;
    int n;
    cin >> n;
    n++;
    while (!is_distinct(n)) {
        n++;
    }
    cout << n;

    return 0;
}
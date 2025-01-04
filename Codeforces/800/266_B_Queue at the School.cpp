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
vector<char> line;

template <typename T>
void print(T array) {
    for (auto it = begin(array); it != end(array); it++) {
        cout << *it;
    }
    cout << "\n";
}

signed main() {
    fastio;
    int n, t;
    cin >> n >> t;
    line.assign(n, '\0');
    for (int i = 0; i < n; i++) {
        cin >> line[i];
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (line[j] == 'B' && line[j + 1] == 'G') {
                swap(line[j], line[j + 1]);
                j++;
            }
        }
    }
    print(line);

    return 0;
}
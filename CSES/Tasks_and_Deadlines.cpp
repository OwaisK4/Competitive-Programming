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
    int n;
    cin >> n;
    vector<pair<int, int>> times(n);
    for (int i = 0; i < n; i++) {
        int a, d;
        cin >> a >> d;
        times[i] = {a, d};
    }
    sort(all(times));
    int answer = 0;
    int current = 0;
    for (auto &it : times) {
        current += it.first;
        answer += it.second - current;
    }
    cout << answer;

    return 0;
}
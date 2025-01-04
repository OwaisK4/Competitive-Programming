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

vector<vector<int>> friends;
vector<bool> visited;

void dfs(int i) {
    visited[i] = true;
    for (auto it : friends[i]) {
        if (!visited[it]) {
            dfs(it);
        }
    }
}

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    friends.assign(n, vector<int>());
    visited.assign(n, false);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        friends[x].push_back(y);
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            total += c[i];
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            total += c[i];
        }
    }
    cout << total << "\n";

    return 0;
}
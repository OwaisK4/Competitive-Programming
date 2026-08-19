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
    int N, M;
    cin >> N >> M;
    vector<int> f(M);
    for (int j = 0; j < M; j++) {
        cin >> f[j];
    }
    int i = 1;
    int j = 0;
    while (i <= N) {
        if (i > f[j]) {
            j++;
        } else {
            cout << f[j] - i << "\n";
            i++;
        }
    }

    return 0;
}
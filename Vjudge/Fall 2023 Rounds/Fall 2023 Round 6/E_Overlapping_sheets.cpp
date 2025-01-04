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
    int N;
    cin >> N;
    vector<vector<int>> matrix(100, vector<int>(100, 0));
    for (int k = 0; k < N; k++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        for (int i = A; i < B; i++) {
            for (int j = C; j < D; j++) {
                matrix[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    for (auto &it : matrix) {
        cnt += count(all(it), 1);
    }
    cout << cnt;

    return 0;
}